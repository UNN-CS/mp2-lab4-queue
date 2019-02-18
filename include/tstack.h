#pragma once
#include "tdataroot.h"

class TStack :public TDataRoot
{
private:
	int top;
public:
	TStack(int Size = DefMemSize);
	TStack(const TStack & a);
	void Put(const TData &Val);
	TData Get();
	virtual TData TopElem();

	int IsValid();
	void Print();
};

