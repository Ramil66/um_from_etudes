#include <cmath>
#include "arithmeticcommands.h"
#include "Processor.h"
#include "except.h"


int cAR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword+data2.iword);
    if(INT32_MAX-data1.iword<data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword+data2.iword,0);
    return 0;
}

int cA::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword+data2.iword);
    if(INT32_MAX-data1.iword<data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword+data2.iword,0);
    return 0;
}

int cAI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.iword=word.dc.dir_op.i;
    VM.memory.storeWord(word.dc.reg1*4,data1.iword+data2.iword);
    if(INT32_MAX-data1.iword<data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword+data2.iword,0);
    return 0;
}
int cAC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=0;
    data2.byte[3]=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword+data2.iword);
    if(INT32_MAX-data1.iword<data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword+data2.iword,0);
    return 0;
}

int cSR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cSI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.iword=word.dc.dir_op.i;
    VM.memory.storeWord(word.dc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cSC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=0;
    data2.byte[3]=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword+data2.iword,0);
    return 0;
}

int cRSR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.sc.reg1*4);
    Word data1=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cRS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cRSI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data2=VM.memory.loadWord(word.dc.reg1*4);
    Word data1;
    data1.iword=word.dc.dir_op.i;
    VM.memory.storeWord(word.dc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cRSC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=0;
    data1.byte[3]=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword-data2.iword);
    if(((INT32_MAX/2)+(data2.iword/2)<data1.iword/2)||((INT32_MIN/2)+(data2.iword/2)>data1.iword/2))
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword-data2.iword,0);
    return 0;
}

int cMR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());;
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword*data2.iword);
    if(VM.memory.loadWord(word.sc.reg1*4).iword/data1.iword!=data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword*data2.iword,0);
    return 0;
}

int cM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword*data2.iword);
    if(VM.memory.loadWord(word.lc.reg1*4).iword/data1.iword!=data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword*data2.iword,0);
    return 0;
}

int cMI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.iword=word.dc.dir_op.i;
    VM.memory.storeWord(word.dc.reg1*4,data1.iword*data2.iword);
    if(VM.memory.loadWord(word.dc.reg1*4).iword/data1.iword!=data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword*data2.iword,0);
    return 0;
}

int cMC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2;
    data2.iword=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword*data2.iword);
    if(VM.memory.loadWord(word.lc.reg1*4).iword/data1.iword!=data2.iword)
        VM.psw.setO();
    else
        VM.psw.compare(data1.iword*data2.iword,0);
    return 0;
}

int cDR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cD::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cDI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.iword=word.dc.dir_op.i;
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cDC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2;
    data2.iword=VM.memory.loadByte(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cRDR::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.sc.reg1*4);
    Word data1=VM.memory.loadWord(short_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cRD::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=VM.memory.loadWord(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cRDI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data2=VM.memory.loadWord(word.dc.reg1*4);
    Word data1;
    data1.iword=word.dc.dir_op.i;
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}

int cRDC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1;
    data1.iword=VM.memory.loadByte(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.iword/data2.iword);
        VM.psw.compare(data1.iword/data2.iword,0);
        return 0;
    }
}
int cREMR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cREM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cREMI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.iword=word.dc.dir_op.i;
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.dc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cREMC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2;
    data2.iword=VM.memory.loadByte(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cRREMR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.sc.reg1*4);
    Word data1=VM.memory.loadWord(short_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cRREM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=VM.memory.loadWord(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cRREMI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data2=VM.memory.loadWord(word.dc.reg1*4);
    Word data1;
    data1.iword=word.dc.dir_op.i;
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.dc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cRREMC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1;
    data1.iword=VM.memory.loadByte(long_com(VM));
    if(data2.iword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,abs(data1.iword%data2.iword));
        VM.psw.compare(abs(data1.iword%data2.iword),0);
        return 0;
    }
}

int cFAR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.fword+data2.fword);
    VM.psw.compare(data1.iword+data2.fword,0);
    return 0;
}

int cFA::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.fword+data2.fword);
    VM.psw.compare(data1.fword+data2.fword,0);
    return 0;
}

int cFAI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.fword=word.dc.dir_op.f;
    VM.memory.storeWord(word.dc.reg1*4,data1.fword+data2.fword);
    VM.psw.compare(data1.fword+data2.fword,0);
    return 0;
}

int cFSR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword-data2.iword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}

int cFS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.fword-data2.fword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}

int cFSI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.fword=word.dc.dir_op.f;
    VM.memory.storeWord(word.dc.reg1*4,data1.fword-data2.fword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}


int cRFSR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.sc.reg1*4);
    Word data1=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.iword-data2.iword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}

int cRFS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.fword-data2.fword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}

int cRFSI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data2=VM.memory.loadWord(word.dc.reg1*4);
    Word data1;
    data1.fword=word.dc.dir_op.f;
    VM.memory.storeWord(word.dc.reg1*4,data1.fword-data2.fword);
    VM.psw.compare(data1.fword-data2.fword,0);
    return 0;
}

int cFMR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data1.fword*data2.fword);
    VM.psw.compare(data1.fword*data2.fword,0);
    return 0;
}

int cFM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.fword*data2.fword);
    VM.psw.compare(data1.fword*data2.fword,0);
    return 0;
}

int cFMI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.fword=word.dc.dir_op.f;
    VM.memory.storeWord(word.dc.reg1*4,data1.fword*data2.fword);
    VM.psw.compare(data1.fword*data2.fword,0);
    return 0;
}

int cFDR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cFD::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cFDI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data1=VM.memory.loadWord(word.dc.reg1*4);
    Word data2;
    data2.fword=word.dc.dir_op.f;
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cRFDR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.sc.reg1*4);
    Word data1=VM.memory.loadWord(short_com(VM));
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.sc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cRFD::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data2=VM.memory.loadWord(word.lc.reg1*4);
    Word data1=VM.memory.loadWord(long_com(VM));
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cRFDI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data2=VM.memory.loadWord(word.dc.reg1*4);
    Word data1;
    data1.fword=word.dc.dir_op.f;
    if(data2.fword==0) throw vm_error("Division by zero");
    else{
        VM.memory.storeWord(word.lc.reg1*4,data1.fword/data2.fword);
        VM.psw.compare(data1.fword/data2.fword,0);
        return 0;
    }
}

int cFLOATR::operator ()(Processor  &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data;
    data.fword=float(VM.memory.loadWord(short_com(VM)).iword);
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.fword,0);
    return 0;
}

int cFLOAT::operator ()(Processor  &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data;
    data.fword=float(VM.memory.loadWord(long_com(VM)).iword);
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.fword,0);
    return 0;
}

int cFLOATI::operator ()(Processor  &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data;
    data.fword=float(word.dc.dir_op.i);
    VM.memory.storeWord(word.dc.reg1*4,data);
    VM.psw.compare(data.fword,0);
    return 0;
}

int cFIXR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    if(data.fword>INT32_MAX||data.fword<INT32_MIN){
        VM.memory.storeWord(word.sc.reg1*4,0);
        VM.psw.setO();
    }
    else{
        data.iword=int(data.fword);
        VM.memory.storeWord(word.sc.reg1*4,data);
        VM.psw.compare(data.iword,0);
    }
}
int cFIX::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    if(data.fword>INT32_MAX||data.fword<INT32_MIN){
        VM.memory.storeWord(word.lc.reg1*4,0);
        VM.psw.setO();
    }
    else{
        data.iword=int(data.fword);
        VM.memory.storeWord(word.lc.reg1*4,data);
        VM.psw.compare(data.iword,0);
    }
}
int cFIXI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data;
    data.fword=word.dc.dir_op.f;
    if(data.fword>INT32_MAX||data.fword<INT32_MIN){
        VM.memory.storeWord(word.dc.reg1*4,0);
        VM.psw.setO();
    }
    else{
        data.iword=int(data.fword);
        VM.memory.storeWord(word.dc.reg1*4,data);
        VM.psw.compare(data.iword,0);
    }
}

int cFLOOR::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.fword=std::floor(data.fword);
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.fword,0);
    return 0;
}

int cCEIL::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.fword=std::ceil(data.fword);
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.fword,0);
    return 0;
}

int cMIN::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword>data2.iword?data2:data1);
    VM.psw.compare(data1.iword,VM.memory.loadWord(word.lc.reg1*4).iword);
    return 0;
}

int cMAX::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.lc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data1.iword>data2.iword?data1:data2);
    VM.psw.compare(data1.iword,VM.memory.loadWord(word.lc.reg1*4).iword);
    return 0;
}
