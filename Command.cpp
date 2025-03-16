#include "Command.h"
#include "Processor.h"
#include "except.h"

address_t Command::short_com(Processor &VM)const{
    Half_word word=VM.memory.loadHalfWord(VM.psw.getPC());
    if((word.sc.reg1<0)||(word.sc.reg1>15)||(word.sc.reg2<0)||(word.sc.reg2>15)){
        throw vm_error("Disabled register address");
    }
    //Проверка бита косвенное адресации
    if(word.sc.i==0){
        return word.sc.reg2*4;
    }
    else{
        Word data;
        data=VM.memory.loadWord(word.sc.reg2*4);
        return data.lc.address;
    }
}
address_t Command::long_com(Processor &VM)const{
    Word word=VM.memory.loadWord(VM.psw.getPC());
    if((word.sc.reg1<0)||(word.sc.reg1>15)){
        throw vm_error("Disabled register address");
    }
    address_t addr;
    //Проверка бита косвенное адресации
    if(word.lc.i==0){
        //Проверка индекс регистра(R2)
        if(word.lc.reg2==0){
            addr=word.lc.address;
        }
        else{
            addr=word.lc.address;
            addr+=word.lc.reg2;
        }
    }
    else{
        if(word.lc.reg2==0){
            addr=VM.memory.loadHalfWord(word.lc.address).hw;
        }
        else{
            addr=VM.memory.loadHalfWord(word.lc.address).hw;
            addr+=word.lc.reg2;
        }
    }
    return addr;
}

