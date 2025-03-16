#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>

#include "Processor.h"
#include "debugger.h"

bool loaderTxtFile(std::string filename, Processor& VM){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string line;
        unsigned int start=0;
        std::istringstream in;
        int bincode;
        std::getline(file,line);
        in.str(line);
        in>>std::hex>>loadaddr;
        std::getline(file,line);
        int loadaddr=2;
        while(std::getline(file,line)){
            VM.memory.storeByte(loadaddr,stoi(line));
            loadaddr+=sizeof(stoi(line));
        }
        VM.psw.setPC(start);
        file.close();
        return true;
    }
    std::cout<<filename<<" is not open"<<std::endl;
    return false;
}

int main(int argc, char *argv[]){
    bool debug=true;
    if (argc > 1){
        Processor  VM;
        VM.reset();
        if (loaderTxtFile(std::string(*argv), VM)) {
            if(debug){
                Debugger debug;
                debug.run();
                debug.debug(VM);
            }
            else
                VM.interpreter(debug);
        }
        else std::cout << argv[1] << " - not run!" << std::endl;
    }
    else std::cout << "No file in command line!" << std::endl;
    system("pause");
}
