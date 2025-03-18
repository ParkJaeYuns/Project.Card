#include "CMonster.h"

CMonster::CMonster() : mName(" "), mHealth(0), mDefence(0), mAttack(0)
{

}

CMonster::CMonster(const string& _name, int _hp, int _atk, int _def)
	: mName(_name), mHealth(_hp), mAttack(_atk), mDefence(_def) {}

CMonster::~CMonster() {}


void CMonster::SelectMonster(CMonster*& _monster)
{
	//CMonster* Monster = nullptr;
	srand(unsigned(time(NULL)));
	switch (1 + rand() % 4)
	{
	case 1:
		_monster = new CMonster("�꼺 ������", 69, 5, 0); //69

		break;
	case 2:
		_monster = new CMonster("���ŵ�", 84, 7, 0); // 84

	case 3:
		_monster = new CMonster("�뿹����", 79, 6, 0); // 79
		break;

	case 4:
		_monster = new CMonster("����", 68, 6, 0); // 68
		break;

	default:
		break;
	}

}

void CMonster::SelectBossMonster(CMonster*& _monster)
{
	switch (1 + rand() % 2)
	{
	case 1:
		_monster = new CMonster("���� �׷���", 98, 10, 0); // (98)
		break;
	case 2:
		_monster = new CMonster("����", 111, 10, 0); //(111)
		break;

	default:
		break;
	}
}


void CMonster::PrintInfo()const
{
	CCard _card;

	_card.Gotoxy(70, 5);
	cout << "��-------------------��" << endl;
	_card.Gotoxy(70, 6);
	cout << "|    " << setw(12) << left << mName << "   |" << endl;
	_card.Gotoxy(70, 7);
	cout << "|" << setw(16) << left << "                  " << " | " << endl;
	_card.Gotoxy(70, 8);
	cout << "|    ü�� : " << setw(7) << left << mHealth << " |" << endl;
	_card.Gotoxy(70, 9);
	cout << "��-------------------��" << endl;;


}

int CMonster::GetAttack() const
{
	return mAttack;
}

int CMonster::GetHp() const
{
	return mHealth;
}

int CMonster::GetDefence() const
{
	return mDefence;
}

void CMonster::SetHP(int hp)
{
	this->mHealth = hp;
}

