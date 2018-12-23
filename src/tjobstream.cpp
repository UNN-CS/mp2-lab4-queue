#include "tjobstream.h"
#include <iostream>

using namespace std;

TJobStream::TJobStream(double q) : q1(q){}

bool TJobStream::IsNewJob()
{
	double q = (rand() / (double)(RAND_MAX + 1));

	if (q <= q1)
	{
		job_number++;

		return true;
	}
	else
	{
		return 0;
	}
		
}

int TJobStream::GetNumberOfJobs() const
{
	return job_number;
}