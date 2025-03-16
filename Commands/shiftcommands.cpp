#include "shiftcommands.h"
#include "Processor.h"

int cSHIFTL::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(word.lc.reg1*4);
    address_t shift=long_com(VM);
    if(shift>0)
        data.iword<<shift;
    else
        data.iword>>shift;
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.iword,0);
    return 0;
}
int cSHIFTC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(word.lc.reg1*4);
    address_t shift=long_com(VM);
    Word temp=data;
    if(shift>0){
        data.iword=(temp.iword<<shift)|(temp.iword>>32-shift);
    }
    else{
        data.iword=(temp.iword<<32-shift)|(temp.iword>>shift);
    }
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.iword,0);
    return 0;
}
int cSHIFTA::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(word.lc.reg1*4);
    address_t shift=long_com(VM);
    Word temp=data;
    if(shift>0){
        data.iword<<shift;
        if(data.lc.i!=temp.lc.i)
        VM.psw.setO();
    }
    else{
        temp.lc.address=0;
        temp.lc.opcode=0;
        temp.lc.reg1=0;
        temp.lc.reg2=0;
        data.iword=(data.iword>>shift)|temp.iword;
    }
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.iword,0);
    return 0;
}

