#include "debugger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <regex>

Debugger::Debugger(Processor& um,std::string filename):UM(um){
    std::ifstream file("debug-"+filename);
    std::string str;
    if(!file.is_open())
        throw std::exception("Could not find debug file");
    while(getline(file,str)){
        text_tags.insert({str.substr(,str.find(" ")),stoi(str.substr(str.find(" ")))});
    }
}

void Debugger::run(){
    std::cin<<"run> ";
    std::string str;
    cin>>str;
    std::vector<std::string> points;  
    boost::split(points,str,boost::is_any_of(" "));
    for(int i=0;i<<points.size();i++){
        if(std::regex_match(str,std::regex("^[a-z|A-Z|\.|@|_|\?|\$]+[@|_|\?|\$|a-z|A-Z|0-9]*$"))){
            breakPoint.push_back(text_tags[points[i]]);
        }
        else{
            breakPoint.push_back(stoi(points[i]))
        }
    }
}
void Debugger::debug(Processor &UM){
    std::string com; 
    std::cout<<""
    std::cin>>com;



    
    do{
        std::cout<<"debug> "
        std::cin>>com;
        std::cout<<std::endl;
        switch(com){
            case "next":
                break;
            case "registers":
                break;
            case "help":
                break;
            case "flags":
                break;
            case "show":
                break;
            default:
                std::cout<<"Invalid command format"<<std::endl;
                break;
        }


    }while(com!="quit"||com!="q")
}