#include "../common/data_uart.h"
#include "../mvibot_core/mvibot_core_init.h"
using namespace std;

// int robot_backup=0;
// // extern void send_history(string type,string data);
class socket_client_node : public rclcpp::Node{
    public:
        socket_client_node(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            while(modify_socket()==-1){
                sleep(1);
            }
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            data_tran.resize(num_byte_pc_stm);
            data_tran[0]=byte_start0;
            data_tran[1]=byte_start1;
            data_tran[2]=byte_start2;
            data_tran[data_tran.size()-3]=byte_end0;
            data_tran[data_tran.size()-2]=byte_end1;
            data_tran[data_tran.size()-1]=byte_end2;
            //init pub //
            //history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //init sub//
            //shutdown robot
            auto robot_shutdown_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                if(msg.data =="1"){
                    robot_shutdown = 1;
                    send_history("normal","Robot shutdown");
                }
                else if(msg.data == "2"){
                    robot_shutdown = 2;
                    send_history("normal","Robot restart");
                }
            };
            robot_shutdown_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot_shutdown",qos_profile,robot_shutdown_callback);
            // robot_shutdown_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot_shutdown",qos_profile,robot_shutdown_callback, sub_options);
            //init timer
            auto socket_data_timer_callback = [this]()->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_socket);
                rclcpp::Time now = this->get_clock()->now();
                if (check_time_socket.nanoseconds() > 0) {
                    rclcpp::Duration dt = now - check_time_socket;
                    RCLCPP_INFO(this->get_logger(), "data socket send/read period: %.6f s", dt.seconds());
                }
                check_time_socket = now;
                read_data_socket();
                // RCLCPP_INFO(this->get_logger(),"read data socket");
                process_data_socket();
                // RCLCPP_INFO(this->get_logger(),"process data socket");
                send_data_socket(data_tran);
                // RCLCPP_INFO(this->get_logger(),"send data socket");
            };
            socket_data_timer_ = this->create_wall_timer(50ms,socket_data_timer_callback);
            // socket_data_timer_ = this->create_wall_timer(50ms,socket_data_timer_callback, reentrant_cbg);
        }
        void send_history(string status, string info){
            static std_msgs::msg::String history_msg;
            history_msg.data = mvibot_seri+"|" + "status:"+status + "|" + "content:" + info;
            history_pub_->publish(history_msg);
        }
        void process_data_uart_read();
        void process_data_uart_write();
        void time_now(string name);
        int modify_socket();
        void process_data_socket();
        void read_data_socket();
        void send_data_socket(std::vector<uint8_t> data_tranf);
        void view_data(string name, std::vector<uint8_t> data);
    private:
        // //mutex var
        // std::recursive_mutex mutex_common;
        //declare var
        string mvibot_seri_;
        //declare pub history
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //declare sub
        //shutdown robot
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr robot_shutdown_sub_;
        //declare timer//
        rclcpp::TimerBase::SharedPtr socket_data_timer_;
        //
        std::vector<uint8_t> data_receive={};
        std::vector<uint8_t> data_tran={};
        //
        int local_motor_break, local_motor_enable;
        float local_vl_out, local_vr_out;
        float local_torqueR_set, local_torqueL_set;
        int local_motor_left_state_error, local_motor_right_state_error, local_motor_reset;
        //
        std_msgs::msg::Float32MultiArray local_output_user;
        //
        int local_battery1_charge;
        ///
        int local_charge_control_status;
        //
        float local_red, local_green, local_blue, local_led_l, local_led_r, local_led_b;
        //
        int local_brush_send_uart_status;
        int local_suction_send_uart_status;
        int local_valve_send_uart_status;
        int local_lift_brush_power_send_uart;
        int local_lift_brush_control_send_uart;
        int local_lift_suction_power_send_uart;
        int local_lift_suction_control_send_uart;
        //
        float local_robot_shutdown;
        //var check time pub
        rclcpp::Time check_time_socket;
};
void socket_client_node::view_data(string name, std::vector<uint8_t> data){
    cout<<name;
    for(size_t i=0;i<data.size();i++){
        printf("0x%x ",data[i]);
    }
    cout<<endl;
}
void socket_client_node::process_data_uart_read(){
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    if(data_receive.size()==num_byte_stm_pc){
        {
            std::lock_guard<std::mutex> lock(mutex_control);
            // read status live motor
            motor_right_state_live=(int)data_receive[motor1_status_re];
            motor_left_state_live=(int)data_receive[motor2_status_re];
            // read status enable motor
            motor_right_disable=(int)data_receive[motor1_enable_re];
            motor_left_disable=(int)data_receive[motor2_enable_re];
            // read status brake
            motor_right_break=(int)data_receive[motor1_brake_re];
            motor_left_break=(int)data_receive[motor2_brake_re];
            // read status error motor
            motor_right_state_error=(int)data_receive[motor1_error_re];
            motor_left_state_error=(int)data_receive[motor2_error_re];
            // read torque
            tr=(float)data_receive[motor1_torque_L_re]/100;
            tl=(float)data_receive[motor2_torque_L_re]/100;
            // condition for speed read
            if(motor_right_state_live==0 || (motor_right_state_live==1 && motor_right_state_error!=0)) vr=0;
            if(motor_left_state_live==0 || (motor_left_state_live==1 && motor_left_state_error!=0)) vl=0;
            //
            for(int i=0;i<num_in_put_user;i++){
                input_user.data[i]=(float)(data_receive[io1_re+i]);
            }
            input_user.data[num_in_put_user+0]=(float)(data_receive[button1_re]);
            input_user.data[num_in_put_user+1]=(float)(data_receive[button2_re]);
            input_user.data[num_in_put_user+2]=(float)(data_receive[button3_re]);
        }
        {
            std::lock_guard<std::mutex> lock(mutex_odom);
            // read speed motor right
            static float v_;
            v_=(float)data_receive[motor1_speed_H_re]*100+(float)data_receive[motor1_speed_L_re];
            v_=v_/gear*M_PI*2/60;
            vr=v_;
            if(data_receive[motor1_ccw_re]==1) vr=-vr;
            // RCLCPP_INFO(rclcpp::get_logger("Motor"), "Velocity of The Right Motor receive: %f", vr);
            // read speed motor left
            v_=(float)data_receive[motor2_speed_H_re]*100+(float)data_receive[motor2_speed_L_re];
            v_=v_/gear*M_PI*2/60;
            vl=v_;
            if(data_receive[motor2_ccw_re]==1) vl=-vl;
            // RCLCPP_INFO(rclcpp::get_logger("Motor"), "Velocity of The Left Motor receive: %f", vl);
            // if speed very small -> speed equal to zero!
            if(fabs(vl)<0.125 && vl_set==0) vl=0;
            if(fabs(vr)<0.125 && vr_set==0) vr=0;
        }
        {
            //
            std::lock_guard<std::mutex> lock(mutex_tool);
            // brush
            brush_receive_uart_status = (int)data_receive[brush_state_re];
            //suction
            suction_receive_uart_status = (int)data_receive[suction_state_re];
            //valve
            valve_receive_uart_status = (int)data_receive[valve_state_re];
            //lift
            // lift_temperature_microcontroller =(float)data_receive[temperature_microcontroller];
            //lift brush
            lift_brush_control_receive_uart = (int)data_receive[cylinder_brush_control_re];
            lift_brush_power_receive_uart = (int)data_receive[cylinder_brush_power_re];
            lift_brush_data.data=(float)(data_receive[cylinder_brush_high_value_re]*100+data_receive[cylinder_brush_low_value_re])/100;
            lift_brush_mode = (int)data_receive[cylinder_brush_state_re];
            //lift suction
            lift_suction_control_receive_uart = (int)data_receive[cylinder_suction_control_re];
            lift_suction_power_receive_uart = (int)data_receive[cylinder_suction_power_re];
            lift_suction_data.data=(float)(data_receive[cylinder_suction_high_value_re]*100+data_receive[cylinder_suction_low_value_re])/100;
            lift_suction_mode = (int)data_receive[cylinder_suction_state_re];
            //temperature
            temperature_outside = (float)(data_receive[value_sensor1]);
            temperature_electric_box = (float)(data_receive[value_sensor2]);

            //water level
            dirty_water_level = (int)data_receive[dirty_water_level_re];
            clean_water_level = (int)data_receive[clean_water_level_re];

	        //charge
            charge_receive_uart_status = (int)data_receive[charge_state_re];
            // read data batterry
            static float check_battery_time_out;
            check_battery_time_out=0;
            for(int i=battery_vol_H_re;i<=battery_vol_cell8_re;i++){
                if(data_receive[i]!=byte_uart_time_out){
                    check_battery_time_out=1;
                    break;
                }
            }
            if(check_battery_time_out==1){
                battery_live_status=1;
                //
                battery_soc=(float)(data_receive[battery_soc_re]);
                //battery_soc=((battery_soc-20)/80)*100;
                if(battery_soc<0) battery_soc=0;
                //
                battery_vol=(float)(data_receive[battery_vol_H_re]*100+data_receive[battery_vol_L_re])/100;
                battery_num_cell=(float)data_receive[battery_num_cell_re];
                battery_cycle=(float)((uint16_t)data_receive[battery_cycle_charing_H_re]<<8 | data_receive[battery_cycle_charing_L_re]);
                battery_guard=(float)((uint16_t)data_receive[battery_guard_H_re]<<8 | data_receive[battery_guard_L_re]);
                battery_mah_now=(float)((uint16_t)data_receive[battery_mah_now_H_re]<<8| data_receive[battery_mah_now_L_re]);
                battery_mah_max=(float)((uint16_t)data_receive[battery_mah_max_H_re]<<8| data_receive[battery_mah_max_L_re]);
                battery_current=(float)((int16_t)(data_receive[battery_current_H_re]<<8 | data_receive[battery_current_L_re]));
                if(battery_current>=0) battery_status_charge=1;
                else battery_status_charge=0;
                battery_temperature=(float)(data_receive[battery_temperature1_re]+data_receive[battery_temperature1_re])/2;
                //
                for(int i=0;i<8;i++){
                    battery_cell[i]=(float)data_receive[battery_vol_cell1_re+i]/10;
                }
            }else battery_live_status=0;
            //
            if(data_receive[other_action]==1) 
            {
                if(robot_shutdown!=1) send_history("normal","Robot shutdown");
                robot_shutdown=1;
            }
        }
        // if(data_receive[other_action]==2) 
        // {
        //     if(robot_backup!=1) send_history("warning","Robot backup software");
        //     robot_backup=1;
        // }
	// RCLCPP_INFO(rclcpp::get_logger("Data_receive"), "byte lift_suction: %d, byte 41: %d", (int)data_receive[cylinder_suction_control_re], (int)data_receive[41]);
	// RCLCPP_INFO(rclcpp::get_logger("Data_receive"), "byte 41: %d, byte 42: %d, byte 43: %d, byte 44: %d, byte 45: %d, byte 46: %d, byte 47: %d, byte 48: %d", (int)data_receive[41], (int)data_receive[42], (int)data_receive[43], (int)data_receive[44], (int)data_receive[45], (int)data_receive[46], (int)data_receive[47], (int)data_receive[48]);
    }
}
void socket_client_node::process_data_uart_write(){
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    {
        std::lock_guard<std::mutex> lock(mutex_control);
        local_motor_break = motor_break;
        local_motor_enable = motor_enable;
        local_motor_reset = motor_reset;
        local_vl_out = vl_out;
        local_vr_out = vr_out;
        local_torqueL_set = torqueL_set;
        local_torqueR_set = torqueR_set;
        local_motor_left_state_error = motor_left_state_error;
        local_motor_right_state_error = motor_right_state_error;
        //local_blue = blue;
        local_green = green;
        local_red = red;
        local_led_l = led_l;
        local_led_r = led_r;
        local_led_b = led_b;
        //
        local_output_user = output_user;
    }
    {
        std::lock_guard<std::mutex> lock(mutex_tool);
        local_brush_send_uart_status = brush_send_uart_status;
        local_suction_send_uart_status = suction_send_uart_status;
        local_valve_send_uart_status = valve_send_uart_status;
        local_lift_brush_power_send_uart = lift_brush_power_send_uart;
        local_lift_brush_control_send_uart = lift_brush_control_send_uart;
        local_lift_suction_power_send_uart = lift_suction_power_send_uart;
        local_lift_suction_control_send_uart = lift_suction_control_send_uart;
        ///
        local_charge_control_status = charge_control_status;
        local_battery1_charge = battery1_charge;
        //
        local_robot_shutdown = robot_shutdown;
    }
    // motor mode
    if(local_motor_break==1){         //motor_break=0: khoa thang, motor_break=1: mo khoa thang
        data_tran[motor1_enable]=(uint8_t)(local_motor_enable);
        data_tran[motor2_enable]=(uint8_t)(local_motor_enable);
        data_tran[motor1_break]=1; 
        data_tran[motor2_break]=1;
    }else{
        data_tran[motor1_enable]=0;
        data_tran[motor2_enable]=0;
        data_tran[motor1_break]=0;
        data_tran[motor2_break]=0;
    }
    // speed motor left
    if(local_vl_out>0) data_tran[motor2_cw_cww]=0;
    else data_tran[motor2_cw_cww]=1;
    data_tran[motor2_set_speedH]=(uint8_t)((fabs(local_vl_out)/(2*M_PI)*60*gear)/100);
    data_tran[motor2_set_speedL]=(uint8_t)((fabs(local_vl_out)/(2*M_PI)*60*gear)-data_tran[motor2_set_speedH]*100);
    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "Motor Left| v_set1: %f, w_set1: %f", data_tran[motor2_set_speedH], data_tran[motor2_set_speedL]);
    // speed motor right
    if(local_vr_out>0) data_tran[motor1_cw_cww]=0;
    else data_tran[motor1_cw_cww]=1;
    data_tran[motor1_set_speedH]=(uint8_t)((fabs(local_vr_out)/(2*M_PI)*60*gear)/100);
    data_tran[motor1_set_speedL]=(uint8_t)((fabs(local_vr_out)/(2*M_PI)*60*gear)-data_tran[motor1_set_speedH]*100);
    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "Motor Right| v_set1: %f, w_set1: %f", data_tran[motor2_set_speedH], data_tran[motor2_set_speedL]);
    // tourque set
    data_tran[motor1_set_torqueL]=(uint8_t)(local_torqueR_set*100);
    data_tran[motor2_set_torqueL]=(uint8_t)(local_torqueL_set*100);
    // color robot
    data_tran[robot_color_red]=(uint8_t)(local_red);
    data_tran[robot_color_green]=(uint8_t)(local_green);
    data_tran[robot_color_blue]=(uint8_t)(local_blue);
    // led robot
    data_tran[robot_led_left]=(uint8_t)(local_led_l);
    data_tran[robot_led_right]=(uint8_t)(local_led_r);
    data_tran[robot_led_back]=(uint8_t)(local_led_b);
    data_tran[robot_led_front]=0;//(uint8_t)(led_f);
    // reset error motor
    if((local_motor_left_state_error !=0 || local_motor_right_state_error !=0) && local_motor_reset==1){
        data_tran[motor1_reset_error]=1;
        data_tran[motor2_reset_error]=1;
        local_motor_reset=0;
    }else {
        data_tran[motor1_reset_error]=0;
        data_tran[motor2_reset_error]=0;
    }
    // output set
    for(int i=robot_io_user_out0;i<robot_io_user_out0+num_out_put_user;i++){
        data_tran[i]=(uint8_t)local_output_user.data[i-robot_io_user_out0];
    }
    //brush
    data_tran[brush_state_pc_to_stm] = (uint8_t)local_brush_send_uart_status;
    //suction
    data_tran[suction_state_pc_to_stm] = (uint8_t)local_suction_send_uart_status;
    //valve
    data_tran[valve_state_pc_to_stm] = (uint8_t)local_valve_send_uart_status;
    //lift brush
    data_tran[cylinder_brush_power_pc_to_stm]=(uint8_t)local_lift_brush_power_send_uart;
    data_tran[cylinder_brush_control_pc_to_stm]=(uint8_t)local_lift_brush_control_send_uart;
    //lift suction
    data_tran[cylinder_suction_power_pc_to_stm]=(uint8_t)local_lift_suction_power_send_uart;
    data_tran[cylinder_suction_control_pc_to_stm]=(uint8_t)local_lift_suction_control_send_uart;
    // battery charge
    data_tran[battery_big_charge]=(uint8_t)local_battery1_charge;
    data_tran[charge_control_pc_to_stm]=(uint8_t)local_charge_control_status;

    // data_tran[battery_small_charge]=(uint8_t)battery2_charge;
    // robot_shutdown
    data_tran[robot_shutdow]=(uint8_t)local_robot_shutdown;
}
void socket_client_node::time_now(string name){
    // lock();
        static struct timespec realtime;
        clock_gettime(CLOCK_REALTIME, &realtime);
        // cout<<name+"|Time:"<<std::fixed << std::setprecision(5)<<((long double)realtime.tv_sec+(long double)realtime.tv_nsec*1e-9)<<endl;
    // unlock();
}
int socket_client_node::modify_socket(){
    static int value_return;
    value_return = 1;
    //tao socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("\n Socket creation error \n"); 
        return -1;
    }
    //cau hinh dia chi server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    //Convert IPv4 addresses from text to binary form
    if(inet_pton(AF_INET, add, &serv_addr.sin_addr) <= 0) 
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    }
    //connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    return value_return;
}
void socket_client_node::read_data_socket(){
    static int num_byte;
    static uint8_t data_receive_socket_local[999]={};
    static int count;
    static int data_error;
    memset(data_receive_socket_local,0, sizeof(data_receive_socket_local));
    num_byte=read( sock , data_receive_socket_local, 999);
    // cout<<num_byte<<endl;
    // lock();
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    // std::lock_guard<std::mutex> lock(mutex_socket);
    data_socket_ready = 0;
    if(num_byte>0){
        data_receive.resize(num_byte);
        for(size_t j=num_byte;j>=2;j--){
            //
            count=0;
            data_error=1;
            if(data_receive_socket_local[j]==byte_end2 &&  data_receive_socket_local[j-1]==byte_end1 && data_receive_socket_local[j-2]==byte_end0){
                for(size_t k=j;k>=0;k--){
                    count++;
                    if(data_receive_socket_local[k]==byte_start0 && data_receive_socket_local[k+1]==byte_start1 && data_receive_socket_local[k+2]==byte_start2 ){
                        data_error=0;
                        data_receive.resize(count);
                        for(size_t h=k;h<=j;h++){
                            data_receive[h-k]=data_receive_socket_local[h];
                        }
                        data_socket_ready=1;
                        break;
                    }
                }
                if(data_error==0) break;
            }
        }
        // if(data_socket_ready==1) view_data("data from socket: ",data_receive);
        time_now(to_string(num_byte));
    }
    // unlock();
}
void socket_client_node::send_data_socket(std::vector<uint8_t> data_tranf){
    // lock();
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    // std::lock_guard<std::mutex> lock(mutex_socket);
    //uint8_t data_tran_socket[data_tranf.size()];
    static uint8_t data_tran_socket[num_byte_pc_stm];
    memset(data_tran_socket,0,sizeof(data_tran_socket));
    for(size_t i=0;i<data_tranf.size();i++){
        data_tran_socket[i]=data_tranf[i];
    }
    // view_data("send data to socket :",data_tranf);
    send(sock , data_tran_socket , data_tranf.size() , 0 );
    // unlock();
}
void socket_client_node::process_data_socket(){
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    // std::lock_guard<std::mutex> lock(mutex_socket);
    if(data_socket_ready==1){
        static int uart_check;
        uart_check=0;
        time_out_socket=0;
        for(size_t i=3;i<num_byte_stm_pc-3;i++){
            static uint8_t byte_check=byte_uart_time_out;
            if(data_receive[i]!=byte_check){
                uart_check=1;
                break;
            }
        }
        if(uart_check==1){
            // process to read socket <- data_recevice
            // process data pc <- stm
            uart_live=1;
            process_data_uart_read();
        }else uart_live=0;
    }else{
        time_out_socket+=(float)0.05;
        if(time_out_socket>=0.250) time_out_socket=0.250;
        if(time_out_socket>=0.250) uart_live=0;
    }
    // process data pc -> stm
    process_data_uart_write();
}
