#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

int main () {
	TJobStream job (0.2);
    TProc proc (0.5);
    TQueue q (3);
	int tact_imitation = 100;
	int idle_tact = 0, busy_tact = 0, all_tasks = 0, completed_tasks = 0, unfinished_tasks = 0;
	for (int tact = 0; tact < tact_imitation; tact ++)
	{
		int task = job.GetNewJob(); //�������� id ������
		int start = proc.RunNewJob(task); //��������� ����� ���������
		int current_task = 0;

		if ((proc.IsProcBusy())&&(start)) { //��������� ����� � �����
			proc.SetBusy(false);
		}
		if ((!proc.IsProcBusy())&&(start)) { //��������� ����� � �� �����
			if (!q.IsEmpty())
			{
				current_task = task; //���������� ������� ������
				task = q.Get(); //�������� �� ������� ������ ������
				proc.SetBusy(true); //��������� ����� ������� �� �������
				completed_tasks++; //��������� ��� ���� ������
				if (current_task > 0) { 
					if (!q.IsFull()) 
						q.Put(current_task);
					all_tasks++;
				}
			}
			else if (task>0) { //���� ������� �����, �� ������ ����������
				proc.SetBusy(true); //��������� ����� ���� �������
				completed_tasks++; //��������� ��� ���� ������
				all_tasks++;
			}
		}
		if ((!start)&&(task>0)) {//��������� �� �����, �� ������ ����
			if (!q.IsFull()) 
				q.Put(current_task);
			else unfinished_tasks++;
			all_tasks++;
		}
		if (proc.IsProcBusy()) 
			busy_tact++;
		else 
			idle_tact++;
	}
	while (!q.IsEmpty()) {
		q.Get();
		unfinished_tasks++;
	}
	cout<<"Total tasks for "<<tact_imitation<<" tacts: "<<all_tasks<<endl;
	cout<<"Completed tasks for "<<tact_imitation<<" tacts: "<<completed_tasks<<endl;
	cout<<"Unfinished tasks for "<<tact_imitation<<" tacts: "<<unfinished_tasks<<endl;
	cout<<"Idle tacts of "<<tact_imitation<<" tacts: "<<idle_tact<<endl;
	cout<<"Busy tacts of "<<tact_imitation<<" tacts: "<<busy_tact<<endl;

	return 0;
}