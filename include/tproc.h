#pragma once
#include <random>
#include <ctime>

class TProc {
private:
	std::mt19937 generate;                    // ��������� �������� �������
	double upper_bound;                       // ����� ��������� ��������
	bool proc_busy;                           // ��������� ����������
public:
	TProc(double q2);                         // ����������� � ����� ��������� ���������
	bool Tact();                              // ����
	bool GetBusy();                           // �������� ��������� ����������
	void SetBusy(bool arg);                   // ���������� ��������� ����������
};

