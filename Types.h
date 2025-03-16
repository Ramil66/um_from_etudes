#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>

using byte_t=uint8_t;
using half_word_t=uint16_t;
using address_t=uint16_t;
using word_t=uint32_t;


struct half_byte{
    byte_t hb:4;
};

#pragma pack(push,1)
struct short_command{   //Формат короткой команды
    byte_t i:1;         //Косвенный бит
    byte_t opcode:7;    //Код операции
    byte_t reg1:4;      //R1
    byte_t reg2:4;      //R2
};
#pragma pack(pop)

#pragma pack(push,1)
struct long_command{    //Формат длинной команды
    byte_t i:1;
    byte_t opcode:7;
    byte_t reg1:4;
    byte_t reg2:4;
    address_t address:16;//Иполнительный адрес
};
#pragma pack(pop)

#pragma pack(push,1)
struct direct_command{  //Формат непосредственной команды
    byte_t i:1;
    byte_t opcode:7;
    byte_t reg1:4;
    union dir{          //Непосредственный операнд
        int i:20;
        float f;
    }dir_op;
};
#pragma pack(pop)

union Half_word{
    Half_word(int i=0):hw(i){}
    byte_t b[2];
    half_word_t hw;
    short_command sc;
};

union Word{
    Word(int w=0):word(w){}
    Word(float w):fword(w){}
    float fword;
    int iword;
    word_t word;
    Half_word half_word[2];
    byte_t byte[4];
    short_command sc;
    long_command lc;
    direct_command dc;
};
#endif TYPES_H
