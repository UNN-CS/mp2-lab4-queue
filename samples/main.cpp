#include "tqueue.h"
#include "TProc.h"
#include <ctime>
using namespace std;


void test(int qsize,double q1,double q2,int tacts)
{
	int num, count = 0, ref = 0, ok = 0, downtime = 0;
	TQueue q(qsize);
	TJobStream js(q1);
	TProc pr(q2);
	int p1 = (1 / js.GetQ1()), p2 = (1 / pr.GetQ2());

	for (int i = 0, t1 = 0, t2 = 0; i < tacts; i++, t1++, t2++)
	{
		if (t1%p1 == 0)
		{
			num = js.GetNewJob();
			if (num != 0)
			{
				count++;
				q.Put(num);
				if (q.GetRetCode() == DataFull) ref++;
			}
		}

		if (t2%p2 == 0)
		{
			if (!pr.IsProcBusy())
			{
				q.Get();
				if (q.GetRetCode() == DataEmpty) downtime++;
				else ok++;
			}
		}

	}

	setlocale(LC_ALL, "Russian");
	cout << "��������� ������:" << endl;
	cout << "������������� ������ ������� = " << q1 << endl;
	cout << "������������������ ���������� �������������� ������� = " << q2 << endl;
	cout << "������ ������� �������� = " << qsize << endl;
	cout << "����� ����� ������ ������ ���������� = " << tacts << endl << endl;
	cout << "�������� ������:" << endl;
	cout << "���������� ����������� � �������������� ������� ������� � ������� ����� �������� �������� = " << count << endl;
	cout << "����� ���������� ����������� ������� = " << ok<<endl;
	cout << "���������� ������� � ������������ ������� ��-�� ������������ ������� = " << (double)ref / count * 100 << "%" << endl;
	cout << "���������� ������ ������� ���������� ��-�� ���������� � ������� ������� ��� ������������ = " << ((double)downtime / tacts) * 100 << "%" <<endl<<endl<<endl;
}

int main()
{
	srand(time(0));

	int size = 10; //������ ������� ��������
	int t = 1000; //����� ����� ������ ������ ����������
	double q = 0.5; //������������� ������ �������
	double Q = 0.5; //������������������ ���������� �������������� �������
	test(size, q, Q, t);

	q = 0.5; Q = 0.2;
	test(size, q, Q, t);

	q = 0.2; Q = 0.5;
	test(size, q, Q, t);

	return 0;
}