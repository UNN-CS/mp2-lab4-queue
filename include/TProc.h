//
// Created by rootreddragon on 12/23/2018.
//

#ifndef LAB_4_TPROC_H
#define LAB_4_TPROC_H
#include <random>
#include <ctime>

using namespace std;
class TProc
        {
private:
    mt19937 generate;                    // генерация значения датчика
    double upper_bound;                       // некое пороговое значение
    bool proc_busy;                           // занятость процессора
public:
    TProc(double q2);                         // конструктор с неким пороговым значением
    bool Tact();                              // такт
    bool GetBusy();                           // получить занятость процессора
    void SetBusy(bool arg);                   // установить занятость процессора
};



#endif //LAB_4_TPROC_H
