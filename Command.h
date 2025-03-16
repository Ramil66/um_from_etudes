#ifndef COMMAND_H
#define COMMAND_H

#include "Types.h"
#include "logs.h"

class Processor;

class Command{
public:
    Command()=default;
    Command(unsigned short _size):size(_size){}
    unsigned short size;
    virtual ~Command()=default;
    virtual int operator()(Processor &VM)=0;
protected:
    //Получение исполнительного адреса короткой команды
    address_t long_com(Processor &VM) const;
    //Получение исполнительонго адресы длиной команды
    address_t short_com(Processor &VM) const;
};

#endif COMMAND_H
