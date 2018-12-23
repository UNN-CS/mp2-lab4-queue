#include "tstack.h"

class TQueue : public TStack
{
	int li;
	int GetNextIndex(int index);
public:
	TQueue(int Size);
	TData Get();
	TData TopElem();
	//void Print();
};