#include "tstack.h"

TStack::TStack(int Size) : TDataRoot(Size)
{
	this->Hi = this->DataCount - 1;
}

int TStack::GetHi()
{
	return Hi;
}

TStack::~TStack()
{}

int TStack::GetNextIndex(int index)
{
	return ++index % MemSize;
}

void TStack::Put(const TData& Val)
{
	if (GetRetCode() != DataOK)
	{
		SetRetCode(DataErr);
		return;
	}
	if (this->IsFull())
	{
		TDataCom::SetRetCode(DataFull);
		return;
	}
		
	Hi = GetNextIndex(Hi);
	this->pMem[Hi] = Val;
	this->DataCount++;
	TDataCom::SetRetCode(DataOK);
}

TData TStack::Get()
{
	if (GetRetCode() != DataOK)
	{
		SetRetCode(DataErr);
		return NULL;
	}
	if (this->IsEmpty())
	{
		TDataCom::SetRetCode(DataEmpty);
		return -1;
	}
	this->DataCount--;
	TDataCom::SetRetCode(DataOK);
	return this->pMem[Hi--];
}

TData& TStack::operator[](int i)
{
	if (i < 0 || i >= this->DataCount)
		TDataCom::SetRetCode(DataErr);
	TDataCom::SetRetCode(DataOK);
	return this->pMem[i];
}

int TStack::IsValid()
{
	if (GetRetCode() != DataOK)
	{
		SetRetCode(DataErr);
		return -1;
	}
	if (this->DataCount > this->MemSize) return -1;
	if ((this->DataCount < this->MemSize) && (this->IsFull())) return -1;
	if ((this->DataCount == 0) && (!this->IsEmpty())) return -1;
	if (this->DataCount < 0) return -1;
	return 0;
}

void TStack::Print()
{
	for (int i = this->DataCount - 1; i >= 0; i--)
		std::cout << this->pMem[i] << " ";
}
