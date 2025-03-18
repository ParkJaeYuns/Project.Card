#pragma once
#include<iostream>
using namespace std;
#include"CCard.h"
#include "CInventory.h"

class CPlayer
{
private:

	string mName;
	int mHealth;
	int mMaxHealth;
	int mDefence;
	int mAttack;
	int mCost;
	int mGold;
	PlayerJab mJabClass = PlayerJab::NONE;
	CInventory* mPlayerinven;
	//CCard card;

public:

	CPlayer(const string& name, int hp, int atk, int def, int cost, int maxhp, int gold, PlayerJab _jab);
	~CPlayer();
	void PrintInfo()const;
	void SelectCharacter(CPlayer*& _player);
	void Show_PlayerInven();
	

public:
	string GetName()const;
	int GetHealth()const;
	int GetAttack()const;
	int GetDefence()const;
	int GetCost()const;
	int GetMaxHealth()const;
	int GetGold()const;
	CInventory* GetInven()const;

public:
	void SetHealth(int setHp);
	void SetAttack(int setAtk);
	void SetDefence(int setdef);
	void SetCost(int setcost);
	void SetMaxHealth(int setmaxhp);
	void SetGold(int setgold);
	void TakeDamage_player(int _damage);
	PlayerJab GetJabClass()const;


};