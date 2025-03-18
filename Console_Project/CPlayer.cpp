#include "CPlayer.h"

CPlayer::CPlayer(const string& name, int hp, int atk, int def, int cost, int maxhp, int gold, PlayerJab _jab)
	:mName(name), mHealth(hp), mDefence(def), mAttack(atk), mCost(cost), mMaxHealth(maxhp), mGold(gold), mJabClass(_jab)
{
	mPlayerinven = new CInventory();
}

CPlayer::~CPlayer()
{
	cout << "소멸자" << endl;
	//delete mPlayerinven;
}

void CPlayer::PrintInfo() const
{
	CCard _card;

	_card.Gotoxy(20, 3);
	cout << "┌---------------------┐" << endl;
	_card.Gotoxy(20, 4);
	cout << "|  클래스 : " << setw(10) << left << mName << "|" << endl;
	_card.Gotoxy(20, 5);
	cout << "|" << setw(20) << left << "                 " << " | " << endl;
	_card.Gotoxy(20, 6);
	cout << "|  체력 : " << setw(6) << left << mHealth << "/ " << mMaxHealth << " |" << endl;
	_card.Gotoxy(20, 7);
	cout << "|  공격력 : " << setw(10) << left << mAttack << "|" << endl;
	_card.Gotoxy(20, 8);
	cout << "|  방어력 : " << setw(10) << left << mDefence << "|" << endl;
	_card.Gotoxy(20, 9);
	cout << "└---------------------┘" << endl;


}

int CPlayer::GetHealth() const
{
	return mHealth;
}

int CPlayer::GetAttack() const
{
	return mAttack;
}

int CPlayer::GetDefence() const
{
	return mDefence;
}

int CPlayer::GetCost() const
{
	return mCost;
}

int CPlayer::GetMaxHealth() const
{
	return mMaxHealth;
}

int CPlayer::GetGold() const
{
	return mGold;
}

CInventory* CPlayer::GetInven() const
{
	return mPlayerinven;	
}

string CPlayer::GetName() const
{
	return mName;
}

void CPlayer::SetHealth(int setHp)
{
	this->mHealth = setHp;
}

void CPlayer::SetAttack(int setAtk)
{
	this->mAttack = setAtk;
}

void CPlayer::SetDefence(int setdef)
{
	this->mDefence = setdef;
}

void CPlayer::SetCost(int setcost)
{
	this->mCost = setcost;
}

void CPlayer::SetMaxHealth(int setmaxhp)
{
	this->mMaxHealth = setmaxhp;
}

void CPlayer::SetGold(int setgold)
{
	this->mGold = setgold;
}

void CPlayer::TakeDamage_player(int _damage)
{
	if (_damage > GetDefence()) 
	{
		SetHealth(GetHealth() - (_damage - GetDefence()));
		SetDefence(0);
	}

	else if (_damage < GetDefence())
	{
		SetDefence(GetDefence() - _damage);
	}

}

PlayerJab CPlayer::GetJabClass() const
{
	return mJabClass;
}

void CPlayer::SelectCharacter(CPlayer*& _player)
{
	int Playerinput;
	CCard _card;

	_card.Gotoxy(55, 8);
	cout << "[클래스 선택]" << endl;

	// └───────┘ , ┌───────┐

	// 전사
	_card.Gotoxy(39, 10);
	cout << "┌───────<전사>───────┐" << endl;
	_card.Gotoxy(39, 11);
	cout << "|  체력 : " << setw(11) << left <<  "100" <<  "|" << endl;
	_card.Gotoxy(39, 12);
	cout << "|  방어력 : " << setw(9) << left << "0" << "|" << endl;
	_card.Gotoxy(39, 13);
	cout << "|  특성 : " << setw(8) << left << "방어력 + 5" << " |" << endl;
	_card.Gotoxy(39, 14);
	cout << "└────────────────────┘" << endl;

	// 도적
	_card.Gotoxy(61, 10);
	cout << "┌───────<도적>───────┐" << endl;
	_card.Gotoxy(61, 11);
	cout << "|  체력 : " << setw(11) << left << "80" << "|" << endl;
	_card.Gotoxy(61, 12);
	cout << "|  방어력 : " << setw(9) << left << "0" << "|" << endl;
	_card.Gotoxy(61, 13);
	cout << "|  특성 : " << setw(8) << left << "공격력 + 5" << " |" << endl;
	_card.Gotoxy(61, 14);
	cout << "└────────────────────┘" << endl;


	_card.Gotoxy(50, 16);
	cout << " (1). 전사  (2). 도적 " << endl;
	_card.Gotoxy(60, 17);
	cin >> Playerinput;
	

	switch (Playerinput)
	{
	case 1:
		_card.Gotoxy(50, 19);
		cout << "[클래스 선택 - 전사]" << endl;
		// 타격5, 수비4, 강타1
		_player = new CPlayer("전사" , 100, 0, 5, 3, 100, 0, PlayerJab::WARRIOR);
		break;

	case 2:
		_player = new CPlayer("도적", 80, 5, 0, 3, 80, 0, PlayerJab::ROGUE);
		// 특능 : 두번공격 , 공격력 +5 추가
		break;

	default:
		break;
	}
}

void CPlayer::Show_PlayerInven()
{
	mPlayerinven->Show_inven();
}
