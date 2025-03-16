#include "memorycommands.h"
#include "Processor.h"

int cLR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cL::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cLI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC()),data;
    VM.checkReg(word);
    data=word;
    if(data.dc.dir_op.i>0){
        data.dc.i=0;
        data.dc.opcode=0b0000000;
        data.dc.reg1=0b0000;
    }
    else{
        data.dc.i=1;
        data.dc.opcode=0b1111111;
        data.dc.reg1=0b1111;
    }
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cLC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,0);
    VM.memory.storeByte(word.lc.reg1*4+3,data);
    VM.psw.compare(data,0);
    return 0;
}

int cLNR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    if(data.word<0)
        data.word=~data.word+1;
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cLN::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    if(data.word<0)
        data.word=~data.word+1;
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cLNI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=word;
    VM.checkReg(word);
    if(data.dc.dir_op.i>0){
        data.dc.i=0;
        data.dc.opcode=0b0000000;
        data.dc.reg1=0b0000;
    }
    else{
        data.dc.i=1;
        data.dc.opcode=0b1111111;
        data.dc.reg1=0b1111;
    }
    if(data.word<0)
        data.word=~data.word+1;
    VM.memory.storeWord(word.sc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cLNC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=0;
    data.byte[3]=VM.memory.loadByte(long_com(VM));
    VM.memory.storeWord(word.lc.reg1*4,data);
    VM.psw.compare(data.word,0);
    return 0;
}

int cSTR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(word.sc.reg1*4);
    VM.memory.storeWord(short_com(VM),data);
    VM.psw.compare(data.word,0);
    return 0;
}
int cST::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(word.sc.reg1*4);
    VM.memory.storeWord(long_com(VM),data);
    VM.psw.compare(data.word,0);
    return 0;
}
int cSTC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(word.sc.reg1*4+3);
    VM.memory.storeWord(long_com(VM),data);
    VM.psw.compare(data,0);
    return 0;
}

int cSWAPR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(short_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data2);
    VM.memory.storeWord(short_com(VM),data1);
    VM.psw.compare(data2.word,0);
    return 0;
}
int cSWAP::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data1=VM.memory.loadWord(word.sc.reg1*4);
    Word data2=VM.memory.loadWord(long_com(VM));
    VM.memory.storeWord(word.sc.reg1*4,data2);
    VM.memory.storeWord(long_com(VM),data1);
    VM.psw.compare(data2.word,0);
    return 0;
}
int cSWAPC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data1=VM.memory.loadByte(word.sc.reg1*4+3);
    byte_t data2=VM.memory.loadByte(long_com(VM));
    VM.memory.storeByte(word.sc.reg1*4+3,data2);
    VM.memory.storeByte(long_com(VM),data1);
    VM.psw.compare(VM.memory.loadWord(word.lc.reg1*4).word,0);
    return 0;
}

