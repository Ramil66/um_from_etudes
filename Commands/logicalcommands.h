#ifndef LOGICALCOMMANDS_H
#define LOGICALCOMMANDS_H

#include"Command.h"

class LogicalCommands: public Command
{
public:
    LogicalCommands(unsigned short _size):Command(_size){}
};

class cANDR:public LogicalCommands{
public:
    cANDR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cAND:public LogicalCommands{
public:
    cAND(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cANDI:public LogicalCommands{
public:
    cANDI(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cANDC:public LogicalCommands{
public:
    cANDC(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cORR:public LogicalCommands{
public:
    cORR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cOR:public LogicalCommands{
public:
    cOR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cORI:public LogicalCommands{
public:
    cORI(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cORC:public LogicalCommands{
public:
    cORC(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cXORR:public LogicalCommands{
public:
    cXORR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cXOR:public LogicalCommands{
public:
    cXOR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cXORI:public LogicalCommands{
public:
    cXORI(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cXORC:public LogicalCommands{
public:
    cXORC(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cNOTR:public LogicalCommands{
public:
    cNOTR(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
    virtual ~cNOTR(){}
};

class cNOT:public LogicalCommands{
public:
    cNOT(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cNOTI:public LogicalCommands{
public:
    cNOTI(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cNOTC:public LogicalCommands{
public:
    cNOTC(unsigned short _size):LogicalCommands(_size){}
    int operator ()(Processor &VM) override;
};


#endif // LOGICALCOMMANDS_H
