#include <ctime>
#include <iostream>
#include "logs.h"
Logs::Logs(){
    std::time_t time = std::time(NULL);
    struct tm *now = localtime(&time);
    filename=std::to_string(now->tm_year+1900)+"-"+
               std::to_string(now->tm_mday)+"-"+ std::to_string(now->tm_mon+1)+" "+
               std::to_string(now->tm_hour)+":"+std::to_string(now->tm_min)+":"+std::to_string(now->tm_sec);
    file.open(filename);
}
Logs::~Logs(){
    if(file.is_open())
        file.close();
}
void Logs::writeMessage(const std::string& message){
    std::time_t time = std::time(NULL);
    struct tm *now = localtime(&time);
    file<<"["+std::to_string(now->tm_hour)+":"+std::to_string(now->tm_min)+":"+std::to_string(now->tm_sec)+
                "]\t"+message<<std::endl;
    if(coutConsole)
        std::cout<<"["+std::to_string(now->tm_hour)+":"+std::to_string(now->tm_min)+":"+std::to_string(now->tm_sec)+
                         "]\t"+message<<std::endl;
}
void Logs::writeError(const std::string& message){
    writeMessage("error: "+message);
}
