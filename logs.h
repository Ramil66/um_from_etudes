#ifndef LOGS_H
#define LOGS_H
#include <string>
#include <fstream>
class Logs
{
public:
    Logs();
    ~Logs();
    void setConsole(bool c){coutConsole=c;}
    bool getConsole(){return coutConsole;}
    void writeMessage(const std::string& message);
    void writeError(const std::string& message);
private:
    bool coutConsole=false;
    std::string filename;
    std::ofstream file;
};

#endif // LOGS_H
