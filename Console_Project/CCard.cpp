#include"CCard.h"

void CCard::Print()
{
	cout << "[ " << mName << " ] " << endl;
}

void CCard::PrintDeck_Used(int _x, int _y)
{
	Gotoxy(_x, _y + 1);
	cout << "[ " << mName << " ] " << endl;
}

void CCard::PrintDraw(int _x, int _y)
{


	if (mName == "���" || mName == "ö��" || mName == "���+" || mName == "ö��+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<���>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| �� : " << setw(8) << left << mAttack << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}

	else if (mName == "��ȣ" || mName == "��ȣ+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<���>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| �� " << setw(10) << left << "x2  " << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}
	
	else if (mName == "���" || mName == "����" || mName == "�ܰ� ��ô" || mName == "���" || mName == "��������" || mName == "���"
		|| mName == "���+" || mName == "����+" || mName == "�ܰ� ��ô+" || mName == "���+" || mName == "��������+" || mName == "���+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<����>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| ���ݷ� : " << setw(8) << left << mAttack << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}

	else if (mName == "���а�Ÿ" || mName == "���а�Ÿ+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<����>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| ���ݷ� : " << setw(1) << left << mAttack  << "+��" << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}

	else if (mName == "����" || mName == "����+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<����>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī��: " << setw(1) << left << mName << "(hp -5)" <<  "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| ���ݷ� : " << setw(8) << left << mAttack << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}

	else if (mName == "ü��ȸ��" || mName == "ü��ȸ��+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<ȸ��>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| ü��+  : " << setw(8) << left << mAttack << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}

	else if (mName == "������" || mName == "������+")
	{
		Gotoxy(_x, _y + 1);
		cout << "��<�߸�>------------�� ��" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| ī�� : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| �ڽ�Ʈ + " << setw(8) << left << mAttack << "��" << " ��" << endl;
		Gotoxy(_x, _y + 4);
		cout << "��--------------------��" << endl;
	}


}

string CCard::GetName()const
{
	return mName;
}

int CCard::GetAttack()const
{
	return mAttack;
}

int CCard::GetCost()const
{
	return mCost;
}

void CCard::SetName(string _name)
{
	this->mName = _name;
}

void CCard::SetAttack(int a)
{
	this->mAttack = a;
}

void CCard::Gotoxy(short x, short y)
{

	COORD pos = { x,y }; //x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� ����
}

PlayerJab CCard::GetJab() const
{
	return mJab;
}

CCard::CCard()
{
}

CCard::CCard(const string& _name, int _atk, int _cost, PlayerJab _jab )
	: mName(_name), mAttack(_atk), mCost(_cost), mJab(_jab) {}

CCard::CCard(const string& _name, int _atk, int _cost)
	: mName(_name), mAttack(_atk), mCost(_cost)
{
	mJab = PlayerJab::NONE;
}

CCard::CCard(CCard* _card)
{
	mName = _card->mName;
	mAttack = _card->mAttack;
	mCost = _card->mCost;
}

CCard::~CCard() {}




