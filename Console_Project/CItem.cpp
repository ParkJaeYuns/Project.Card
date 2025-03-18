#include "CItem.h"

CItem::CItem(CItem* _item)
{
}

CItem::CItem(string _name, int _atk, int _def, int _price, int _maxhp, string _Effect)
	: mItemName(_name), mItemAttack(_atk), mItemDefence(_def), mItemPrice(_price), mItemMaxHealth(_maxhp), mItemEffect(_Effect)
{
}

CItem::~CItem()
{
}

string CItem::GetName()const
{
	return mItemName;
}

int CItem::GetAttack()const
{
	return mItemAttack;
}

int CItem::GetPrice()const
{
	return mItemPrice;
}

int CItem::GetDefence() const
{
	return mItemDefence;
}

int CItem::GetMaxHealth() const
{
	return mItemMaxHealth;
}

void CItem::SetAttack(int _Attack)
{
	this->mItemAttack = _Attack;
}

void CItem::SetPrice(int _Price)
{
	this->mItemPrice = _Price;
}

void CItem::SetDefence(int _Defence)
{
	this->mItemDefence = _Defence;
}

void CItem::SetMaxhealth(int _MaxHealth)
{
	this->mItemMaxHealth = _MaxHealth;
}

void CItem::ShowItme(int _x, int _y)
{
	//忙式式式式式式式忖戌式式式式式式式戎

	CCard* card = nullptr;
	card->Gotoxy(_x, _y);
	cout << "忙式式式式式式式[ $"<< mItemPrice <<" ]忖" << endl;
	card->Gotoxy(_x, _y+1);
	cout << "弛  " << setw(9) << left << mItemName << "  弛" << " - " << mItemEffect << endl;
	card->Gotoxy(_x, _y+2);
	cout << "戌式式式式式式式式式式式式式式戎" << endl;
}

void CItem::ShowItem_player(int _x, int _y)
{
	CCard* card = nullptr;
	card->Gotoxy(_x, _y);
	cout << "[ " << mItemName << " ]" << endl;
}
