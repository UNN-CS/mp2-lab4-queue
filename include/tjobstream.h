#include "tqueue.h"
#include <stdlib.h>
#include <time.h>

class TJobStream : protected TQueue
{
protected:
	float q1; // âåðîÿòíîñòü ïîÿâëåíèÿ íîâîé êîìàíäû
	unsigned long int failAddNum; // êîëè÷åñòâî îòêàçîâ
	unsigned long int comandToDoNum;// êîëè÷åñòâî ïîñòóïèâøèõ êîìàíä
	
	default_random_engine generator;
	uniform_real_distribution<double> distribution;
	
public:
	TJobStream(int lenght);
	bool TryToAdd(int n);
	void SetQ1(float x);
};
