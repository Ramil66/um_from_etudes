#include "transitioncommands.h"
#include "Processor.h"

int cBCSR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.sc.reg1!=0)
        VM.psw.setPC(short_com(VM));
    return 0;
}

int cBCS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.lc.reg1!=0)
        VM.psw.setPC(long_com(VM));
    return 0;
}

int cBCRR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.sc.reg1==0)
        VM.psw.setPC(short_com(VM));
    return 0;
}

int cBCR::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.lc.reg1==0)
        VM.psw.setPC(long_com(VM));
    return 0;
}
int cBALR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data;
    data.word=VM.psw.getPC();
    VM.memory.storeWord(word.sc.reg1*4,data);
    if(word.sc.i==0)
        data.word=word.sc.reg2*4;
    else
        data.word=short_com(VM);
    VM.psw.setPC(data.word);
    return 0;
}

int cBAL::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.memory.storeWord(word.lc.reg1*4,VM.psw.getPC());
    VM.psw.setPC(long_com(VM));
    return 0;
}
