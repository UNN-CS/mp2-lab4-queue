#include "tdataroot.h"

class TStack :public TDataRoot
{
protected:
	int Hi; 
	virtual int GetNextIndex(int Index);
public:
	TStack(int Size = DefMemSize) : TDataRoot(Size), Hi(-1) {}
	TStack(const TStack &);
	void Put(const TData &); // �������� � ����
	TData Get(); //����� �� �����
	int  IsValid();
	void Print();
	TData GetTopElem();
};
};