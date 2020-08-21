///
/// Created by Anonymous275 on 7/28/2020
///
#include "Security/Enc.h"
#include "Client.hpp"
#include "Logger.h"
#include <string>

std::string CustomIP;
std::string GetSVer(){
    return Sec("0.60");
}
std::string GetCVer(){
    return Sec("1.60");
}
void Args(int argc, char* argv[]){
    info(Sec("BeamMP Server Running version ") + GetSVer());
    if(argc > 1){
        CustomIP = argv[1];
        size_t n = std::count(CustomIP.begin(), CustomIP.end(), '.');
        auto p = CustomIP.find_first_not_of(Sec(".0123456789"));
        if(p != std::string::npos || n != 3 || CustomIP.substr(0,3) == Sec("127")){
            CustomIP.clear();
            warn(Sec("IP Specified is invalid! Ignoring"));
        }else info(Sec("Server started with custom IP"));
    }
}
void InitServer(int argc, char* argv[]){
    InitLog();
    Args(argc,argv);
    CI = new ClientInterface;
}