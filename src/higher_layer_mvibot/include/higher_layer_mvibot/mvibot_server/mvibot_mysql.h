#include "mvibot_server_init.h"
// #include "map_io.hpp"
using namespace std;
using namespace sql;
class fcr_database : public rclcpp::Node{
    private:
        //mutex var
        // std::recursive_mutex mutex_common;
        //robot var
        string mvibot_seri_;
        //init pub//
        // rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr map_pub_;
        //init sub//
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr history_robot_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr battery_status_chart_sub_;
        // //init timer//
        rclcpp::TimerBase::SharedPtr database_process_timer_;
        // rclcpp::TimerBase::SharedPtr insert_data_timer_;
        // creat table
        //robot
        table_ my_robot;
        table_ robot_status;
        table_ sensor_status;
        table_ battery_status;
        table_ battery_cell_status;
        table_ motor_right_status;
        table_ motor_left_status;
        table_ input_user_status;
        table_ output_user_status;
        table_ robot_config_status;
        table_ history_robot;
        table_ pose_robot;
        table_ mission_robot;
        table_ battery_status_chart;
        //map
        table_ layer_emulator;
        table_ map;
    public:
        fcr_database(const string& node_name, const string& sub_namespace) : Node(node_name, sub_namespace){
            mvibot_seri_ = this->get_namespace();
            rclcpp::QoS qos_profile(rclcpp::KeepLast(100));
            qos_profile.best_effort();
            //connect database
            data_base_init();
            cout<<"connect database"<<endl;
            //create table if not exists
            table_init();
            cout<<"create table"<<endl;
            //get map active from database
            get_map_first();
            cout<<"get map active from database"<<endl;
            //get robot from database
            get_robots_first();
            cout<<"get robot from database"<<endl;
            auto database_process_callback = [this]()->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                //update layer map from database
                get_layer();
                cout<<"get layer map from database"<<endl;
                //update map active to database
                update_map_active();
                cout<<"update map active to database"<<endl;
                //update data robot from database
                database_process();
                cout<<"process data robot update to database"<<endl;
                // //insert history robot to database
                // insert_history_robot();
                // cout<<"insert robot history to database"<<endl;
                // //insert battery robot to database
                // insert_battery_charge_robot();
                // cout<<"insert battery charge robot to database"<<endl;

            };
            database_process_timer_ = this->create_wall_timer(100ms, database_process_callback);
            auto history_robot_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                static vector<string> string_ ;
                static string string_cmd_mysql;
                static time_t now_time;
                static tm* now_tm;
                static std::ostringstream oss;
                auto now = chrono::system_clock::now();
                // Chuyển đổi thành std::time_t
                now_time = chrono::system_clock::to_time_t(now);
                // Chuyển std::time_t thành std::tm
                now_tm = localtime(&now_time);
                oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");
                string_.resize(4,"");
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].history_robot=msg.data;
                        string_cmd_mysql="";
                        string_cmd_mysql=string_cmd_mysql+"INSERT INTO history_robot (name_seri,robot_id,";
                        for(int j=1;j<data.data1.size();j++){
                            static string_Iv2 data2;
                            data2.detect(data.data1[j],"",":","");
                            if(data2.data1[0]=="status"){
                                string_[0]=data2.data1[0];
                                string_[1]=data2.data1[1];
                            }
                            else if(data2.data1[0]=="content"){
                                string_[2]=data2.data1[0];
                                string_[3]=data2.data1[1];
                            }
                        }
                        string_cmd_mysql=string_cmd_mysql+"status,content,created_at) VALUES ('"+data.data1[0]+"',"+to_string(my_robots[i].id)+",'"+string_[1]+"','"+string_[3]+"',TIMESTAMP('"+oss.str()+"'))";
                        std::cout << string_cmd_mysql << std::endl;
                        database_execmd(string_cmd_mysql);
                        my_robots[i].history_robot ="";
                        // //insert history robot to database
                        // insert_history_robot();
                        cout<<"insert robot history to database"<<endl;
                        break;
                    }
                }
                oss.str("");
            };
            history_robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/history", qos_profile, history_robot_callback);
            auto battery_status_chart_callback = [this](std_msgs::msg::String msg)->void{
                static vector<string> string_ ;
                static string_Iv2 data;
                static string string_cmd_mysql;
                static time_t now_time;
                static tm* now_tm;
                static std::ostringstream oss;
                auto now = chrono::system_clock::now();
                // Chuyển đổi thành std::time_t
                now_time = chrono::system_clock::to_time_t(now);
                // Chuyển std::time_t thành std::tm
                now_tm = localtime(&now_time);
                oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");
                string_.resize(3,"");
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        string_cmd_mysql="";
                        string_cmd_mysql=string_cmd_mysql+"INSERT INTO battery_status_chart (name_seri,robot_id,created_at,soc) ";
                        for(int j=1;j<data.data1.size();j++){
                            static string_Iv2 data2;
                            data2.detect(data.data1[i],"",":","");
                            if(data2.data1[0]=="soc"){
                                string_[0]=data.data1[0];
                                string_[1]=data2.data1[0];
                                string_[2]=data2.data1[1];
                                break;
                            }
                        }
                        string_cmd_mysql=string_cmd_mysql+"VALUES ('"+string_[0]+"',"+to_string(my_robots[i].id)+",TIMESTAMP('"+oss.str()+"'),"+string_[2]+")";
                        std::cout << string_cmd_mysql << std::endl;
                        database_execmd(string_cmd_mysql);
                        // my_robots[i].battery_status_chart ="";
                    }
                }
                oss.str("");
            };
            battery_status_chart_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/battery_status", qos_profile, battery_status_chart_callback);
            // auto insert_data_callback = [this]()->void{
            //     std::lock_guard<std::recursive_mutex> lock(mutex_common);
            //     //insert history robot to database
            //     insert_history_robot();
            //     cout<<"insert robot history to database"<<endl;
            //     //insert battery robot to database
            //     insert_battery_charge_robot();
            //     cout<<"insert battery charge robot to database"<<endl;
            // };
            // insert_data_timer_ = this->create_wall_timer(500ms, insert_data_callback);
        }
        

        // void free_res();
        void data_base_init();
        void table_init();
        void database_process();
        void get_layer();
        void database_execmd(string cmd);
        void insert_data_robot();
        void insert_battery_charge_robot();
        void insert_history_robot();
        void get_map_first();
        void database_update();
        void database_combined();
        void get_robots_first();
        void update_map_active();
        string load_file(string name_file);
};

void table_::add_colume(string name, string type){
    table_colume.resize(table_colume.size()+1);
    table_colume[table_colume.size()-1].colume_name=name;
    table_colume[table_colume.size()-1].colume_type=type;
}
void table_::init_table_PK(){
    static int init_finish;
    init_finish=0;
    while(init_finish==0){
        try{
            cout<<"Creat table "<<table_name<<endl;
            static string cmd;
            // cmd="CREATE TABLE IF NOT EXISTS "+table_name+""+" (id int)"; //, PRIMARY KEY (name_seri)
            cmd="CREATE TABLE IF NOT EXISTS "+table_name+" ("+table_colume[0].colume_name+" INT PRIMARY KEY AUTO_INCREMENT)";
            stmt->execute(cmd);
            
            //
            for(int i=1;i<table_colume.size();i++){
                try{    
                    stmt->execute("SELECT `"+table_colume[i].colume_name+"`"+"from `"+table_name+"`");
                    stmt->getResultSet();
                }catch(sql::SQLException &e){
                    cout<<"add colume:"<<table_colume[i].colume_name<<endl;
                    stmt->execute("ALTER TABLE `"+table_name+"` ADD COLUMN `"+table_colume[i].colume_name+"` "+table_colume[i].colume_type);
                }
            }
            //
            init_finish=1;
        }catch (sql::SQLException &e) {
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            cout << "reconnect....."<<endl;
            init_finish=0;
        }
    }
}
void table_::init_table_FK(string table_FK, string colume_FK){
    static int init_finish;
    init_finish=0;
    while(init_finish==0){
        try{
            cout<<"Creat table "<<table_name<<endl;
            static string cmd;
            // cmd="CREATE TABLE IF NOT EXISTS "+table_name+""+" (id int)"; //, PRIMARY KEY (name_seri)
            cmd="CREATE TABLE IF NOT EXISTS `"+table_name+"` (id BIGINT PRIMARY KEY AUTO_INCREMENT, `"+colume_FK+"` INT, FOREIGN KEY (`"+colume_FK+"`) REFERENCES `"+table_FK+"` (`"+colume_FK+"`) ON DELETE CASCADE ON UPDATE CASCADE)";

            stmt->execute(cmd);
            
            //
            for(int i=0;i<table_colume.size();i++){
                try{    
                    stmt->execute("SELECT `"+table_colume[i].colume_name+"`"+"from `"+table_name+"`");
                    stmt->getResultSet();
                }catch(sql::SQLException &e){
                    cout<<"add colume:"<<table_colume[i].colume_name<<endl;
                    stmt->execute("ALTER TABLE `"+table_name+"` ADD COLUMN `"+table_colume[i].colume_name+"` "+table_colume[i].colume_type);//+" NOT NULL");
                }
            }
            //
            init_finish=1;
        }catch (sql::SQLException &e) {
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            cout << "reconnect....."<<endl;
            init_finish=0;
        }
    }
}

// void fcr_database::free_res(){
//     if(res!=nullptr){
//         delete res;
//         res=nullptr;
//     }
// }
void fcr_database::data_base_init(){
    // creat connect to data base
    static int init_finish;
    init_finish=0;
    while(init_finish==0){
        try{
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect(host, user, password);
            if(con->isValid()){
                cout <<"Finish connect!"<<endl;
                // creat statement
                stmt = con->createStatement();
                cout<<"Creat database"<<endl;
                stmt->execute("CREATE DATABASE IF NOT EXISTS "+db);
                cout<<"Use database"<<endl;
                stmt->execute("USE "+db);
                //
                init_finish=1;
            }
        }catch (sql::SQLException &e) {
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            cout << "reconnect....."<<endl;
            init_finish=0;
            sleep(1);
        }
        
    }
    //
}
void fcr_database::table_init(){
    my_robot.table_name="my_robot";
    my_robot.add_colume("robot_id","INT");
    my_robot.add_colume("name_seri","VARCHAR(255)");
    my_robot.add_colume("type","VARCHAR(255)");
    my_robot.init_table_PK();
    //
    robot_status.table_name="robot_status";
    robot_status.add_colume("name_seri","VARCHAR(255)");
    robot_status.add_colume("status","VARCHAR(255)");
    robot_status.add_colume("mode","VARCHAR(255)");
    robot_status.add_colume("mode_status","VARCHAR(255)");
    robot_status.add_colume("ip_robot","VARCHAR(255)");
    robot_status.add_colume("robot_type_connect","VARCHAR(255)");
    robot_status.init_table_FK("my_robot","robot_id");
    // robot_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    sensor_status.table_name="sensor_status";
    sensor_status.add_colume("name_seri","VARCHAR(255)");
    sensor_status.add_colume("uart","INT");
    sensor_status.add_colume("radar1","INT");
    sensor_status.add_colume("radar2","INT");
    sensor_status.add_colume("camera1","INT");
    sensor_status.add_colume("camera2","INT");
    sensor_status.add_colume("battery","INT");
    sensor_status.init_table_FK("my_robot","robot_id");
    // sensor_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    battery_status.table_name="battery_status";
    battery_status.add_colume("name_seri","VARCHAR(255)");
    battery_status.add_colume("soc","INT");
    battery_status.add_colume("vol","FLOAT(4,2)");
    battery_status.add_colume("cycle","INT");
    battery_status.add_colume("capacity_now","FLOAT(6,3)");
    battery_status.add_colume("capacity_max","FLOAT(6,3)");    
    battery_status.add_colume("charge","INT");    
    battery_status.add_colume("current","FLOAT(5,2)");    
    battery_status.add_colume("num_cell","INT");    
    battery_status.add_colume("temperature","FLOAT(3,1)");
    battery_status.init_table_FK("my_robot","robot_id");   
    // battery_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    battery_cell_status.table_name="battery_cell_status";
    battery_cell_status.add_colume("name_seri","VARCHAR(255)");
    for(int i=0;i<8;i++){
    	battery_cell_status.add_colume("cell"+to_string(i+1),"FLOAT(2,1)");
    }
    battery_cell_status.init_table_FK("my_robot","robot_id");
    // battery_cell_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    motor_right_status.table_name="motor_right_status";
    motor_right_status.add_colume("name_seri","VARCHAR(255)");
    motor_right_status.add_colume("live","INT");
    motor_right_status.add_colume("error","INT");
    motor_right_status.add_colume("enable","INT");
    motor_right_status.add_colume("brake","INT");
    motor_right_status.init_table_FK("my_robot","robot_id");
    // motor_right_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    motor_left_status.table_name="motor_left_status";
    motor_left_status.add_colume("name_seri","VARCHAR(255)");
    motor_left_status.add_colume("live","INT");
    motor_left_status.add_colume("error","INT");
    motor_left_status.add_colume("enable","INT");
    motor_left_status.add_colume("brake","INT");
    motor_left_status.init_table_FK("my_robot","robot_id");
    // motor_left_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    input_user_status.table_name="input_user_status";
    input_user_status.add_colume("name_seri","VARCHAR(255)");
    for(int i=0;i<30;i++){
    	input_user_status.add_colume("in"+to_string(i),"INT");
    }
    input_user_status.init_table_FK("my_robot","robot_id");
    // motor_right_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    output_user_status.table_name="output_user_status";
    output_user_status.add_colume("name_seri","VARCHAR(255)");
    for(int i=0;i<30;i++){
    	output_user_status.add_colume("out"+to_string(i),"INT");
    }
    output_user_status.init_table_FK("my_robot","robot_id");
    // motor_right_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    robot_config_status.table_name="robot_config_status";
    robot_config_status.add_colume("name_seri","VARCHAR(255)");   
    robot_config_status.add_colume("robot_R","VARCHAR(255)");     
    robot_config_status.add_colume("robot_L","VARCHAR(255)");         
    robot_config_status.add_colume("robot_gear","VARCHAR(255)");     
    robot_config_status.add_colume("robot_ax","VARCHAR(255)");         
    robot_config_status.add_colume("robot_aw","VARCHAR(255)");     
    robot_config_status.add_colume("robot_vmax","VARCHAR(255)");         
    robot_config_status.add_colume("robot_wmax","VARCHAR(255)");     
    robot_config_status.add_colume("robot_volume","VARCHAR(255)");         
    robot_config_status.add_colume("robot_low_battery","VARCHAR(255)");     
    robot_config_status.add_colume("robot_type_connect","VARCHAR(255)");  
    robot_config_status.add_colume("serial_camera1","VARCHAR(255)");     
    robot_config_status.add_colume("serial_camera2","VARCHAR(255)");      
    robot_config_status.add_colume("lan_type","VARCHAR(255)");     
    robot_config_status.add_colume("lan_ipv4","VARCHAR(255)");         
    robot_config_status.add_colume("lan_ipv4_gateway","VARCHAR(255)");     
    robot_config_status.add_colume("lan_ipv4_dns","VARCHAR(255)");      
    robot_config_status.add_colume("wifi_type","VARCHAR(255)");     
    robot_config_status.add_colume("wifi_ssid","VARCHAR(255)");         
    robot_config_status.add_colume("wifi_password","VARCHAR(255)");     
    robot_config_status.add_colume("wifi_ipv4","VARCHAR(255)");   
    robot_config_status.add_colume("wifi_ipv4_gateway","VARCHAR(255)");     
    robot_config_status.add_colume("wifi_ipv4_dns","VARCHAR(255)");   
    robot_config_status.add_colume("mode","VARCHAR(255)");              
    robot_config_status.add_colume("is_master","VARCHAR(255)");     
    robot_config_status.add_colume("ip_robot","VARCHAR(255)");
    robot_config_status.init_table_FK("my_robot","robot_id");
    // robot_config_status.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    history_robot.table_name="history_robot";
    history_robot.add_colume("name_seri","VARCHAR(255)");
    history_robot.add_colume("status","VARCHAR(255)");
    history_robot.add_colume("content","LONGTEXT");
    history_robot.add_colume("created_at","TIMESTAMP");
    history_robot.init_table_FK("my_robot","robot_id");
    // history_robot.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    pose_robot.table_name="pose_robot";
    pose_robot.add_colume("name_seri","VARCHAR(255)");
    pose_robot.add_colume("x","FLOAT(7,4)");
    pose_robot.add_colume("y","FLOAT(7,4)");
    pose_robot.add_colume("thz","FLOAT(7,4)");
    pose_robot.add_colume("thw","FLOAT(7,4)");
    pose_robot.init_table_FK("my_robot","robot_id");
    //
    battery_status_chart.table_name="battery_status_chart";
    battery_status_chart.add_colume("name_seri","VARCHAR(255)");
    battery_status_chart.add_colume("created_at","TIMESTAMP");
    battery_status_chart.add_colume("soc","INT");
    battery_status_chart.init_table_FK("my_robot","robot_id");
    // battery_status_chart.init_table_FK(my_robot.table_colume[0].colume_name,my_robot.table_name);
    //
    map.table_name="map";
    map.add_colume("map_id","INT");
    map.add_colume("name_map","VARCHAR(255)");
    map.add_colume("status","INT");
    map.init_table_PK();
    //
    layer_emulator.table_name="layer_emulator";
    layer_emulator.add_colume("name_map","varchar(255)");   
    layer_emulator.add_colume("name_layer","varchar(255)");     
    layer_emulator.add_colume("type_layer","varchar(255)");         
    layer_emulator.add_colume("height","float(15,3)");         
    layer_emulator.add_colume("width","float(15,3)");   
    layer_emulator.add_colume("xo","float(15,3)");   
    layer_emulator.add_colume("yo","float(15,3)");   
    layer_emulator.add_colume("yawo","float(15,3)");   
    layer_emulator.init_table_FK("map","map_id");
    
}
void fcr_database::database_process(){
    std::lock_guard<std::recursive_mutex> lock(mutex_robot);
    for(int i=0;i<my_robots.size();i++){
        // update new robot into database
        if(my_robots[i].update_database==0){                                     //chua ton tai robot
            cout<<"Start Add new robot:"<<my_robots[i].name_seri<<endl;
            static vector<string> data;
            data=my_robots[i].cmd_insert_database();     //insert robot into database
            for(int j=0;j<data.size();j++){
                cout<<data[j]<<endl;
                try{
                    stmt->execute(data[j]);                 
                }catch (sql::SQLException &e) {
                    cout << "# ERR: " << e.what();
                    cout << " (MySQL error code: " << e.getErrorCode();
                    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                }
            }
            my_robots[i].update_database=1;
        }else{                                                                //Da ton tai robot
            my_robots[i].time_out=my_robots[i].time_out+(float)ts_my_robots;  //Kiem tra timeout robot
            if(my_robots[i].time_out>=10) my_robots[i].time_out=10.0;
            cout<<my_robots[i].name_seri<<"|"<<my_robots[i].time_out<<endl;
            //
            if(my_robots[i].time_out>=5) my_robots[i].update_status_robot(0);  //update status robot into database
            else my_robots[i].update_status_robot(1);
            //
            my_robots[i].cmd_update_database();                                //update database
        }
    }
}
void fcr_database::database_execmd(string cmd){
    try{
        stmt->execute(cmd);
    }catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void fcr_database::get_layer(){
    std::lock_guard<std::recursive_mutex> lock(mutext_layer_map);
    for(int i=0;i<my_layers.size();i++){
        my_layers[i].is_have=0;
    }
    try{
        free_res();
        res=stmt->executeQuery("SELECT * from `layer_emulator`");
        while (res->next()) {
            if(res->getString("name_map") == name_map_active){
                static int is_have;
                is_have = 0;
                static string name_layer;
                name_layer=res->getString("name_layer");
                for(int i=0;i<my_layers.size();i++){
                    if(name_layer == my_layers[i].name_layer){
                        is_have=1;
                        my_layers[i].is_have=1;
                    }
                }
                if(is_have==0){
                        cout<<"insert_layer:"<<endl;
                        my_layers.resize(my_layers.size()+1);
                        my_layers[my_layers.size()-1].name_map=res->getString("name_map");
                        my_layers[my_layers.size()-1].name_layer=res->getString("name_layer");
                        my_layers[my_layers.size()-1].type_layer=res->getString("type_layer");
                        my_layers[my_layers.size()-1].heigth=atof(res->getString("height").c_str());
                        my_layers[my_layers.size()-1].width=atof(res->getString("width").c_str());
                        my_layers[my_layers.size()-1].xo=atof(res->getString("xo").c_str());
                        my_layers[my_layers.size()-1].yo=atof(res->getString("yo").c_str());
                        my_layers[my_layers.size()-1].yawo=atof(res->getString("yawo").c_str());
                        my_layers[my_layers.size()-1].is_have=1;
                }
            }
        }
    }catch(sql::SQLException &e){
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void fcr_database::database_update(){
    
}
void fcr_database::database_combined(){

}

void fcr_database::insert_battery_charge_robot(){
    static vector<string> string_ ;
    static string_Iv2 data;
    static string string_cmd_mysql;
    static time_t now_time;
    static tm* now_tm;
    static std::ostringstream oss;
    auto now = chrono::system_clock::now();
    // Chuyển đổi thành std::time_t
    now_time = chrono::system_clock::to_time_t(now);
    // Chuyển std::time_t thành std::tm
    now_tm = localtime(&now_time);
    oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");
    string_.resize(3,"");
    //
    std::lock_guard<std::recursive_mutex> lock(mutex_robot);
    for(int i=0;i<my_robots.size();i++){
        if(my_robots[i].battery_status_chart != ""){
            data.detect(my_robots[i].battery_status_chart,"","|","");
            string_cmd_mysql="";
            string_cmd_mysql=string_cmd_mysql+"INSERT INTO battery_status_chart (name_seri,robot_id,created_at, ";
            for(int j=1;j<data.data1.size();j++){
                static string_Iv2 data2;
                data2.detect(data.data1[j],"",":","");
                if(data2.data1[0]=="soc"){
                    string_[0]=data.data1[0];
                    string_[1]=data2.data1[0];
                    string_[2]=data2.data1[1];
                }
            }
            string_cmd_mysql=string_cmd_mysql+string_[1]+") VALUES ('"+string_[0]+"',"+to_string(my_robots[i].id)+",TIMESTAMP('"+oss.str()+"'),"+string_[2]+")";
            std::cout << string_cmd_mysql << std::endl;
            database_execmd(string_cmd_mysql);
            my_robots[i].battery_status_chart ="";
        }
    }
    oss.str("");
}
void fcr_database::insert_history_robot(){
    static vector<string> string_ ;
    static string_Iv2 data;
    static string string_cmd_mysql;
    static time_t now_time;
    static tm* now_tm;
    static std::ostringstream oss;
    auto now = chrono::system_clock::now();
    // Chuyển đổi thành std::time_t
    now_time = chrono::system_clock::to_time_t(now);
    // Chuyển std::time_t thành std::tm
    now_tm = localtime(&now_time);
    oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");
    string_.resize(4,"");
    //
    std::lock_guard<std::recursive_mutex> lock(mutex_robot);
    for(int i=0;i<my_robots.size();i++){
        if(my_robots[i].history_robot != ""){
            cout<<"History: "<<my_robots[i].history_robot<<endl;
            data.detect(my_robots[i].history_robot,"","|","");
            string_cmd_mysql="";
            string_cmd_mysql=string_cmd_mysql+"INSERT INTO history_robot (name_seri,robot_id,";
            for(int j=1;j<data.data1.size();j++){
                static string_Iv2 data2;
                data2.detect(data.data1[j],"",":","");
                if(data2.data1[0]=="status"){
                    string_[0]=data2.data1[0];
                    string_[1]=data2.data1[1];
                } 
                else if(data2.data1[0]=="content"){
                    string_[2]=data2.data1[0];
                    string_[3]=data2.data1[1];
                }
            }
            string_cmd_mysql=string_cmd_mysql+string_[0]+",content,created_at"+") VALUES ('"+data.data1[0]+"',"+to_string(my_robots[i].id)+",'"+string_[1]+"','"+string_[3]+"',TIMESTAMP('"+oss.str()+"'))";
            std::cout << string_cmd_mysql << std::endl;
            database_execmd(string_cmd_mysql);
            my_robots[i].history_robot ="";
        }
    }
    oss.str("");
}
void fcr_database::get_robots_first(){
    //
    std::lock_guard<std::recursive_mutex> lock(mutex_robot);
    my_robots.resize(0);
    //
    try{
        //giai phong bieen res
        free_res();
        res=stmt->executeQuery("SELECT * from `my_robot`");
        while (res->next()) {
            cout<<res->getString("name_seri")<<endl;
            my_robots.resize(my_robots.size()+1);
            my_robots[my_robots.size()-1].name_seri=res->getString("name_seri");
            my_robots[my_robots.size()-1].type=res->getString("type");
            my_robots[my_robots.size()-1].update_database=1;
            my_robots[my_robots.size()-1].id=res->getInt("robot_id");
            // my_robots[my_robots.size()-1].id=my_robots.size()-1;
            // //UPDATE SAU//
            // my_robots[my_robots.size()-1].node= new node_v2_3;
            // my_robots[my_robots.size()-1].node->name_seri=my_robots[my_robots.size()-1].name_seri;   
            // my_robots[my_robots.size()-1].node->init();
        }
        //UPDATE SAU//
        // // get mission backup
        // free_res();
        // res=stmt->executeQuery("SELECT * from `my_robot_backup_mission`");
        // while (res->next()) {
        //     for(int i=0;i<my_robots.size();i++){
        //         if(res->getString("name_seri")==my_robots[i].name_seri){
        //             my_robots[i].node->mission_normal=res->getString("mission_normal_backup");
        //             break;
        //         }
        //     }
        // }
    
    }catch(sql::SQLException &e){
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void fcr_database::get_map_first(){
    std::lock_guard<std::recursive_mutex> lock(mutex_common);
    static string cmd;
    try{
        free_res();
        res=stmt->executeQuery("SELECT * from `map`");
        while(res->next()){
            if(res->getInt("status")==1){
                name_map_active = res->getString("name_map");
                break;
            }
        }
    }
    catch(sql::SQLException &e){
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    if(name_map_active==""){
        name_map_active=load_file(package_path+"config/map");
    }
}
void fcr_database::update_map_active(){
    std::lock_guard<std::recursive_mutex> lock(mutex_common);
    static string cmd;
    if(update_map_database == 1){
        if(action_map == "save_map"){
            try{
                free_res();
                res = stmt->executeQuery("SELECT COUNT(*) AS cnt FROM `map` WHERE name_map='" + name_map + "'");
                if(res->next() && res->getInt("cnt") > 0){
                    std::cout << "name_map had" << std::endl;
                }
                else{
                    std::cout << "name_map is not" << std::endl;
                    cmd ="";
                    cmd = cmd+"INSERT INTO map (name_map,status)  VALUES('"+name_map+"',0)";
                    database_execmd(cmd);
                }
            }catch(sql::SQLException &e){
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            }
        }
        else if(action_map == "delete_map"){
            cmd ="";
            cmd = cmd+"DELETE FROM map WHERE name_map='"+name_map+"'";
            database_execmd(cmd);
        }
        else if(action_map == "active_map"){
            try{
                free_res();
                res = stmt->executeQuery("SELECT COUNT(*) AS cnt FROM `map` WHERE name_map='" + name_map_active + "'");
                if(res->next() && res->getInt("cnt") > 0){
                    std::cout << "name_map had" << std::endl;
                }
                else{
                    std::cout << "name_map is not" << std::endl;
                    cmd ="";
                    cmd = cmd+"INSERT INTO map (name_map,status)  VALUES('"+name_map_active+"',1)";
                    database_execmd(cmd);
                }
                cmd ="";
                cmd = cmd+"UPDATE map SET status=1 WHERE name_map='"+name_map_active+"'";
                database_execmd(cmd);
                cmd ="";
                cmd = cmd+"UPDATE map SET status=0 WHERE name_map!='"+name_map_active+"'";
                database_execmd(cmd);
            }catch(sql::SQLException &e){
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            }   
        }
    }
    update_map_database = 0;
}
string fcr_database::load_file(string name_file_path){ 
    //
    static string value_return;
    try
    {
	    std::ifstream file(name_file_path);
	    std::string str; 
	    std::string data;
        std::getline(file, str);
        value_return=str;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        value_return="-1";
    }
    return value_return;
}