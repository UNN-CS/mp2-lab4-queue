#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"
using namespace std;

void simulate(int que_size, int tacts, double q1, double q2);

int main()
{
	simulate(1, 100, 0.5, 0.5);

	return 0;
}

void simulate(int que_size, int tacts, double q1, double q2)
{

	int JobsNumber = 0;
	int CompletedJobs = 0;
	int Queue_Full = 0;
	int FreeTime = 0;
	int UnprocessedJobs = 0;
	TJobStream jobstream(q1);
	TProc proc(q2);
	TQueue q(que_size);

	if (!q.IsValid())
	{
		cout << "Queue is not valid\n";
		return;
	}

	for (int i = 0; i < tacts; i++)
	{


		if (jobstream.IsNewJob())
		{

			JobsNumber++;


			if (q.IsFull())
			{
				Queue_Full++;
			}
			else
			{
				q.Put(jobstream.GetNumberOfJobs());
			}

		}

		if (proc.IsBusy())
		{
			if (proc.JobHasDone())
			{
				proc.SetBusy(false);
				CompletedJobs++;

				if (q.IsEmpty())
				{
					FreeTime++;
				}
				else
				{
					q.Get();
					proc.SetBusy(true);
				}
			}

		}
		else
		{

			if (q.IsEmpty())
			{
				FreeTime++;
			}
			else
			{
				q.Get();
				proc.SetBusy(true);
			}
		}
	}

	while (!q.IsEmpty())
	{
		JobsNumber++;
		UnprocessedJobs++;
		q.Get();
	}

	cout << "Total tacts: " << tacts << endl;
	cout << "Busy tacts: " << tacts - FreeTime << endl;
	cout << "Idle tacts: " << FreeTime << " %: " << (double)FreeTime / tacts * 100 << endl;
	cout << "Total jobs " << JobsNumber << endl;
	cout << "Complete jobs: " << JobsNumber - Queue_Full - UnprocessedJobs << endl;
	cout << "Jobs skipped when queue is full: " << Queue_Full << " %: " << (double)Queue_Full / JobsNumber * 100 << endl;
	cout << "Jobs skipped when have no tacts left: " << UnprocessedJobs << " %: " << (double)UnprocessedJobs / JobsNumber * 100 << endl;
	cout << "Time for 1 job: " << (double)(tacts - FreeTime) / (double)CompletedJobs << " tacts" << endl;

}