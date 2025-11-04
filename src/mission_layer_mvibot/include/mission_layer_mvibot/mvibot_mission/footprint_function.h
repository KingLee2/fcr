#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/set_get_param.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "mission_define.h"

using namespace std;
class footprint : public set_get_param<string>{
    public:
        footprint(const string &node_name , const string &sub_namespace) : set_get_param<string>(node_name, sub_namespace){
            mvibot_seri_ = this->get_namespace();
        }
        void process_data();
        void print();
        int action(int action);
        void reset();
    private:
        string data;
        float x1;
		float y1;
		float x2;
		float y2;
        int status=0;
        string mvibot_seri_;
};
void footprint::process_data(){
    // static string_Iv2 data_return;
    // data_return.detect(data,"~","=","~");
    // for(int i=0;i<data_return.data1.size();i++){
    //     if(data_return.data1[i]=="x1")     x1=stof_f(data_return.data2[i]);
    //     if(data_return.data1[i]=="y1")     y1=stof_f(data_return.data2[i]);
    //     if(data_return.data1[i]=="x2")     x2=stof_f(data_return.data2[i]);
    //     if(data_return.data1[i]=="y2")     y2=stof_f(data_return.data2[i]);
    // }
    x1 = 0.55, x2 = -0.55, y1 = 0.35, y2 = -0.35;

}
void footprint::print(){

}
int footprint::action(int action){
    static int value_return;
    if(action==Active_){
        static string footprint_set;
        static string footprint_return;
        bool state_set_footprint, state_get_footprint;
        footprint_set="[";
        footprint_set=footprint_set+"["+to_string(x1)+","+to_string(y1)+"],";
        footprint_set=footprint_set+"["+to_string(-x1)+","+to_string(y1)+"],";
        footprint_set=footprint_set+"["+to_string(x2)+","+to_string(y2)+"],";
        footprint_set=footprint_set+"["+to_string(-x2)+","+to_string(y2)+"]]";
        // cout<<"\t \t \t \t \t footprint set:"<<footprint_set<<endl;
        // footprint_x1=x1; footprint_x2=x2; footprint_y1=y1, footprint_y2=y2;
        // value_return=Finish_;
        value_return = Finish_;
        // local costmap
        state_set_footprint = set_param(mvibot_seri_+"/local_costmap/local_costmap/set_parameters","footprint",footprint_set);
        if(state_set_footprint == true){
            state_get_footprint = get_param(mvibot_seri_+"/local_costmap/local_costmap/get_parameters","footprint", footprint_return);
            if(state_get_footprint == true) cout<<"footprint: "<<footprint_return<<endl;
        }
        if(footprint_return!=footprint_set) value_return = Active_;
        // global costmap

        state_set_footprint = set_param(mvibot_seri_+"/global_costmap/global_costmap/set_parameters","footprint",footprint_set);
        if(state_set_footprint == true){
            state_get_footprint = get_param(mvibot_seri_+"/global_costmap/global_costmap/get_parameters","footprint", footprint_return);
            if(state_get_footprint == true) cout<<"footprint: "<<footprint_return<<endl;
        }
        if(footprint_return!=footprint_set) value_return = Active_;
        //
    }else{
        value_return=action;
    }
    return value_return;
};
void footprint::reset(){

};