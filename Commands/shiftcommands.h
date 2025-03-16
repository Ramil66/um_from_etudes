#ifndef SHIFTCOMMANDS_H
#define SHIFTCOMMANDS_H
#include "Command.h"

class ShiftCommands:public Command
{
public:
    ShiftCommands(unsigned char _size):Command(_size){}
};

class cSHIFTL:public ShiftCommands{
public:
    cSHIFTL(unsigned char _size):ShiftCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSHIFTC:public ShiftCommands{
public:
    cSHIFTC(unsigned char _size):ShiftCommands(_size){}
    int operator()(Processor &VM) override;
};

class cSHIFTA:public ShiftCommands{
public:
    cSHIFTA(unsigned char _size):ShiftCommands(_size){}
    int operator()(Processor &VM) override;
};

#endif // SHIFTCOMMANDS_H
