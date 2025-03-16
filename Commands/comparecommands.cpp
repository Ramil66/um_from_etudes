#include "comparecommands.h"
#include "Processor.h"
#include "except.h"

int cCR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(short_com(VM));
    VM.psw.compare(VM.memory.loadWord(word.sc.reg1*4).iword,data.iword);
    return 0;
}
int cC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=VM.memory.loadWord(long_com(VM));
    VM.psw.compare(VM.memory.loadWord(word.sc.reg1*4).iword,data.iword);
    return 0;
}
int cCI::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    VM.checkReg(word);
    Word data;
    data.iword=word.dc.dir_op.i;
    VM.psw.compare(VM.memory.loadWord(word.sc.reg1*4).iword,data.iword);
    return 0;
}
int cCC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    byte_t data=VM.memory.loadByte(long_com(VM));
    VM.psw.compare(VM.memory.loadByte(word.sc.reg1*4+3),data);
    return 0;
}
int cCCS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if((word.sc.reg2<0)||(word.sc.reg2>14))
        throw vm_error("Disabled register address");
    Word data1=VM.memory.loadWord(word.sc.reg2*4);
    Word data2=VM.memory.loadWord((word.sc.reg2+1)*4);
    byte_t A1=VM.memory.loadByte(data1.half_word[1].hw);
    byte_t A2=VM.memory.loadByte(data2.half_word[1].hw);
    int L=data2.half_word[1].hw;
    while(true){
        if(L==0){
            VM.memory.storeHalfWord(word.sc.reg2*4,0);
            VM.memory.storeHalfWord((word.sc.reg2+1)*4,0);
            VM.memory.storeHalfWord(word.sc.reg2*4+2,A1);
            VM.memory.storeHalfWord((word.sc.reg2+1)*4+2,A2);
            break;
        }
        VM.psw.compare(A1,A2);
        if(VM.psw.getE()){
            VM.memory.storeHalfWord(word.sc.reg2*4,0);
            VM.memory.storeHalfWord(word.sc.reg2*4+2,A1);
            VM.memory.storeHalfWord((word.sc.reg2+1)*4+2,data2.half_word[1]);
            break;
        }
        L--;
        data1.half_word[1].hw+=word.sc.reg1;
        A1=VM.memory.loadByte(data1.half_word[1].hw);
        A2++;
    }
    return 0;
}
