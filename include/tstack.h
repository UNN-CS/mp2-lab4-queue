#include "tdataroot.h"

class TStack :public TDataRoot
{
private:
	int hi; 
public:
    TStack(int Size = DefMemSize);
    ~TStack() {};
	void Put(const TData &Val); 
	virtual TData Get();
	virtual TData TopElem(); 
	virtual int GetNextIndex(int index);

	int IsValid();
    virtual void Print();
};