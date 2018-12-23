//
// Created by rootreddragon on 12/23/2018.
//

#ifndef LAB_4_TJOBSTREAM_H
#define LAB_4_TJOBSTREAM_H

#include <random>
#include <ctime>

using namespace std;

class TJobStream
{
private:
    mt19937 generate_value;             // генерация значения датчика
    double upper_bound;                      // некое пороговое значение
    int task_number;                         // индекс задания
public:
    TJobStream(double q1);                   // конструктор с неким пороговым значением
    int Tact();                              // такт
};





#endif //LAB_4_TJOBSTREAM_H
