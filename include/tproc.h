#ifndef __TPROC_H__
#define __TPROC_H__

class TProc {
 private:
 double ProcRate; // ������������������ ����������
 int JobId; // Id ������������ �������
 int Busy;
 public:
 TProc (double Rate);
 int IsProcBusy(void) ; // ��������� �����?
 void SetBusy (bool status);
 int RunNewJob (int JobId); // ���������� � ���������� ������ �������
};

#endif // __TPROC_H__