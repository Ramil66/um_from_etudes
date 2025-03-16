#ifndef ARITHMETICCOMMANDS_H
#define ARITHMETICCOMMANDS_H

#include "Command.h"

class ArithmeticCommands:public Command
{
public:
    ArithmeticCommands(unsigned char _size):Command(_size){}
};

class cAR:public ArithmeticCommands{
public:
    cAR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cA:public ArithmeticCommands{
public:
    cA(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cAI:public ArithmeticCommands{
public:
    cAI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cAC:public ArithmeticCommands{
public:
    cAC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cSR:public ArithmeticCommands{
public:
    cSR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cS:public ArithmeticCommands{
public:
    cS(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cSI:public ArithmeticCommands{
public:
    cSI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cSC:public ArithmeticCommands{
public:
    cSC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRR:public ArithmeticCommands{
public:
    cRR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRSR:public ArithmeticCommands{
public:
    cRSR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRS:public ArithmeticCommands{
public:
    cRS(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRSI:public ArithmeticCommands{
public:
    cRSI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRSC:public ArithmeticCommands{
public:
    cRSC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cMR:public ArithmeticCommands{
public:
    cMR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cM:public ArithmeticCommands{
public:
    cM(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cMI:public ArithmeticCommands{
public:
    cMI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cMC:public ArithmeticCommands{
public:
    cMC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cDR:public ArithmeticCommands{
public:
    cDR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cD:public ArithmeticCommands{
public:
    cD(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cDI:public ArithmeticCommands{
public:
    cDI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cDC:public ArithmeticCommands{
public:
    cDC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};


class cRDR:public ArithmeticCommands{
public:
    cRDR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRD:public ArithmeticCommands{
public:
    cRD(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRDI:public ArithmeticCommands{
public:
    cRDI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRDC:public ArithmeticCommands{
public:
    cRDC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cREMR:public ArithmeticCommands{
public:
    cREMR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cREM:public ArithmeticCommands{
public:
    cREM(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cREMI:public ArithmeticCommands{
public:
    cREMI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cREMC:public ArithmeticCommands{
public:
    cREMC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRREMR:public ArithmeticCommands{
public:
    cRREMR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRREM:public ArithmeticCommands{
public:
    cRREM(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRREMI:public ArithmeticCommands{
public:
    cRREMI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRREMC:public ArithmeticCommands{
public:
    cRREMC(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cFAR:public ArithmeticCommands{
public:
    cFAR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFA:public ArithmeticCommands{
public:
    cFA(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
    virtual ~cFA(){}
};
class cFAI:public ArithmeticCommands{
public:
    cFAI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cFSR:public ArithmeticCommands{
public:
    cFSR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFS:public ArithmeticCommands{
public:
    cFS(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFSI:public ArithmeticCommands{
public:
    cFSI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRFSR:public ArithmeticCommands{
public:
    cRFSR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cRFS:public ArithmeticCommands{
public:
    cRFS(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cRFSI:public ArithmeticCommands{
public:
    cRFSI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cFMR:public ArithmeticCommands{
public:
    cFMR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFM:public ArithmeticCommands{
public:
    cFM(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFMI:public ArithmeticCommands{
public:
    cFMI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFDR:public ArithmeticCommands{
public:
    cFDR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFD:public ArithmeticCommands{
public:
    cFD(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
    virtual ~cFD(){}
};
class cFDI:public ArithmeticCommands{
public:
    cFDI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cRFDR:public ArithmeticCommands{
public:
    cRFDR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cRFD:public ArithmeticCommands{
public:
    cRFD(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cRFDI:public ArithmeticCommands{
public:
    cRFDI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cFLOATR:public ArithmeticCommands{
public:
    cFLOATR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFLOAT:public ArithmeticCommands{
public:
    cFLOAT(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFLOATI:public ArithmeticCommands{
public:
    cFLOATI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFIXR:public ArithmeticCommands{
public:
    cFIXR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFIX:public ArithmeticCommands{
public:
    cFIX(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cFIXI:public ArithmeticCommands{
public:
    cFIXI(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

class cFLOOR:public ArithmeticCommands{
public:
    cFLOOR(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cCEIL:public ArithmeticCommands{
public:
    cCEIL(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cMIN:public ArithmeticCommands{
public:
    cMIN(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};
class cMAX:public ArithmeticCommands{
public:
    cMAX(unsigned char _size):ArithmeticCommands(_size){}
    int operator ()(Processor &VM) override;
};

#endif // ARITHMETICCOMMANDS_H
