#include "mvibot_server_init.h"
using namespace std;
extern void database_update(string table,string coloum,string data,string name_seri);
extern void database_combined(string table,string coloum,string data,string name_seri);
extern int update_battery_chart;
//
string robot_information::get_cmd_update_database(string data1_,string data2_){
    static string string_return;
    //
    static string_Iv2 data;
    static string string_cmd_mysql;
    int robot_id;
    data.detect(data2_,"","|","");
    //
    try{
        free_res();
        res=stmt->executeQuery("SELECT robot_id FROM my_robot WHERE name_seri='"+data.data1[0]+"'");
        if (res->next()) {
            robot_id = res->getInt("robot_id");
        } else {
            cout << "not robot" << endl;
        }
    }catch(sql::SQLException &e){
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    try{
        free_res();
        res = stmt->executeQuery("SELECT COUNT(*) AS cnt FROM `"+data1_+"` WHERE name_seri='" + data.data1[0] + "'");
        if(res->next() && res->getInt("cnt") > 0){
            std::cout << data1_<<" had" << std::endl;
        }
        else{
            std::cout << data1_<<" is not" << std::endl;
            string cmd;
            cmd ="";
            cmd = cmd+"INSERT INTO `"+data1_+"` (name_seri,robot_id) VALUES('"+data.data1[0]+"',"+to_string(robot_id)+")";
            send_cmd_to_msyql(cmd);
        }
    }catch(sql::SQLException &e){
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    //
    string_cmd_mysql="";
    string_cmd_mysql=string_cmd_mysql+"UPDATE "+data1_+" SET ";
    for(int i=1;i<data.data1.size()-1;i++){
        static string_Iv2 data2;
        data2.detect(data.data1[i],"",":","");
        if(data2.data1[0]!="")
        string_cmd_mysql=string_cmd_mysql+data2.data1[0]+"="+"'"+data2.data1[1]+"', ";
    }
    static string_Iv2 data2;
    data2.detect(data.data1[data.data1.size()-1],"",":","");
    if(data2.data1[0]!="")
    string_cmd_mysql=string_cmd_mysql+data2.data1[0]+"="+"'"+data2.data1[1]+"' ";
    string_cmd_mysql=string_cmd_mysql+"WHERE name_seri = '"+data.data1[0]+"' ";
    string_return=string_cmd_mysql;
    cout<<"update_robot: "<<string_return<<endl;
    return string_return;
}
///get_cmd_insert_row_table
string robot_information::get_cmd_insert_row_table(string data1_,string data2_){
    static string string_return;
    static vector<string> string_ ;
    //
    static string_Iv2 data;
    static string string_cmd_mysql;
   //
    static string msg;
    static time_t now_time;
    static tm* now_tm;
    static std::ostringstream oss;
    auto now = chrono::system_clock::now();
    // Chuyển đổi thành std::time_t
    now_time = chrono::system_clock::to_time_t(now);
    // Chuyển std::time_t thành std::tm
    now_tm = localtime(&now_time);
    oss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");
    // msg = "INSERT INTO battery_status_chart (name_seri, soc, created_at) VALUES('MB24_916b','23','"+oss.str()+"')";
    // oss.str("");

   //
    string_.resize(2);
    data.detect(data2_,"","|","");
/// "INSERT INTO my_robot (name_seri,type,history,id)  VALUES('"+name_seri+"','"+type+"',"+"'',"+"'"+to_string(id)+"'"+")";

    string_cmd_mysql="";
    string_[0]="";
    string_[1]="";
    string_cmd_mysql=string_cmd_mysql+"INSERT INTO "+data1_+" (";
    for(int i=1;i<data.data1.size()-1;i++){
            static string_Iv2 data2;
            data2.detect(data.data1[i],"",":","");
            ///
            // if(data2.data1[0]!=""){
            //     string_[0]=string_[0]+", "+data2.data1[0];
            //     string_[1]=string_[1]+", "+data2.data1[1];
            // }
            if(data2.data1[0]=="soc"){
                string_[0]=string_[0]+", "+data2.data1[0];
                string_[1]=string_[1]+", "+data2.data1[1];
            }
    }
    static string_Iv2 data2;
    data2.detect(data.data1[data.data1.size()-1],"",":","");
    if(data2.data1[0]!=""){
        // string_[0]=string_[0]+", "+data2.data1[0]+", "+"created_at";
        // string_[1]=string_[1]+", "+data2.data1[1]+", "+ oss.str();
    }
    string_cmd_mysql=string_cmd_mysql+string_[0]+") VALUES ("+string_[1]+")";
    //string_return=string_cmd_mysql;
    //string_return = "INSERT INTO battery_status_chart (name_seri,soc)  VALUES('"+name_seri+"','"+type+"',"+"'',"+"'"+to_string(id)+"'"+")";
    string_return = "INSERT INTO battery_status_chart (name_seri,soc)  VALUES('MB24_916b','48')";
    return string_return;
}
std::vector<string>  robot_information::cmd_update_database(){
    static vector<string> string_return;
    //
    string_return.resize(0);
    //
    if(sensor_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("sensor_status",sensor_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        sensor_status="";
    }
    //
    if(robot_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("robot_status",robot_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        robot_status="";
    }
    //
    if(battery_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("battery_status",battery_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        battery_status="";
    }
    //
    if(battery_cell_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("battery_cell_status",battery_cell_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        battery_cell_status="";
    }
    //
    if(motor_left_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("motor_left_status",motor_left_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        motor_left_status="";
    }
    //
    if(motor_right_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("motor_right_status",motor_right_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        motor_right_status="";
    }
    //
    if(input_user_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("input_user_status",input_user_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        input_user_status="";
    }
    //
    if(output_user_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("output_user_status",output_user_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        output_user_status="";
    }
    //
    if(robot_config_status!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("robot_config_status",robot_config_status);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        robot_config_status="";
    }
    if(pose_robot!=""){
        string_return.resize(string_return.size()+1);
        string_return[string_return.size()-1]=get_cmd_update_database("pose_robot",pose_robot);
        send_cmd_to_msyql(string_return[string_return.size()-1]);
        pose_robot="";
    }
    ///
    // if(update_battery_chart==1){// & battery_status_chart!=""
    //     string_return.resize(string_return.size()+1);
    //     //string_return[string_return.size()-1]=get_cmd_insert_row_table("battery_status_chart",battery_status_chart);
    //     string_return[string_return.size()-1]="INSERT INTO battery_status_chart (name_seri,soc)  VALUES('MB24_916b','26')";
    //     send_cmd_to_msyql(string_return[string_return.size()-1]);
    //     update_battery_chart==0;
    // }
    /////update sau/////
    // if(node->update_mision==1){
    //     string_return.resize(string_return.size()+1);
    //     string_return[string_return.size()-1]="update `my_robot_backup_mission` set mission_normal_backup='"+node->mission_normal+"' where name_seri='"+name_seri+"'";
    //     send_cmd_to_msyql(string_return[string_return.size()-1]);
    //     node->update_mision=0;
    // }
    // if(node->history.size()!=0){
    //     for(int i=0;i<node->history.size();i++){
    //       database_combined("my_robot","history",node->history[i],node->name_seri);
    //     }
    //     node->history.resize(0);
    // }
    return string_return;
}
std::vector<string>  robot_information::cmd_insert_database(){
    string cmd;
    static vector<string> string_return;
    //
    string_return.resize(13);
    // string_return[0]="INSERT INTO my_robot (name_seri,type,robot_id)  VALUES('"+name_seri+"','"+type+"',"+to_string(id)+")";
    cmd="INSERT INTO my_robot (name_seri,type)  VALUES('"+name_seri+"','"+type+"')";
    send_cmd_to_msyql(cmd);
    free_res();
    res=stmt->executeQuery("SELECT robot_id FROM my_robot WHERE name_seri='"+name_seri+"'");
    if (res->next()) {
        int robot_id = res->getInt("robot_id");
        cout << "Robot ID: " << robot_id << endl;
        string_return[0]="INSERT INTO robot_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[1]="INSERT INTO sensor_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[2]="INSERT INTO battery_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[3]="INSERT INTO battery_cell_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[4]="INSERT INTO motor_left_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[5]="INSERT INTO motor_right_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[6]="INSERT INTO input_user_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[7]="INSERT INTO output_user_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[8]="INSERT INTO robot_config_status (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[9]="INSERT INTO history_robot (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[10]="INSERT INTO pose_robot (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
        string_return[11]="INSERT INTO battery_status_chart (name_seri,robot_id)  VALUES('"+name_seri+"',"+to_string(robot_id)+")";
    } else {
        cout << "not robot" << endl;
        string_return.resize(0);
    }
    return string_return;
}
void robot_information::update_status_robot(int n){
    static string cmd;
    if(n==1) cmd="update `robot_status` set status='1' where name_seri='"+name_seri+"'";
    else cmd="update `robot_status` set status='0' where name_seri='"+name_seri+"'";
    try{
        stmt->execute(cmd);
    }catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void robot_information::send_cmd_to_msyql(string cmd){
    try{
        stmt->execute(cmd);
    }catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
