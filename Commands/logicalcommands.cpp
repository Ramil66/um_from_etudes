#include "logicalcommands.h"
#include "Processor.h"

int cANDR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    data.word=data.word&VM.memory.loadWord(word.sc.reg1*4).word;
    VM.memory.storeWord(word.sc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cAND::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.word=data.word&VM.memory.loadWord(word.lc.reg1*4).word;
    VM.memory.storeWord(word.lc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cANDI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data=word;
    data.dc.i=0;
    data.dc.opcode=0;
    data.dc.reg1=0;
    data.word=data.word&VM.memory.loadWord(word.dc.reg1*4).word;
    VM.memory.storeWord(word.dc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cANDC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    data=data&VM.memory.loadByte(word.lc.reg1*4+3);
    VM.memory.storeByte(word.lc.reg1*4+3,data);
    if(data==0xFF)
        VM.psw.setG();
    else if(data==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}


int cORR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    data.word=data.word|VM.memory.loadWord(word.sc.reg1*4).word;
    VM.memory.storeWord(word.sc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cOR::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.word=data.word|VM.memory.loadWord(word.lc.reg1*4).word;
    VM.memory.storeWord(word.lc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cORI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data=word;
    data.dc.i=0;
    data.dc.opcode=0;
    data.dc.reg1=0;
    data.word=data.word|VM.memory.loadWord(word.dc.reg1*4).word;
    VM.memory.storeWord(word.dc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cORC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    data=data|VM.memory.loadByte(word.lc.reg1*4+3);
    VM.memory.storeByte(word.lc.reg1*4+3,data);
    if(data==0xFF)
        VM.psw.setG();
    else if(data==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cXORR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    data.word=data.word^VM.memory.loadWord(word.sc.reg1*4).word;
    VM.memory.storeWord(word.sc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cXOR::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.word=data.word^VM.memory.loadWord(word.lc.reg1*4).word;
    VM.memory.storeWord(word.lc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cXORI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data=word;
    data.dc.i=0;
    data.dc.opcode=0;
    data.dc.reg1=0;
    data.word=data.word^VM.memory.loadWord(word.dc.reg1*4).word;
    VM.memory.storeWord(word.dc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cXORC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    data=data^VM.memory.loadByte(word.lc.reg1*4+3);
    VM.memory.storeByte(word.lc.reg1*4+3,data);
    if(data==0xFF)
        VM.psw.setG();
    else if(data==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cNOTR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    data.word=~data.word;
    VM.memory.storeWord(word.sc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cNOT::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    data.word=~data.word;
    VM.memory.storeWord(word.lc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cNOTI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data=word;
    data.dc.i=0;
    data.dc.opcode=0;
    data.dc.reg1=0;
    data.word=~data.word;
    VM.memory.storeWord(word.dc.reg1*4,data);
    if(data.word==0xFFFFFFFF)
        VM.psw.setG();
    else if(data.word==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

int cNOTC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    data=~data;
    VM.memory.storeByte(word.lc.reg1*4+3,data);
    if(data==0xFF)
        VM.psw.setG();
    else if(data==0x0)
        VM.psw.setE();
    else
        VM.psw.setL();
    return 0;
}

