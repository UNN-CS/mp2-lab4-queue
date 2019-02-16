#pragma once
#include <random>
#include <ctime>

class TJobStream
{
private:
	std::mt19937 generate_value;             // ��������� �������� �������
	double upper_bound;                      // ����� ��������� ��������
	int task_number;                         // ������ �������
public:
	TJobStream(double q1);                   // ����������� � ����� ��������� ���������
	int Tact();                              // ����
};

