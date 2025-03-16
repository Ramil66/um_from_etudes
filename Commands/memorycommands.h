#ifndef MEMORYCOMMANDS_H
#define MEMORYCOMMANDS_H

#include "Command.h"

class MemoryCommands:public Command
{
public:
    MemoryCommands(unsigned short _size):Command(_size){}
};

class cLR:public MemoryCommands{
public:
    cLR(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cL:public MemoryCommands{
public:
    cL(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cLI:public MemoryCommands{
public:
    cLI(unsigned short _size):MemoryCommands(_size){}
     int operator ()(Processor &VM) override;
};
class cLC:public MemoryCommands{
public:
    cLC(unsigned short _size):MemoryCommands(_size){}
     int operator ()(Processor &VM) override;
};
class cLNR:public MemoryCommands{
public:
    cLNR(unsigned short _size):MemoryCommands(_size){}
     int operator ()(Processor &VM) override;
};
class cLN:public MemoryCommands{
public:
    cLN(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cLNI:public MemoryCommands{
public:
    cLNI(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cLNC:public MemoryCommands{
public:
    cLNC(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cSTR:public MemoryCommands{
public:
    cSTR(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cST:public MemoryCommands{
public:
    cST(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cSTC:public MemoryCommands{
public:
    cSTC(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cSWAPR:public MemoryCommands{
public:
    cSWAPR(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cSWAP:public MemoryCommands{
public:
    cSWAP(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cSWAPC:public MemoryCommands{
public:
    cSWAPC(unsigned short _size):MemoryCommands(_size){}
    int operator ()(Processor &VM) override;
};

#endif // MEMORYCOMMANDS_H
