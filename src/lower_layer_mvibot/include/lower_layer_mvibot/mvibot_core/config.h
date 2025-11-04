#include"mvibot_core_init.h"
#include"../common/stof.h"
#include"../common/exec.h"
using namespace std;
//
// extern string robot_config_string;
extern string mvibot_seri;
extern float R,L,ax,aw,gear,v_max,w_max,volume;
extern string define_path;
class config : public rclcpp::Node{
    private:
        //declare pub//
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_config_pub_;
        //declare timer//
        rclcpp::TimerBase::SharedPtr robot_timer_;
        string robot_config_string;

    public:
        config(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            //load file config robot//
            robot_load_config();
            //init pub//
            robot_pub_ = this->create_publisher<std_msgs::msg::String>("robot",1);
            robot_status_pub_ = this->create_publisher<std_msgs::msg::String>("robot_status",1);
            robot_config_pub_ = this->create_publisher<std_msgs::msg::String>("config_robot",1);
            //init timer//
            auto robot_timer_callback = [this]()->void{
                std::lock_guard<std::mutex> lock(mutex_common);
                pub_robot();
                pub_robot_config();
                pub_information_robot();
            };
            robot_timer_ = this->create_wall_timer(1000ms, robot_timer_callback);
            // robot_timer_ = this->create_wall_timer(1000ms, robot_timer_callback, mutuallyExclusive_cbg);
        }
        string load_file(string name_file);
        void robot_load_config();
        void pub_robot_config();
        void pub_robot();
        void pub_information_robot();
};
string config::load_file(string name_file){
    //
    static string value_return;
    try
    {
	    std::ifstream file(define_path+"config/"+name_file);
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
void config::robot_load_config(){
    static string config;
    static string my_port;
    // //
    // robot_config_string=mvibot_seri+"|";
    config=load_file("name_seri");
    if(config!="-1"){
        mvibot_seri = config;
        robot_config_string=mvibot_seri+"|";
    }
    // robot config 
    config=load_file("robot_R");
    if(config!="-1") R=stof_f(config);
    if(config!="-1") robot_config_string+="robot_R:"+config+"|";
    //
    config=load_file("robot_L");
    if(config!="-1") L=stof_f(config);
    if(config!="-1") robot_config_string+="robot_L:"+config+"|";
    //
    config=load_file("robot_gear");
    if(config!="-1") gear=stof_f(config);
    if(config!="-1") robot_config_string+="robot_gear:"+config+"|";
    //
    config=load_file("robot_ax");
    if(config!="-1") ax=stof_f(config);
    if(config!="-1") robot_config_string+="robot_ax:"+config+"|";
    //
    config=load_file("robot_aw");
    if(config!="-1") aw=stof_f(config);
    if(config!="-1") robot_config_string+="robot_aw:"+config+"|";
    //
    config=load_file("robot_vmax");
    if(config!="-1") v_max=stof_f(config);
    if(config!="-1") robot_config_string+="robot_vmax:"+config+"|";
    //
    config=load_file("robot_wmax");
    if(config!="-1") w_max=stof_f(config);
    if(config!="-1") robot_config_string+="robot_wmax:"+config+"|";
    //
    config=load_file("robot_volume");
    if(config!="-1") volume=stof_f(config);
    if(config!="-1") robot_config_string+="robot_volume:"+config+"|";
    //
    config=load_file("robot_low_battery");
    if(config!="-1") robot_config_string+="robot_low_battery:"+config+"|";
    //
    config=load_file("robot_type_connect");
    if(config!="-1") {
        robot_config_string+="robot_type_connect:"+config+"|";
        if(config=="lan") my_port=load_file("lan_port");
        if(config=="wifi") my_port=load_file("wifi_port");
    }
    // camera seri config
    config=load_file("serial_camera1");
    if(config!="-1") robot_config_string+="serial_camera1:"+config+"|";
    //
    config=load_file("serial_camera2");
    if(config!="-1") robot_config_string+="serial_camera2:"+config+"|";  
    // lan cònfig
    config=load_file("lan_type");
    if(config!="-1") robot_config_string+="lan_type:"+config+"|";  
    config=load_file("lan_ipv4");
    if(config!="-1") robot_config_string+="lan_ipv4:"+config+"|";  
    config=load_file("lan_ipv4_gateway");
    if(config!="-1") robot_config_string+="lan_ipv4_gateway:"+config+"|";  
    config=load_file("lan_ipv4_dns");
    if(config!="-1") robot_config_string+="lan_ipv4_dns:"+config+"|";  
    // wifi cònfig
    config=load_file("wifi_type");
    if(config!="-1") robot_config_string+="wifi_type:"+config+"|";  
    config=load_file("wifi_ssid");
    if(config!="-1") robot_config_string+="wifi_ssid:"+config+"|";
    config=load_file("wifi_password");
    if(config!="-1") robot_config_string+="wifi_password:"+config+"|";
    config=load_file("wifi_ipv4");
    if(config!="-1") robot_config_string+="wifi_ipv4:"+config+"|";  
    config=load_file("wifi_ipv4_gateway");
    if(config!="-1") robot_config_string+="wifi_ipv4_gateway:"+config+"|";  
    config=load_file("wifi_ipv4_dns");
    if(config!="-1") robot_config_string+="wifi_ipv4_dns:"+config+"|";  
    //  operating config
    config=load_file("mode");
    if(config!="-1") robot_config_string+="mode:"+config+"|";  
    //
    // config=load_file("ip_robot");
    // if(config!="-1") robot_config_string+="ip_robot:"+config+"|";  
    //
    config=load_file("is_master");
    if(config!="-1") robot_config_string+="is_master:"+config+"|";  
    //
    config="ip -4 addr show "+my_port+" | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}'";
    config=exec(config.c_str());
    config.erase(std::remove(config.begin(), config.end(), '\n'), config.cend());
    robot_config_string+="ip_robot:"+config;//+"|"; 
    try{
        std::ofstream file(define_path+"config/ip_robot");
        if (!file.is_open()){
            cout<<"error open file ip_robot"<<endl;
            return;
        }
        file <<config;
        file.close();
    }catch(const std::exception& e){
        cout<<"error| update ip_robot into file:"<<e.what()<<endl;
    }
    /*
    config=load_file("ip_node");
    if(config!="-1") robot_config_string+="ip_node:"+config;//+"|";  
    //*/
}
void config::pub_robot(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|robot";
            robot_pub_->publish(msg);
    }else creat_fun=1;
}
void config::pub_information_robot(){
    static float creat_fun=0;
    static vector<string> list={"mode","robot_type_connect","ip_robot"};
    // static vector<string> list={"name","mode","ip_robot"};
    static vector<string> param;
    static std_msgs::msg::String msg;
    if(creat_fun==1){
            // robot_pub_->publish(msg);
            robot_status_pub_->publish(msg);
    }else{
        creat_fun=1;
        param.resize(list.size());
        for(int i=0;i<list.size();i++){
            try{
                    std::ifstream file(define_path+"config/"+list[i]);
                    static std::string str; 
                    static std::string data;
                    data="";
                    while (std::getline(file, str))
                    {
                        // Process str
                        data=str;
                    }
                    file.close();
                    param[i]=data;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        msg.data=mvibot_seri;
        for(int i=0;i<list.size();i++){
            msg.data=msg.data+"|";
            msg.data=msg.data+list[i]+":"+param[i];
        }
    }
}
void config::pub_robot_config(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=robot_config_string;
            robot_config_pub_->publish(msg);
    }else creat_fun=1;
}