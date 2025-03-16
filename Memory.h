#ifndef MEMORY_H
#define MEMORY_H

#include <string>

#include "Types.h"

class Memory{
    int size;
    byte_t* memory;
public:
    Memory();
    Memory(const Memory &) = delete;
    Memory(const Memory &&) = delete;
    Memory &operator=(const Memory &) = delete;
    Memory &operator=(const Memory &&) = delete;
    //Загрузка и сохранение байта
    byte_t loadByte(address_t address) const;
    void storeByte(address_t address,byte_t byte);
    //Загрузка и сохранение половины слова
    Half_word loadHalfWord(address_t address) const;
    void storeHalfWord(address_t address, Half_word half_word);
    //Загрузка и сохранение слова
    Word loadWord(address_t address) const;
    void storeWord(address_t address,Word word);
    ~Memory() noexcept;
};
#endif MEMORY_H
