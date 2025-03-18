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
	mStore.push_back(new CItem("�����ϸ���", 0, 4, 50, 0, "�� �÷��̾��ϸ��� �� +4")); // �� �÷��̾� �϶� �� + 3
	mStore.push_back(new CItem("��ⵢ�", 6, 0, 50, 0, "���� ���� �� ���� �÷��̾� ü���� 50% ���ϸ� ü�� +6"));	 // ���� ���� �� ü���� 50% ������ �� ü�� 6 ȸ��
	mStore.push_back(new CItem("�ż��ѽ���", 0, 0, 50, 10, "�ִ�ü�� +10"));	  // �ִ�ü�� + 10
}

void CStore::BuyItem()
{
	CCard card;

	string input;

	while (true)
	{
		system("cls");

		card.Gotoxy(40, 7);
		cout << "================< ���� >================" << endl;

		card.Gotoxy(23, 9);
		cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
		card.Gotoxy(23, 10);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 11);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 12);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 13);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 14);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 15);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 16);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 17);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 18);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 19);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 20);
		cout << "��" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "    ��" << endl;
		card.Gotoxy(23, 21);
		cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;

		int x = 25;
		int y = 11;

		for (auto& Store : mStore)
		{
			Store->ShowItme(x, y);
			y += 3;
		}

		card.Gotoxy(45, 22);
		cout << "������ - " << mPlayer->GetGold() << endl;
		card.Gotoxy(28, 23);
		cout << "�����Ϸ��� �������� �̸��� �Է��ϼ��� ( �����ݱ� = ������ ) - ";
		cin >> input;
		FindItem(input);

		if (input == "������")
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
				cout << Store->GetName() << " ���� �Ϸ�" << endl;
				mStore.erase(mStore.begin() + (1 -(Store->GetName() == _Iname)));
				break;
			}
			else if (Store->GetName() == _Iname && mPlayer->GetGold() < Store->GetPrice())
			{
				cout << "������ ����" << endl;
				Sleep(1000);
				break;
			}
		}
}
