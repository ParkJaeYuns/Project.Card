#include "CMonster.h"
#include "CCardDB.h"
#include "CStore.h"
#include <Windows.h>
#include <algorithm>
#include <random>


#pragma once
class Battle
{
public:
	Battle();
	~Battle();

	//vector<CCard*>& _draw, vector<CCard*>& _playerDeck , vector<CCard*>& _usedcard
	void BattleStart(CPlayer*& _player);
	void TakeDamage_monster(const int _Atk);
	void DrawCard();
	void SelectUsingCard(int a, vector<CCard*>& _card, CPlayer*& _player);
	void printDrawCard();
	void PrintDeckCard();
	void Monster_Reward(CPlayer*& _player, int _count);
	void PrintBattleMap();
	void SelectCharacter_Card(CPlayer*& _player);
	void FirstChoice(CPlayer*& _player);
	void Show_Store(CPlayer*& _player);
	int UsedItem(CPlayer*& _player, int _bool);
	
	//void PrintBattle(CPlayer* __Player, CMonster* __Monster);

private:
	CMonster* mMonster = nullptr;
	vector<CCard*> mJabDeck;
	vector<CCard*> mPlayerDeck;
	vector<CCard*> mUsedCard;
	vector<CCard*> mDraw;
	CCard* card = nullptr;
	CCardDB* mCardDB;
	CStore* Store;
	

};

