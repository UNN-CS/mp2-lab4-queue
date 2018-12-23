//
// Created by rootreddragon on 12/23/2018.
//

#include "TQueue.h"


#include "iostream"

using namespace std;

TQueue::TQueue(int Size) :TStack(Size)
{
    Li = 0;
    Hi = 0;
}

int TQueue::GetNextIndex(int index)
{
    index++;
    return index % MemSize;
}

void TQueue::Put(const TData& val) {
    if (pMem == 0) SetRetCode(DataNoMem);
    else if (IsFull()) SetRetCode(DataFull);

    {
        pMem[Hi] = val;
        Hi = GetNextIndex(Hi);
        DataCount++;
    }
}

TData TQueue::Get()
{
    TData tmp = -1;
    if (pMem == 0) SetRetCode(DataNoMem);
    else if (IsEmpty()) SetRetCode(DataEmpty);
    else
    {
        tmp = pMem[Li];
        Li = GetNextIndex(Li);
        DataCount--;
    }
    return tmp;
}


TData TQueue:: GetTopElem()

{
    TData tmp = -1;
    if (pMem == 0) SetRetCode(DataNoMem);
    else if (IsEmpty()) SetRetCode(DataEmpty);
    else tmp = pMem[Li];
    return tmp;
}

void TQueue::GetNextIndex()
{
    int k = DataCount;
    for (int i = Li; i == Hi, k != 0; i = GetNextIndex(i))
    {
        k--;
        cout << pMem[i] << " ";
    }
    cout << endl;
}