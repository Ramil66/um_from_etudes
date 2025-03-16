#include <iostream>
#include "othercommands.h"
#include "Processor.h"
#include "except.h"

int cSACR::operator ()(Processor &VM){
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.sc.reg1==0)
        VM.memory.storeWord(short_com(VM),0);
    else
        VM.memory.storeWord(short_com(VM),int(0xFFFFFFFF));
    return 0;
}

int cSAC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.sc.reg1==0)
        VM.memory.storeWord(long_com(VM),Word(0));
    else
        VM.memory.storeWord(long_com(VM),int(0xFFFFFFFF));
    return 0;
}

int cSACC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if(VM.psw.getRPR().hb&word.sc.reg1==0)
        VM.memory.storeByte(long_com(VM),0);
    else
        VM.memory.storeByte(long_com(VM),0xFF);
    return 0;
}

int cSVC::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    switch(word.sc.reg1){
    case 0:
        VM.clear();
        VM.reset();
        return 1;
    case 1:
        int32_t in_number;
        std::cin>>in_number;
        VM.memory.storeWord(long_com(VM),in_number);
    case 2:
        float in_fnumber;
        std::cin>>in_fnumber;
        VM.memory.storeWord(long_com(VM),in_fnumber);
    case 3:
        char in_lit;
        std::cin>>in_lit;
        VM.memory.storeByte(long_com(VM),in_lit);
    case 5:
        std::cout<<VM.memory.loadWord(long_com(VM)).iword;
    case 6:
        std::cout<<VM.memory.loadWord(long_com(VM)).fword;
    case 7:
        std::cout<<VM.memory.loadByte(long_com(VM));
    case 9:
        VM.setTracing(word.lc.reg2);
    }
    return 0;
}

int cMCS::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if((word.sc.reg2<0)||(word.sc.reg2>14)) throw vm_error("Disabled register address");
    Word data1=VM.memory.loadWord(word.sc.reg2*4);
    Word data2=VM.memory.loadWord((word.sc.reg2+1)*4);
    byte_t A1=VM.memory.loadByte(data1.half_word[1].hw);
    byte_t A2=VM.memory.loadByte(data2.half_word[1].hw);
    int L=data2.half_word[1].hw;
    while(true){
        if(L=0){
            VM.memory.storeHalfWord(word.sc.reg2*4,0);
            VM.memory.storeHalfWord((word.sc.reg2+1)*4,0);
            VM.memory.storeHalfWord(word.sc.reg2*4+2,A1);
            VM.memory.storeHalfWord((word.sc.reg2+1)*4+2,A2);
            break;
        }
        A2=VM.memory.loadByte(data1.half_word[1].hw);
        L--;
        A2++;
        A1+=word.sc.reg1;
    }
}
int cEX::operator ()(Processor&VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    address_t data=long_com(VM);
    if(data%2!=0) throw vm_error("Invalid executive address");
    byte_t byte=VM.memory.loadByte(data)&0b01111111;
    if(byte==0xFFFE) throw vm_error("error: Opcode loop");
    if(byte>0x7F) throw vm_error("error: Incorrect command");
    VM. commands[byte]->operator ()(VM);
    return 0;
}

int cLA::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    address_t data=long_com(VM);
    VM.memory.storeWord(data,word.sc.reg1*4);
    return 0;
}

int cLM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=word;
    data.lc.reg2=0;
    VM.memory.storeWord(VM.psw.getPC(),data);
    address_t addr=long_com(VM);
    VM.memory.storeWord(VM.psw.getPC(),word);
    if(word.lc.reg1<word.lc.reg2){
        for(int i=word.lc.reg1;i<word.lc.reg2;i++){
            VM.memory.storeWord(i*4,VM.memory.loadWord(addr));
            addr+=4;
        }
    }
    else{
        for(int i=word.lc.reg1;i<=15;i++){
            VM.memory.storeWord(i*4,VM.memory.loadWord(addr));
            addr+=4;
        }
        for(int i=0;i<word.lc.reg2;i++){
            VM.memory.storeWord(i*4,VM.memory.loadWord(addr));
            addr+=4;
        }
    }
    return 0;
}

int cSTM::operator ()(Processor &VM){
    Word word=VM.memory.loadWord(VM.psw.getPC());
    Word data=word;
    data.lc.reg2=0;
    VM.memory.storeWord(VM.psw.getPC(),data);
    address_t addr=long_com(VM);
    VM.memory.storeWord(VM.psw.getPC(),word);
    if(word.lc.reg1<word.lc.reg2){
        for(int i=word.lc.reg1;i<word.lc.reg2;i++){
            VM.memory.storeWord(addr,VM.memory.loadWord(i*4));
            addr+=4;
        }
    }
    else{
        for(int i=word.lc.reg1;i<=15;i++){
            VM.memory.storeWord(addr,VM.memory.loadWord(i*4));
            addr+=4;
        }
        for(int i=0;i<word.lc.reg2;i++){
            VM.memory.storeWord(addr,VM.memory.loadWord(i*4));
            addr+=4;
        }
    }
    return 0;
}

