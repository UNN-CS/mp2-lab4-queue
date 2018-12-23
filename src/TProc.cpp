//
// Created by rootreddragon on 12/23/2018.
//

#include "TProc.h"
#include <iostream>

using namespace std;


void TProc::ProcWork()
{

    for (int i = 0; i < m_MaxTact; i++)
    {
        m_JobStream.TactStream();
        if (m_Status == FREE)
        {
            if (m_JobStream.IsEmpty())
                m_CountDowntime++;
            else
            {
                m_JobStream.Get();
                m_Status = BUSY;
            }
        }
        if (m_Status == BUSY)
        {
            double chance = (rand() % 100 / 100.0f);
            if (chance <= m_q2)
                m_Status = FREE;
        }
    }
}

void TProc::PrintInfo()
{
    cout << endl;
    cout << "Number of tasks received by the computing system: " << m_JobStream.m_ID << endl;
    cout << "The number of failures in service jobs due to overflow queue:: " << m_JobStream.m_CountFail << " (" << (double)m_JobStream.m_CountFail / m_JobStream.m_ID * 100 << "%)" << endl;
    cout <<  "The average number of job cycles" << (double)(m_MaxTact - m_CountDowntime) / (m_JobStream.m_ID - m_JobStream.m_CountFail) << endl;
    cout << "CPU idle cycles: " << m_CountDowntime << " (" << double(m_CountDowntime) / m_MaxTact * 100 << "%)" << endl;
}