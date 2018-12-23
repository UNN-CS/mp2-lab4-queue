#include <iostream>
#include "tqueue.h"

TQueue::TQueue(int Size):TStack(Size)
{
	li = -1;
}

int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}

TData TQueue::Get()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else
	{
		li = GetNextIndex(li);
		DataCount--;
		return pMem[li];
	}
}

TData TQueue::TopElem()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else
	{
		return pMem[GetNextIndex(li)];
	}
}