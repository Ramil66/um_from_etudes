#include "psw.h"

PSW::PSW():PC(0),O(0),L(0),E(0),G(0){}

void PSW::setPC(address_t pc)noexcept{PC=pc;}
void PSW::setO()noexcept{O=1;}
void PSW::setL()noexcept{
    L=1;
    E=0;
    G=0;
}
void PSW::setE() noexcept{
    E=1;
    L=0;
    G=0;
}
void PSW::setG() noexcept{
    G=1;
    L=0;
    E=0;
}

half_byte PSW::getRPR() const noexcept{
    half_byte rpr;
    rpr.hb=O;
    rpr.hb=(rpr.hb<<1)+L;
    rpr.hb=(rpr.hb<<1)+G;
    rpr.hb=(rpr.hb<<1)+E;
    return rpr;
}

address_t PSW::getPC() const noexcept{return PC;}
byte_t PSW::getO() const noexcept{return O;}
byte_t PSW::getL() const noexcept{return L;}
byte_t PSW::getE() const noexcept{return E;}
byte_t PSW::getG() const noexcept{return G;}
