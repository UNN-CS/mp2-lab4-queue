#include "tjobstream.h"
#include <stdlib.h>
#include <random>
#include <iostream>

using namespace std;

class  TProc : protected TJobStream
{
protected:
	float q2;
	unsigned long int tactNum; // êîëè÷åñòâî òàêòîâ
	unsigned long int completedTactNum; // êîëè÷åñòâî âûë=ïîëíåíûõ êîìàíä
	float averTuctNumToComplete; // ñðåäíåå ÷èñëî òàêòîâ äëÿ âûïîëíåíèÿ
	unsigned long int idleNum; // êîëè÷åñòâî òàêòîâ ïðîñòîÿ
public:
	TProc(int lenght);
	bool TryToComplete();
	void Report();
	void CPUSim(float m1, float m2, unsigned long int tNum);
	void SetQ2(float x);
};
