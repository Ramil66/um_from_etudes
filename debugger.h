#ifndef DEBUGGER_H
#define DEBUGGER_H
#include "Processor.h"
#include <vector>
#include <unordered_map>
class Debugger{
public:
    explicit Debugger(Processor&,std::string);
    void run();
    void debug(Processor &UM);
private:
    std::vector<int> breakPoint;
    std::unordered_map<std::string,int> text_tags;
    Processor& UM;

};

#endif // !DEBUGGER_H
