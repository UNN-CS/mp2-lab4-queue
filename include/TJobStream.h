#pragma once
#include "tdataroot.h"
#include <random>
#include <ctime>

class TJobStream
{
private:
	double boundOfExecution;			//����� ��������� ���������� ���������
	double boundOfTasks;				//����� ��������� ������
	int taskNum;						//������ ������
public:
	TJobStream(double q1, double q2);
	int taskGeneration();				//��������� ������
	int taskWork();						//��������� ���������� ���������
	int getTaskNum();					//����������� ������� ������
};

