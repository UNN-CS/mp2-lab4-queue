#pragma once
#include "tstack.h"

class TQueue : public TStack
{
private:
	int lowIndex;						//������ ������
	int highIndex;						//������� ������
public:
	TQueue(int size);
	virtual void Put(int val);			//���������� ��-��
	virtual int Get();					//�������� ��-��
	int GetNextIndex(int val);			//��������� ����. �������
};

