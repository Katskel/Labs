//---------------------------------------------------------------------------

#ifndef DequeH
#define DequeH
#include <vcl.h>

struct Node{
	String data;
	Node *next;
	Node *prev;
};

class Deque
{
	private:
		Node *begin_;
		Node *end_;
	public:
		Deque();
		~Deque();
		void PushBack(String data); //�������� � ������ �������
		String front();             //����� �� ����� �������
		void PopFront();            //������� ������� �� ����� �������
		void Clear();               //�������� �������
		void Show(TMemo *memo);     //������� �������� ������� � ��������� TMemo
};
//---------------------------------------------------------------------------
#endif
