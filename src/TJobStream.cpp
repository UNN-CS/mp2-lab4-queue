//
// Created by rootreddragon on 12/23/2018.
//

#include "TJobStream.h"

using namespace std;


TJobStream::TJobStream(double q1) :task_number(0)
{
    upper_bound = q1;
    generate_value = mt19937(time(0) + 1);
}

int TJobStream::Tact()
{
    if (uniform_real_distribution<double> {0, 1} (generate_value) < upper_bound)
        return ++task_number;
    else
        return 0;
}