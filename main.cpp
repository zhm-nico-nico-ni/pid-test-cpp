#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PID.h"


int pid_test();
int main() {

    pid_test();
    return 0;
}

int pid_test(){
    PID pid;
    // double dt, double max, double min, double Kp, double Kd, double Ki
    //PID(0.1, 100, -100, 0.1, 0.01, 0.5);
    pid.kP(1.0f);
    pid.kI(0.01f);
    pid.kD(0.0f);
    pid.imax(500);
    float total = pid.get_pid(0, 1);
    std::cout << "pid_test " << total << std::endl;

    //假设读到的数据是-90 - 90 间，目标输出 50
    int targetVal = 50;
    srand((int)(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()));
    for(int x=0;x<10/*sizeof(data_array)/sizeof(int)*/;x++){
        float rdw = rand() % (90-(-90)+1)+ (-90);//产生随机数：表示  a=90~b=-90 之间的一个随机整数。
        float error  = rdw;
        float control= pid.get_pid(-(error - targetVal) , 1);//补偿值
        float control_out = rdw + control;//加上补偿值后，这个约等于targetVal
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << x<<"read:"<< error << " target:"<< (control_out)<< " control: " << control << std::endl;

    }
    std::cout << "avg:"<< total/20 << std::endl;
}