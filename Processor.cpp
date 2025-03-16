#include "Processor.h"
#include "except.h"
#include "Commands/memorycommands.h"
#include "Commands/logicalcommands.h"
#include "Commands/transitioncommands.h"
#include "Commands/arithmeticcommands.h"
#include "Commands/comparecommands.h"
#include "Commands/othercommands.h"
#include "Commands/shiftcommands.h"


Processor::Processor() noexcept{
    init_command();
    clear();
    reset();
}

Processor::~Processor(){
    delete *commands;
}

void Processor::clear() noexcept{
    for(int i=0;i<16;i++){
        memory.storeWord(i*4,0);
    }
}
int Processor::reset() noexcept{
    psw.setPC(0);
    psw.setO();
    psw.setE();
    return 0;
}

void Processor::checkReg(Word word){
    if((word.lc.reg1<0)||(word.lc.reg1>15))
        throw vm_error("Disabled register address");
}

void Processor::init_command() noexcept{
    commands[LR]=       new cLR(16);        //загрузка
    commands[L]=        new cL(32);         //
    commands[LI]=       new cLI(32);        //
    commands[LC]=       new cLC(32);        //
    commands[LNR]=      new cLNR(16);       //загрузка отрицательная
    commands[LN]=       new cLN(32);        //
    commands[LNI]=      new cLNI(32);       //
    commands[LNC]=      new cLNC(32);       //
    commands[STR]=      new cSTR(16);       //запись регистра
    commands[ST]=       new cST(32);        //запись в память
    commands[STC]=      new cSTC(32);       //запись в память байта
    commands[SWAPR]=    new cSWAPR(16);     //обмен
    commands[SWAP]=     new cSWAP(32);      //обмен с памятью
    commands[SWAPC]=    new cSWAPC(32);     //обмен с байтом
    commands[ANDR]=     new cANDR(16);      //и
    commands[AND]=      new cAND(32);       //
    commands[ANDI]=     new cANDI(32);      //
    commands[ANDC]=     new cANDC(32);      //
    commands[ORR]=      new cORR(16);       //или
    commands[OR]=       new cOR(32);        //
    commands[ORI]=      new cORI(32);       //
    commands[ORC]=      new cORC(32);       //
    commands[XORR]=     new cXORR(16);      //исключающее или
    commands[XOR]=      new cXOR(32);       //
    commands[XORI]=     new cXORI(32);      //
    commands[XORC]=     new cXORC(32);      //
    commands[NOTR]=     new cNOTR(16);      //отрицание
    commands[NOT]=      new cNOT(32);       //
    commands[NOTI]=     new cNOTI(32);      //
    commands[NOTC]=     new cNOTC(32);      //
    commands[BCSR]=     new cBCSR(16);      //условный переход по единице
    commands[BCS]=      new cBCS(32);       //
    commands[BCRR]=     new cBCRR(16);      //условный переход  по нулю
    commands[BCR]=      new cBCR(32);       //
    commands[BALR]=     new cBALR(16);      //переход с возвратом
    commands[BAL]=      new cBAL(32);       //
    commands[SACR]=     new cSACR(16);      //сохранение состояния
    commands[SAC]=      new cSAC(32);       //
    commands[SACC]=     new cSACC(32);      //
    commands[CR]=       new cCR(16);        //сравнение
    commands[C]=        new cC(32);         //
    commands[CI]=       new cCI(32);        //
    commands[CC]=       new cCC(32);        //
    commands[CCS]=      new cCCS(32);       //сравнение цепочки байтов
    commands[MCS]=      new cMCS(16);       //Пересылка цепочки байтов
    commands[SVC]=      new cSVC(32);       //Вызов супервизора
    commands[EX]=       new cEX(32);        //Выполнить
    commands[LA]=       new cLA(32);        //Загрузка адреса
    commands[LM]=       new cLM(32);        //загрузка групповая
    commands[STM]=      new cSTM(32);       //Запись групповая
    commands[AR]=       new cAR(16);        //Сложение
    commands[A]=        new cA(32);         //
    commands[AI]=       new cAI(32);        //
    commands[AC]=       new cAC(32);        //
    commands[SR]=       new cSR(16);        //Вычитание
    commands[S]=        new cS(32);         //
    commands[SI]=       new cSI(32);        //
    commands[SC]=       new cSC(32);        //
    commands[RSR]=      new cRSR(16);       //вычитание обратное
    commands[RS]=       new cRS(32);        //
    commands[RSI]=      new cRSI(32);       //
    commands[RSC]=      new cRSC(32);       //
    commands[MR]=       new cMR(16);        //Умножение
    commands[M]=        new cM(32);         //
    commands[MI]=       new cMI(32);        //
    commands[MC]=       new cMC(32);        //
    commands[DR]=       new cDR(16);        //Деление
    commands[D]=        new cD(32);         //
    commands[DI]=       new cDI(32);        //
    commands[DC]=       new cDC(32);        //
    commands[RDR]=      new cRDR(16);       //Деление обратное
    commands[RD]=       new cRD(32);        //
    commands[RDI]=      new cRDI(32);       //
    commands[RDC]=      new cRDC(32);       //
    commands[REMR]=     new cREMR(16);      //Остаток
    commands[REM]=      new cREM(32);       //
    commands[REMI]=     new cREMI(32);      //
    commands[REMC]=     new cREMC(32);      //
    commands[RREMR]=    new cRREMR(16);     //Остаток от обратного деления
    commands[RREM]=     new cRREM(32);      //
    commands[RREMI]=    new cRREMI(32);     //
    commands[RREMC]=    new cRREMC(32);     //
    commands[FAR]=      new cFAR(16);       //с вещественными
    commands[FA]=       new cFA(32);        //
    commands[FAI]=      new cFAI(32);       //
    commands[FSR]=      new cFSR(16);       //
    commands[FS]=       new cFS(32);        //
    commands[FSI]=      new cFSI(32);       //
    commands[RFSR]=     new cRFSR(16);      //
    commands[RFS]=      new cRFS(32);       //
    commands[RFSI]=     new cRFSI(32);      //
    commands[FMR]=      new cFMR(16);       //
    commands[FM]=       new cFM(32);        //
    commands[FMI]=      new cFMI(32);       //
    commands[FDR]=      new cFDR(16);       //
    commands[FD]=       new cFD(32);        //
    commands[FDI]=      new cFDI(32);       //
    commands[RFDR]=     new cRFDR(16);      //
    commands[RFD]=      new cRFD(32);       //
    commands[RFDI]=     new cRFDI(32);      //
    commands[FLOATR]=   new cFLOATR(16);    //Преобразование в вещественное
    commands[FLOAT]=    new cFLOAT(32);     //
    commands[FLOATI]=   new cFLOATI(32);    //
    commands[FIXR]=     new cFIXR(16);      //Преобразование в целое
    commands[FIX]=      new cFIX(32);       //
    commands[FIXI]=     new cFIXI(32);      //
    commands[FLOOR]=    new cFLOOR(32);     //вещественное округление
    commands[CEIL]=     new cCEIL(32);      //
    commands[MIN]=      new cMIN(32);       //минимум
    commands[MAX]=      new cMAX(32);       //максимум
    commands[SHIFTL]=   new cSHIFTL(32);    //Логический сдвиг
    commands[SHIFTC]=   new cSHIFTC(32);    //Циклический сдвиг
    commands[SHIFTA]=   new cSHIFTA(32);    //Арифметический сдвиг
}

int Processor::interpreter(bool debug){
    clear();
    int stoping = 0;
    //Проверка счетчика адреса команд(САК) на четность
    if(psw.getPC()%2!=0){
        log.writeError("Forbidden command address");
        return 0;
    }
    half_word_t byte;
    while(stoping==0){
        try{
            byte=memory.loadByte(psw.getPC())&0b01111111;
            //Зацикливание кода операции
            if(byte==0xFFFE){
                log.writeError("address command: "+std::to_string(psw.getPC())+" opcode loop!");
            }
            //Проверка на корректность кода команды
            if(byte>0x7F){
                log.writeError("address command: "+std::to_string(psw.getPC())+" incorrect command!");
            }
            log.writeMessage("address command: "+std::to_string(psw.getPC())+" command execution: "+std::to_string(byte));
            stoping=commands[byte]->operator ()(*this);
            if(stoping==0)log.writeMessage("command completed");
            psw.setPC(psw.getPC()+commands[byte]->size);
        }
        catch(const vm_error &error){
            log.writeError("address command: "+std::to_string(psw.getPC())+" "+error.what());
            stoping=1;
        }
    }
    return 0;
}


