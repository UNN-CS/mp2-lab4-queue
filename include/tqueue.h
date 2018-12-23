#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include "tstack.h"

class TQueue : public TStack {
 protected:
 int Li; // ������ ������ �������
 int Hi; //����� �������
 int GetNextIndex (int index); // �������� ��������� ������
public:
 TQueue (int Size = DefMemSize);
 TElem Get () ; // ������� ��������
 void Put(const TData &Val); //�������� ��������
 TElem TopElem ();
};

#endif // __TQUEUE_H__