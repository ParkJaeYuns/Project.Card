#pragma once
#include "CCard.h"

class CCardDB 
{
public:

	CCardDB();
	~CCardDB();

	CCard* Getcard(string _name)const;
	CCard* Getcard(int _index)const;
	int GetDBSize()const;




private:
	vector<CCard*> mCardDB;

};

