//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Deque.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Deque *newDeque;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
//�������� ��������� ����, ���� ������, �� ������� � memo � ������ ������� �� �����
{
	String path;
	if(OpenFileDialog -> Execute()) {
		path = OpenFileDialog -> FileName;
		Memo1 -> Lines -> LoadFromFile(path);
		newDeque -> Clear();
		int linesCount = Memo1 -> Lines -> Count;
		for(int i = 0; i < linesCount; i++)
			newDeque -> PushBack(Memo1 -> Lines -> Strings[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
//������ �������, ��������� ����������
{
	delete newDeque;
	Application -> Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
// ������ ������ ������ Deque
{
	newDeque = new Deque();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
//��������� �������
{
	Memo1 -> Clear();
	String data = newDeque -> front();
	newDeque -> PopFront();
	newDeque -> PushBack(data);
	newDeque -> Show(Form1 -> Memo1);
}
//---------------------------------------------------------------------------


