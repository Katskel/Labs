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
		void PushBack(String data); //вставить в начало очереди
		String front();             //взять из конца очереди
		void PopFront();            //удалить элемент из конца очереди
		void Clear();               //очистить очередь
		void Show(TMemo *memo);     //вывести элементы очереди в компонент TMemo
};
//---------------------------------------------------------------------------
#endif
