#include "CInventory.h"

CInventory::CInventory() {}

CInventory::~CInventory() {}

void CInventory::AddItem_Inven(CItem* _item)
{
	mInventory.push_back(_item);
}

void CInventory::Show_inven()const
{
	int x = 1;
	int y = 1;
	for (auto& inven : mInventory)
	{
		inven->ShowItem_player(x, y);
		y++;
	}
}

void CInventory::ItemCheck_inven(string _name)
{
	for (auto& inven : mInventory)
	{
		if (inven->GetName() == _name)
		{
			
		}
	}
}

int CInventory::GetinvenSize() const
{
	return mInventory.size();
}

CItem* CInventory::GetInvenItem(const int _index)
{
	return mInventory[_index];
}


