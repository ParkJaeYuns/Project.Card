#pragma once
#include"CItem.h"
#include"CPlayer.h"
class CStore
{
public:
	CStore(CPlayer* _player);
	~CStore();

	void Store_list();
	void BuyItem();
	void FindItem(string _Iname);



private:
	vector<CItem*> mStore;
	CPlayer* mPlayer;

};

