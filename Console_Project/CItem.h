#pragma once
#include <iostream>
#include "CCard.h"
using namespace std;


class CItem
{
public:
	CItem(CItem* _item);
	CItem(string _name, int _atk, int _def, int _price, int _maxhp, string _Effect);
	~CItem();

	string GetName()const;
	int GetAttack()const;
	int GetPrice()const;
	int GetDefence()const;
	int GetMaxHealth()const;

	void SetAttack(int _Attack);
	void SetPrice(int _Price);
	void SetDefence(int _Defence);
	void SetMaxhealth(int _MaxHealth);

	void ShowItme(int _x, int _y);
	void ShowItem_player(int _x, int _y);



private:
	string mItemName;
	int mItemAttack;
	int mItemDefence;
	int mItemPrice;
	int mItemMaxHealth;
	string mItemEffect;
};

