#include <iostream>
#include "tstack.h"

TStack::TStack(int Size):TDataRoot(Size)
{
	hi = -1;
}

int TStack::GetNextIndex(int index)
{
	return ++index;
}

void TStack::Put(const TData &Val)
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
		
	}
	else if (IsFull())
	{
		SetRetCode(DataFull);
	}
	else
	{
		hi = GetNextIndex(hi);
		pMem[hi] = Val;
		DataCount++;
	}
}



TData TStack::Get()
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
		DataCount--;
		return pMem[hi--];
	}
}

TData TStack::TopElem()
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
		return pMem[hi];
	}
}

int TStack::IsValid()
{
	return GetRetCode() == DataOK ? true : false;
}

void TStack::Print()
{
	for (int i = 0; i < DataCount; ++i)
	{
		std::cout << pMem[i] << " ";
	}
	std::cout << std::endl;
}
