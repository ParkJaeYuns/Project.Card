#include "CCardDB.h"

CCardDB::CCardDB()
{
	//공용
	mCardDB.push_back(new CCard("베기", 5, 1));
	mCardDB.push_back(new CCard("찌르기", 7, 1));
	mCardDB.push_back(new CCard("숨고르기", 1, 0));
	mCardDB.push_back(new CCard("방어", 4, 1));	// 방어도증가
	mCardDB.push_back(new CCard("체력회복", 5, 1 )); // 힐

	//공용 강화
	mCardDB.push_back(new CCard("베기+", 7, 1, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("찌르기+", 9, 1, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("숨고르기+", 2, 0, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("방어+", 5, 1, PlayerJab::UPGRADE));	// 방어도증가
	mCardDB.push_back(new CCard("체력회복+", 7, 1, PlayerJab::UPGRADE)); // 힐

	//전사
	mCardDB.push_back(new CCard("방패강타", 2, 2, PlayerJab::WARRIOR)); // 방어도 에 따른 데미지
	mCardDB.push_back(new CCard("철벽", 10, 2, PlayerJab::WARRIOR));		// 방어도증가
	mCardDB.push_back(new CCard("대검", 13, 2, PlayerJab::WARRIOR)); //
	mCardDB.push_back(new CCard("혈류", 15, 2, PlayerJab::WARRIOR)); // 체력-2
	mCardDB.push_back(new CCard("몽둥이질", 20, 3, PlayerJab::WARRIOR)); // 
	mCardDB.push_back(new CCard("참호", 0, 2, PlayerJab::WARRIOR)); //방어도 2배 증가

	//전사강화
	mCardDB.push_back(new CCard("방패강타+", 4, 2, PlayerJab::UPGRADE)); // 방어도 에 따른 데미지
	mCardDB.push_back(new CCard("철벽+", 12, 2, PlayerJab::UPGRADE));		// 방어도증가
	mCardDB.push_back(new CCard("대검+", 15, 2, PlayerJab::UPGRADE)); //
	mCardDB.push_back(new CCard("혈류+", 17, 2, PlayerJab::UPGRADE)); // 체력-3
	mCardDB.push_back(new CCard("몽둥이질+", 23, 3, PlayerJab::UPGRADE)); // 
	mCardDB.push_back(new CCard("참호+", 3, 2, PlayerJab::UPGRADE)); //방어도 2배 증가

	//도적
	mCardDB.push_back(new CCard("단검 투척", 10, 2, PlayerJab::ROGUE));
	mCardDB.push_back(new CCard("급습", 12, 2, PlayerJab::ROGUE));

	
}

CCardDB::~CCardDB()
{
	for (auto& i : mCardDB)
	{
		delete i;
	}

	cout << "mCardDB - 소멸자" << endl;
}

CCard* CCardDB::Getcard(string _name) const
{
	for (auto& Cardlist : mCardDB)
	{
		if (_name == Cardlist->GetName())
		{
			return Cardlist;
		}
	}

}

CCard* CCardDB::Getcard(int _index) const
{
	return mCardDB[_index];
}

int CCardDB::GetDBSize() const
{
	return mCardDB.size();
}
