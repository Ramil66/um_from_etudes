#ifndef PSW_H
#define PSW_H
#include "Types.h"

class PSW
{
    address_t PC;   //САК
    byte_t O:1;     //Флаг переполнения
    byte_t L:1;     //Флаг меньше
    byte_t E:1;     //Флаг равно
    byte_t G:1;     //Флаг больше
public:
    PSW();
    void setPC(address_t pc) noexcept;
    void setO() noexcept;
    void setL() noexcept;
    void setE() noexcept;
    void setG() noexcept;


    template<typename T1,typename T2>
    void compare(T1 arg1, T2 arg2) noexcept{
        if(arg1>arg2)
            setG();
        else if(arg1<arg2)
            setL();
        else
            setE();
    }

    //вывод 4 флагов
    half_byte getRPR() const noexcept;

    address_t getPC() const noexcept;
    byte_t getO() const noexcept;
    byte_t getL() const noexcept;
    byte_t getE() const noexcept;
    byte_t getG() const noexcept;
};

#endif // PSW_H
