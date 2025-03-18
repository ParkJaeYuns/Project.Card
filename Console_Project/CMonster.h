#pragma once
#include<iostream>
using namespace std;
#include "CPlayer.h"

class CMonster
{
private:
	string mName;
	int mHealth;
	int mAttack;
	int mDefence;

public:
	CMonster();
	CMonster(const string& _name, int _hp, int _atk, int _def);
	~CMonster();


	void SelectMonster(CMonster*& _monster);
	void SelectBossMonster(CMonster*& _monster);
	void PrintInfo()const;
	int GetAttack() const;
	int GetHp() const;
	int GetDefence() const;
	void SetHP(int hp);




};

