#include <iostream>
#include "tproc.h"


using namespace std;

TProc::TProc(double q) :q2(q) {}

const bool TProc::IsBusy()
{
	return isBusy;
}

void TProc::SetBusy(const bool b)
{
	isBusy = b;
}


bool TProc::JobHasDone()
{
	double q = (rand() / (double)(RAND_MAX + 1));

	if (q <= q2)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}