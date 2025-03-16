#ifndef COMPARECOMMANDS_H
#define COMPARECOMMANDS_H

#include "Command.h"

class CompareCommands:public Command
{
public:
    CompareCommands(unsigned char _size):Command(_size){}
};

class cCR:public CompareCommands{
public:
    cCR(unsigned char _size):CompareCommands(_size){}
    int operator()(Processor &VM) override;
};


class cC:public CompareCommands{
public:
    cC(unsigned char _size):CompareCommands(_size){}
    int operator()(Processor &VM) override;
};

class cCI:public CompareCommands{
public:
    cCI(unsigned char _size):CompareCommands(_size){}
    int operator()(Processor &VM) override;
};


class cCC:public CompareCommands{
public:
    cCC(unsigned char _size):CompareCommands(_size){}
    int operator()(Processor &VM) override;
};

class cCCS:public CompareCommands{
public:
    cCCS(unsigned char _size):CompareCommands(_size){}
    int operator()(Processor &VM) override;
};

#endif // COMPARECOMMANDS_H
