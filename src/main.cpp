///
/// Created by Anonymous275 on 28/01/2020
///

#include <iostream>
#include <string>
#include <fstream>
#include "logger.h"
#include <chrono>
#include <thread>

using namespace std; //nameSpace STD
void DebugData();
void LogInit();
void ParseConfig();
void ServerMain(int Port, int MaxClients);
bool Debug = false;
void addToLog(basic_string<char> Data);
void HeartbeatInit();
int Port = 30814;
int MaxPlayers = 10;
string MapName = "levels/gridmap/level.json";
string ServerName = "BeamNG-MP FTW";
string Resource = "/Resources";

//Entry
int main() {
    LogInit();
    HeartbeatInit();
    ParseConfig();
    if(Debug){ //checks if debug is on
        DebugData(); //Prints Debug Data
    }
    setLoggerLevel("ALL");
    ServerMain(Port, MaxPlayers);
}


void DebugData(){
    cout << "Debug : true" << "\n";
    cout << "Port : " << Port << "\n";
    cout << "MaxPlayers : " << MaxPlayers << "\n";
    cout << "MapName : " << MapName << "\n";
    cout << "ServerName : " << ServerName << "\n";
    cout << "File : " << Resource << "\n";
}

void SetMainValues(bool D, int P,int MP,string Name,string serverName,string filename){
    Debug = D;
    Port = P;
    MapName = Name;
    ServerName = serverName;
    MaxPlayers = MP;
    Resource = filename;
}

void LogInit(){
    ofstream LFS;
    LFS.open ("Server.log");
    LFS.close();
}

void addToLog(basic_string<char> Data){
    ofstream LFS;
    LFS.open ("Server.log", std::ios_base::app);
    LFS << Data.c_str();
    LFS.close();
}