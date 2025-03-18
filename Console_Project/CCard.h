#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include <iomanip>
#include <Windows.h>
#include "Enum.h"

using namespace std;

class CCard
{
public:
	CCard();
	CCard(const string& _name, int _atk, int _cost, PlayerJab _jab);
	CCard(const string& _name, int _atk, int _cost);
	CCard(CCard* _card);
	~CCard();

	void Print();
	void PrintDeck_Used(int _x, int _y);
	void PrintDraw(int _x, int _y);


	string GetName()const;
	int GetAttack()const;
	int GetCost()const;
	void SetName(string _name);
	void SetAttack(int a);
	void Gotoxy(short x, short y);

	PlayerJab GetJab()const;



private:

	string mName;
	int mAttack; // ����ī��� ���ݷ��̰� ���ī��� �������� ���
	int mCost;
	PlayerJab mJab;

};

