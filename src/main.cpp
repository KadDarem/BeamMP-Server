#include "Startup.h"
#include <thread>
#include <iostream>
[[noreturn]] void loop(){
    while(true){
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}
int main(int argc, char* argv[]) {
    #ifdef DEBUG
        std::thread t1(loop);
        t1.detach();
    #endif
    ConsoleInit();
    InitServer(argc,argv);
    InitConfig();
    InitLua();
    InitRes();
    HBInit();
    StatInit();
    NetMain();
    return 0;
}
