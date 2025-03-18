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


	if (mName == "방어" || mName == "철벽" || mName == "방어+" || mName == "철벽+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<방어>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 방어도 : " << setw(8) << left << mAttack << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}

	else if (mName == "참호" || mName == "참호+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<방어>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 방어도 " << setw(10) << left << "x2  " << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}
	
	else if (mName == "찌르기" || mName == "베기" || mName == "단검 투척" || mName == "기습" || mName == "몽둥이질" || mName == "대검"
		|| mName == "찌르기+" || mName == "베기+" || mName == "단검 투척+" || mName == "기습+" || mName == "몽둥이질+" || mName == "대검+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<공격>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 공격력 : " << setw(8) << left << mAttack << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}

	else if (mName == "방패강타" || mName == "방패강타+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<공격>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 공격력 : " << setw(1) << left << mAttack  << "+방어도" << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}

	else if (mName == "혈류" || mName == "혈류+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<공격>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드: " << setw(1) << left << mName << "(hp -5)" <<  "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 공격력 : " << setw(8) << left << mAttack << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}

	else if (mName == "체력회복" || mName == "체력회복+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<회복>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 체력+  : " << setw(8) << left << mAttack << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
	}

	else if (mName == "숨고르기" || mName == "숨고르기+")
	{
		Gotoxy(_x, _y + 1);
		cout << "┌<중립>------------┌ ┐" << endl;
		Gotoxy(_x, _y + 2);
		cout << "| 카드 : " << setw(10) << left << mName << "|" << mCost << "|" << endl;
		Gotoxy(_x, _y + 3);
		cout << "| 코스트 + " << setw(8) << left << mAttack << "└" << " ┘" << endl;
		Gotoxy(_x, _y + 4);
		cout << "└--------------------┘" << endl;
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

	COORD pos = { x,y }; //x, y 좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 설정
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




