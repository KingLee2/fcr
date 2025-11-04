#include "library_basic.h"
#if !defined(data_uart_define)
        // define byte send pc to stm
        #define num_byte_pc_stm 120
        #define num_byte_stm_pc 120

        #define byte_start0 0xff
        #define byte_start1 0xee
        #define byte_start2 0xdd 

        #define byte_end0 0xdd
        #define byte_end1 0xee
        #define byte_end2 0xff

        uint8_t byte_uart_time_out=0xcc;

        // frame byte pc to stm
        // motor1
        #define motor1_enable       3
        #define motor1_stop         4
        #define motor1_cw_cww       5
        #define motor1_set_speedH   6
        #define motor1_set_speedL   7
        #define motor1_set_torqueH  8
        #define motor1_set_torqueL  9
        #define motor1_reset_error  10
        #define motor1_break        11
        // motor2 
        #define motor2_enable       18
        #define motor2_stop         19
        #define motor2_cw_cww       20
        #define motor2_set_speedH   21
        #define motor2_set_speedL   22
        #define motor2_set_torqueH  23
        #define motor2_set_torqueL  24
        #define motor2_reset_error  25
        #define motor2_break        26
        // IO system
        #define robot_shutdow       33
        #define robot_led_left      35
        #define robot_led_right     36
        #define robot_led_back      37
        #define robot_color_red     38
        #define robot_color_green   39
        #define robot_color_blue    40
        #define robot_led_front     41
        // // liff options mvp
        // #define robot_liff_pwm      42
        // #define robot_liff_cylinder 43
        // // hook options mvp
        // #define robot_hook_         44
        // #define robot_hook_cylinder 45
        // #define robot_hook_dir      46
        // charge battery
        #define battery_big_charge      47
        // #define battery_small_charge    48
        // IO user
        #define num_out_put_user    12
        #define robot_io_user_out0  57
        #define robot_io_user_out1  58
        #define robot_io_user_out2  59
        #define robot_io_user_out3  60
        #define robot_io_user_out4  61
        #define robot_io_user_out5  62
        #define robot_io_user_out6  63
        #define robot_io_user_out7  64
        #define robot_io_user_out8  65
        #define robot_io_user_out9  66
        #define robot_io_user_out10 67
        #define robot_io_user_out11 68
        //

        // #define control_lift_power  90
        // #define control_lift_mode   91
        #define cylinder_brush_power_pc_to_stm 98
        #define cylinder_brush_control_pc_to_stm 99
        #define cylinder_suction_power_pc_to_stm 103
        #define cylinder_suction_control_pc_to_stm 104
        #define brush_state_pc_to_stm 108
        #define suction_state_pc_to_stm 109
        #define valve_state_pc_to_stm 110
        #define charge_control_pc_to_stm 111
        // stm -> pc
        #define motor1_enable_re	3
        #define motor1_brake_re		4
        #define motor1_status_re	5
        #define motor1_error_re		6
        #define motor1_speed_H_re	7
        #define motor1_speed_L_re	8
        #define motor1_torque_H_re	9
        #define motor1_torque_L_re	10
        #define motor1_ccw_re		11
        //
        #define value_sensor1       14
        #define value_sensor2		15

        #define motor2_enable_re	18
        #define motor2_brake_re		19
        #define motor2_status_re	20
        #define motor2_error_re		21
        #define motor2_speed_H_re	22
        #define motor2_speed_L_re	23
        #define motor2_torque_H_re	24
        #define motor2_torque_L_re	25
        #define motor2_ccw_re		26
        // system
        #define button1_re       33
        #define button2_re       34
        #define button3_re       35
        //water level
        #define dirty_water_level_re 36
        #define clean_water_level_re 37
        //
        #define other_action                38
        // // robot mode
        // #define mode_re       	 36
        // #define mode_switch_hook 37
        // // robot options
        // #define robot_hook_encoder_re 	40
        // battery
        #define battery_vol_H_re		50
        #define battery_vol_L_re		51
        #define battery_current_H_re	52
        #define battery_current_L_re	53
        #define battery_mah_now_H_re	54
        #define battery_mah_now_L_re	55
        #define battery_mah_max_H_re	56
        #define battery_mah_max_L_re	57
        #define battery_cycle_charing_H_re 	58
        #define battery_cycle_charing_L_re	59
        #define battery_guard_H_re			60
        #define battery_guard_L_re			61
        #define battery_soc_re				62
        #define battery_num_cell_re			63
        #define battery_temperature1_re		64
        #define battery_temperature2_re		65
        #define battery_vol_cell1_re		66
        #define battery_vol_cell2_re		67
        #define battery_vol_cell3_re		68
        #define battery_vol_cell4_re		69
        #define battery_vol_cell5_re		70
        #define battery_vol_cell6_re		71
        #define battery_vol_cell7_re		72
        #define battery_vol_cell8_re		73
        // io
        #define num_in_put_user             12
        #define io1_re                      74
        #define io2_re                      75
        #define io3_re                      76
        #define io4_re                      77
        #define io5_re                      78
        #define io6_re                      79
        #define io7_re                      80
        #define io8_re                      81
        #define io9_re                      82
        #define io10_re                     83
        #define io11_re                     84
        #define io12_re                     85
        //out
        // #define num_out_put_user            12
        // #define out1_re                     86
        // #define out2_re                     87
        // #define out3_re                     88
        // #define out4_re                     89
        // #define out5_re                     90
        // #define out6_re                     91
        // #define out7_re                     92
        // #define out8_re                     93
        // #define out9_re                     94
        // #define out10_re                    95
        // #define out11_re                    96
        // #define out12_re                    97

        //
        // #define sbattery_vol_H_re		86
        // #define sbattery_vol_L_re		87
        // #define sbattery_current_H_re	88
        // #define sbattery_current_L_re	89
        // #define sbattery_mah_now_H_re	90
        // #define sbattery_mah_now_L_re	91
        // #define sbattery_mah_max_H_re	92
        // #define sbattery_mah_max_L_re	93
        // #define sbattery_soc_re			94
        // #define sbattery_num_cell_re	95
        // #define sbattery_temperature0_re		96
        // #define sbattery_temperature1_re		97

        //lift
        // #define num_cylinder    4
        // //cylinder 1
        // #define state_cylinder1 98
        // #define high_value_c1 	99
        // #define low_value_c1	100

        // //cylinder 2
        // #define state_cylinder2 101
        // #define high_value_c2 	102
        // #define low_value_c2	103

        // //cylinder 3
        // #define state_cylinder3 104
        // #define high_value_c3 	105
        // #define low_value_c3	106

        // //cylinder 4
        // #define state_cylinder4 107
        // #define high_value_c4 	108
        // #define low_value_c4	109
        //cylinder
        #define cylinder_brush_power_re 98
        #define cylinder_brush_control_re 99
        #define cylinder_brush_high_value_re 100
        #define cylinder_brush_low_value_re 101
        #define cylinder_brush_state_re 102
        #define cylinder_suction_power_re 103
        #define cylinder_suction_control_re 104
        #define cylinder_suction_high_value_re 105
        #define cylinder_suction_low_value_re 106
        #define cylinder_suction_state_re 107
        //brush
        #define brush_state_re 108
        //brush
        #define suction_state_re 109
        //brush
        #define valve_state_re 110
	//charge
	#define charge_state_re 111
        //temperature microcontroller
        // #define temperature_microcontroller 110
        // #define state_control_cylinder		111
        // #define state_power_tool_lift 		112
        //
        #define version_software            113

        //
    #define data_uart_define 1
#endif
