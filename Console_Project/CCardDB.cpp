#include "CCardDB.h"

CCardDB::CCardDB()
{
	//����
	mCardDB.push_back(new CCard("����", 5, 1));
	mCardDB.push_back(new CCard("���", 7, 1));
	mCardDB.push_back(new CCard("������", 1, 0));
	mCardDB.push_back(new CCard("���", 4, 1));	// ������
	mCardDB.push_back(new CCard("ü��ȸ��", 5, 1 )); // ��

	//���� ��ȭ
	mCardDB.push_back(new CCard("����+", 7, 1, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("���+", 9, 1, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("������+", 2, 0, PlayerJab::UPGRADE));
	mCardDB.push_back(new CCard("���+", 5, 1, PlayerJab::UPGRADE));	// ������
	mCardDB.push_back(new CCard("ü��ȸ��+", 7, 1, PlayerJab::UPGRADE)); // ��

	//����
	mCardDB.push_back(new CCard("���а�Ÿ", 2, 2, PlayerJab::WARRIOR)); // �� �� ���� ������
	mCardDB.push_back(new CCard("ö��", 10, 2, PlayerJab::WARRIOR));		// ������
	mCardDB.push_back(new CCard("���", 13, 2, PlayerJab::WARRIOR)); //
	mCardDB.push_back(new CCard("����", 15, 2, PlayerJab::WARRIOR)); // ü��-2
	mCardDB.push_back(new CCard("��������", 20, 3, PlayerJab::WARRIOR)); // 
	mCardDB.push_back(new CCard("��ȣ", 0, 2, PlayerJab::WARRIOR)); //�� 2�� ����

	//���簭ȭ
	mCardDB.push_back(new CCard("���а�Ÿ+", 4, 2, PlayerJab::UPGRADE)); // �� �� ���� ������
	mCardDB.push_back(new CCard("ö��+", 12, 2, PlayerJab::UPGRADE));		// ������
	mCardDB.push_back(new CCard("���+", 15, 2, PlayerJab::UPGRADE)); //
	mCardDB.push_back(new CCard("����+", 17, 2, PlayerJab::UPGRADE)); // ü��-3
	mCardDB.push_back(new CCard("��������+", 23, 3, PlayerJab::UPGRADE)); // 
	mCardDB.push_back(new CCard("��ȣ+", 3, 2, PlayerJab::UPGRADE)); //�� 2�� ����

	//����
	mCardDB.push_back(new CCard("�ܰ� ��ô", 10, 2, PlayerJab::ROGUE));
	mCardDB.push_back(new CCard("�޽�", 12, 2, PlayerJab::ROGUE));

	
}

CCardDB::~CCardDB()
{
	for (auto& i : mCardDB)
	{
		delete i;
	}

	cout << "mCardDB - �Ҹ���" << endl;
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
