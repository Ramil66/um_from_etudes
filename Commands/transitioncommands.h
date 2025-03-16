#ifndef TRANSITIONCOMMANDS_H
#define TRANSITIONCOMMANDS_H

#include "Command.h"

class TransitionCommands:public Command
{
public:
    TransitionCommands(unsigned char _size):Command(_size){}
};

class cBCSR:public TransitionCommands{
public:
    cBCSR(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cBCS:public TransitionCommands{
public:
    cBCS(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cBCRR:public TransitionCommands{
public:
    cBCRR(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cBCR:public TransitionCommands{
public:
    cBCR(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cBALR:public TransitionCommands{
public:
    cBALR(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cBAL:public TransitionCommands{
public:
    cBAL(unsigned char _size):TransitionCommands(_size){}
    int operator ()(Processor &VM) override;
};



#endif // TRANSITIONCOMMANDS_H
