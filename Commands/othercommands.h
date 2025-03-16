#ifndef OTHERCOMMANDS_H
#define OTHERCOMMANDS_H

#include "Command.h"

class OtherCommands:public Command
{
public:
    OtherCommands(unsigned short _size):Command(_size){}
};

class cMCS:public OtherCommands{
public:
    cMCS(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cEX:public OtherCommands{
public:
    cEX(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cLA:public OtherCommands{
public:
    cLA(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cLM:public OtherCommands{
public:
    cLM(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSTM:public OtherCommands{
public:
    cSTM(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSACR:public OtherCommands{
public:
    cSACR(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSAC:public OtherCommands{
public:
    cSAC(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSACC:public OtherCommands{
public:
    cSACC(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSVC:public OtherCommands{
public:
    cSVC(unsigned char _size):OtherCommands(_size){}
    int operator()(Processor &VM) override;
};


#endif // OTHERCOMMANDS_H
