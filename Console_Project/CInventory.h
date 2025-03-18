#pragma once
#include "CItem.h"
#include<vector>

class CInventory
{
public:

	CInventory();
	~CInventory();

	void AddItem_Inven(CItem* _item);
	void Show_inven()const;
	void ItemCheck_inven(string _name);
	int GetinvenSize()const;
	CItem* GetInvenItem(const int _index);


private:
	vector<CItem*> mInventory;
};

