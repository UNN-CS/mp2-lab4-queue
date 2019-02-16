#include <iostream>

#include "tjobstream.h"

#include "tproc.h"

#include "tqueue.h"

void ProcSimulate(double q1, double q2, int all_tacts, int queue_size);

int main()

{

ProcSimulate(.5, .1, 1500000, 5);

return 0;

}

void ProcSimulate(double q1, double q2, int all_tacts, int queue_size)

{

setlocale(0, "rus");

TJobStream job_stream(q1);

TProc proc(q2);

TQueue task_queue(queue_size);

int total_tasks = 0, skipped_tasks = 0, complete_tasks = 0;

int complete_tacts = 0, busy_tacts = 0;

int curr_task = 0;

for (int tact = 0; tact < all_tacts; ++tact)

{

bool completed = proc.Tact();

int number_task = job_stream.Tact();

if (completed)

{

if (proc.GetBusy())

++complete_tasks;

proc.SetBusy(false);

}

if (number_task)

{

++total_tasks;

if (!task_queue.IsFull())

task_queue.Put(number_task);

else
	++skipped_tasks;

}

if (!proc.GetBusy())

{

if (!task_queue.IsEmpty())

{

curr_task = task_queue.Get();

proc.SetBusy(true);

}

busy_tacts++;

}

else

complete_tacts++;

}

std::cout << "Всего тактов: " << all_tacts << std::endl;

std::cout << "Количество тактов простоя: " << busy_tacts << std::endl;

std::cout << "Количество выполненных тактов: " << complete_tacts << std::endl;

std::cout << "Всего заданий: " << total_tasks << std::endl;

std::cout << "Выполненные задания: " << complete_tasks << std::endl;

std::cout << "Пропущенные задания: " << skipped_tasks << std::endl;

}