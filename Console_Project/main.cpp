#include "Battle.h"



int main()
{
	CPlayer* _player = nullptr;
	Battle battle;
	CCard card;
	int input;

	card.Gotoxy(55, 20);
	cout << "1. Game Start" << endl;
	card.Gotoxy(55, 21);
	cout << "2. Game End" << endl;

	cin >> input;

	switch (input)
	{
	case 1:
		system("cls");
		battle.BattleStart(_player);
		break;

	case 2:
		system("cls");
		card.Gotoxy(55,15);
		cout << "게임 종료" << endl;
		break;

	default:
		break;
	}

	//battle.PrintBattleMap();

}