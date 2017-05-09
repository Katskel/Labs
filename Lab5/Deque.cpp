//---------------------------------------------------------------------------


#pragma hdrstop

#include "Deque.h"

void Deque::PopFront()
//удалить элемент из конца очереди
{
	if(end_ -> prev) {
		end_ = end_ -> prev;
		delete end_ -> next;
		end_ -> next = NULL;
	}
	else {
		begin_ = end_ = NULL;
		delete end_;
	}
}

String Deque::front()
//взять из конца очереди
{
	return end_ -> data;
}

void Deque::PushBack(String data)
//вставить в начало очереди
{
	Node *item = new Node();
	item -> data = data;
	if(!begin_) {
		begin_ = end_ = item;
		item -> prev = item -> next = NULL;
	}
	else {
		item -> next = begin_;
		item -> prev = NULL;
		begin_ -> prev = item;
		begin_ = item;
	}
}

Deque::Deque()
{
	begin_ = end_ = NULL;
}

Deque::~Deque()
{
	this->Clear();
}

void Deque::Clear()
//очистить очередь
{
	Node *iterator = begin_;
	Node *temp;
	while(iterator) {
		temp = iterator;
		iterator = iterator -> next;
		delete temp;
	}
}

void Deque::Show(TMemo* memo)
//вывести элементы очереди в компонент TMemo
{
	Node *iterator = end_;
	while(iterator) {
		memo -> Lines -> Add(iterator -> data);
		iterator = iterator -> prev;
	}
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
