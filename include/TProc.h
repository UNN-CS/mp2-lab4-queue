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
    mt19937 generate;
    double upper_bound;
    bool TProc_busy;
public:
   TProc(double q2);
    bool Tact();
    bool IsComplete();
    bool Ready();
   bool IsEmpty();
    bool Busy();
    SetBusy(bool arg);
    void SetBusy(bool arg);
};



#endif //LAB_4_TPROC_H
