#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Types.h"
#include "psw.h"
#include "Memory.h"
#include "Commands/othercommands.h"
#include "logs.h"

class Processor{
public:
    Processor() noexcept;
    Processor(const Processor &) = delete;
    Processor(const Processor &&) = delete;
    Processor &operator=(const Processor &) = delete;
    Processor &operator=(const Processor &&) = delete;
    ~Processor();
    PSW psw;
    void clear() noexcept;                          //Очистка РОН
    int reset() noexcept;                           //Обнуление РПР
    void checkReg(Word word);
    void setTracing(bool tr){log.setConsole(true);} //Установка трасировки(Выполняется суперзвизором)
    Memory memory;
    int interpreter(bool);
    enum op_code : byte_t{
        LR      =   0x00,
        LNR     =   0x01,
        STR     =   0x02,
        SWAPR   =   0x03,
        ANDR    =   0x04,
        ORR     =   0x05,
        XORR    =   0x06,
        NOTR    =   0x07,
        BCSR    =   0x08,
        BCRR    =   0x09,
        BALR    =   0x0A,
        SACR    =   0x0B,
        CR      =   0x0C,
        CCS     =   0x0E,
        MCS     =   0x0F,
        AR      =   0x10,
        SR      =   0x11,
        RSR     =   0x12,
        MR      =   0x13,
        DR      =   0x14,
        RDR     =   0x15,
        REMR    =   0x16,
        RREMR   =   0x17,
        FAR     =   0x18,
        FSR     =   0x19,
        RFSR    =   0x1A,
        FMR     =   0x1B,
        FDR     =   0x1C,
        RFDR    =   0x1D,
        FLOATR  =   0x1E,
        FIXR    =   0x1F,
        L       =   0x20,
        LN      =   0x21,
        ST      =   0x22,
        SWAP    =   0x23,
        AND     =   0x24,
        OR      =   0x25,
        XOR     =   0x26,
        NOT     =   0x27,
        BCS     =   0x28,
        BCR     =   0x29,
        BAL     =   0x2A,
        SAC     =   0x2B,
        C       =   0x2C,
        EX      =   0x2F,
        SVC     =   0x2E,
        A       =   0x30,
        S       =   0x31,
        RS      =   0x32,
        M       =   0x33,
        D       =   0x34,
        RD      =   0x35,
        REM     =   0x36,
        RREM   =   0x37,
        FA      =   0x38,
        FS      =   0x39,
        RFS     =   0x3A,
        FM      =   0x3B,
        FD      =   0x3C,
        RFD     =   0x3D,
        FLOAT   =   0x3E,
        FIX     =   0x3F,
        LI      =   0x40,
        LNI     =   0x41,
        ANDI    =   0x44,
        ORI     =   0x45,
        XORI    =   0x46,
        NOTI    =   0x47,
        CI      =   0x4C,
        LA      =   0x4E,
        AI      =   0x50,
        SI      =   0x51,
        RSI     =   0x52,
        MI      =   0x53,
        DI      =   0x54,
        RDI     =   0x55,
        REMI    =   0x56,
        RREMI   =   0x57,
        FAI     =   0x58,
        FSI     =   0x59,
        RFSI    =   0x5A,
        FMI     =   0x5B,
        FDI     =   0x5C,
        RFDI    =   0x5D,
        FLOATI  =   0x5E,
        FIXI    =   0x5F,
        LC      =   0x60,
        LNC     =   0x61,
        STC     =   0x62,
        SWAPC   =   0x63,
        ANDC    =   0x64,
        ORC     =   0x65,
        XORC    =   0x66,
        NOTC    =   0x67,
        SACC    =   0x6B,
        CC      =   0x6C,
        LM      =   0x6E,
        STM     =   0x6F,
        AC      =   0x70,
        SC      =   0x71,
        RSC     =   0x72,
        MC      =   0x73,
        DC      =   0x74,
        RDC     =   0x75,
        REMC    =   0x76,
        RREMC   =   0x77,
        FLOOR   =   0x78,
        CEIL    =   0x79,
        MIN     =   0x7A,
        MAX     =   0x7B,
        SHIFTL  =   0x7C,
        SHIFTC  =   0x7D,
        SHIFTA  =   0x7F,
        end
    };
    friend class cEX;
private:
    Logs log;
    void init_command() noexcept;
    Command* commands[end];
};

#endif PROCESSOR_H
