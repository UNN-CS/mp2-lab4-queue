#ifndef __TJOBSTREAM_H__
#define __TJOBSTREAM_H__

class TJobStream {
 private:
 double JobInt�ns; // ������������� ������ �����
 public:
 TJobStream (double Int�ns);
 int GetNewJob(void); // ��������� ������ �������
};

#endif // __TJOBSTREAM_H__