#include <cstring>
#include "Memory.h"
#include "except.h"
Memory::Memory():size(65536),memory(new byte_t[size]){}

byte_t Memory::loadByte(address_t address)const {
    return memory[address];
}
void Memory::storeByte(address_t address,byte_t byte){
    memory[address]=byte;
}
Half_word Memory::loadHalfWord(address_t address) const{
    if(address%2!=0){
        throw vm_error("Invalid executive address");
    }
    Half_word half_word;
    std::memcpy(&half_word.b[0],&memory[address],2);
    return half_word;
}
void Memory::storeHalfWord(address_t address, Half_word half_word){
    if(address%2!=0){
        throw vm_error("Invalid executive address");
    }
    std::memcpy(&memory[address],&half_word.b[0],2);
}
Word Memory::loadWord(address_t address) const{
    if(address%4!=0)
        throw vm_error("Invalid executive address");
    Word word;
    std::memcpy(&word.byte[0],&memory[address],4);
    return word;
}
void Memory::storeWord(address_t address,Word word){
    if(address%4!=0)
        throw vm_error("Invalid executive address");
    std::memcpy(&memory[address],&word.byte[0],2);
}
Memory::~Memory() noexcept{
    delete []memory;
}
