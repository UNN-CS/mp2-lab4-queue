#include "tdataroot.h"
#include "tqueue.h"
#include "TJobStream.h"

class TProc
{
private:
	int tactsOfWork;						//����� ������
	int tactsOfFree;						//����� �������
public:
	TProc();
	int GetCountOfWorkTacts();				//������� ���-�� ������ ������
	int GetCountOfFreeTacts();				//������� ���-�� ������ �������
	void BusynessOfProc(TQueue &queue);	//�������� �� ���������
};


