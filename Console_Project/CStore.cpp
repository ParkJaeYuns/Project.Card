#include "CStore.h"

CStore::CStore(CPlayer* _player)
{
	mPlayer = _player;
}

CStore::~CStore()
{
	for (auto& store : mStore)
	{
		delete store;
	}
}

void CStore::Store_list()
{
	mStore.push_back(new CItem("오리하르콘", 0, 4, 50, 0, "매 플레이어턴마다 방어도 +4")); // 매 플레이어 턴때 방어도 + 3
	mStore.push_back(new CItem("고기덩어리", 6, 0, 50, 0, "전투 종료 시 만약 플레이어 체력이 50% 이하면 체력 +6"));	 // 전투 종료 시 체력이 50% 이하일 시 체력 6 회복
	mStore.push_back(new CItem("신선한심장", 0, 0, 50, 10, "최대체력 +10"));	  // 최대체력 + 10
}

void CStore::BuyItem()
{
	CCard card;

	string input;

	while (true)
	{
		system("cls");

		card.Gotoxy(40, 7);
		cout << "================< 상점 >================" << endl;

		card.Gotoxy(23, 9);
		cout << "┌────────────────────────────────────────────────────────────────────────────┐" << endl;
		card.Gotoxy(23, 10);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 11);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 12);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 13);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 14);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 15);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 16);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 17);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 18);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 19);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 20);
		cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    │" << endl;
		card.Gotoxy(23, 21);
		cout << "└────────────────────────────────────────────────────────────────────────────┘" << endl;

		int x = 25;
		int y = 11;

		for (auto& Store : mStore)
		{
			Store->ShowItme(x, y);
			y += 3;
		}

		card.Gotoxy(45, 22);
		cout << "소지금 - " << mPlayer->GetGold() << endl;
		card.Gotoxy(28, 23);
		cout << "구매하려는 아이템의 이름을 입력하세요 ( 상점닫기 = 나가기 ) - ";
		cin >> input;
		FindItem(input);

		if (input == "나가기")
			break;
	}



}

void CStore::FindItem(string _Iname)
{
		for (auto& Store : mStore)
		{
			if (Store->GetName() == _Iname && mPlayer->GetGold() >= Store->GetPrice())
			{
				mPlayer->GetInven()->AddItem_Inven(Store);
				mPlayer->SetGold(mPlayer->GetGold() - Store->GetPrice());
				cout << Store->GetName() << " 구매 완료" << endl;
				mStore.erase(mStore.begin() + (1 -(Store->GetName() == _Iname)));
				break;
			}
			else if (Store->GetName() == _Iname && mPlayer->GetGold() < Store->GetPrice())
			{
				cout << "소지금 부족" << endl;
				Sleep(1000);
				break;
			}
		}
}
