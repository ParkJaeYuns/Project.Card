#include "Battle.h"

Battle::Battle()
{
	mCardDB = new CCardDB();
}

Battle::~Battle()
{
	delete Store; // 스토어 메모리 할당 해제
	cout << "스토어 메모리" << endl;

	// 덱, 패, 묘지 할당 해제
	for (auto& _playerDeck : mPlayerDeck)
	{
		delete _playerDeck;
	}
	mPlayerDeck.clear();
	cout << "덱 메모리" << endl;

	for (auto& _Draw : mDraw)
	{
		delete _Draw;
	}
	mDraw.clear();
	cout << "패 메모리" << endl;

	for (auto& _UsedDeck : mUsedCard)
	{
		delete _UsedDeck;
	}
	mUsedCard.clear();
	cout << "묘지 메모리" << endl;

}

void Battle::BattleStart(CPlayer*& _player)
{
	srand(unsigned(time(NULL)));
	int input;
	int count = NULL;
	bool isTrue = true;


	// 클래스 선택
	_player->SelectCharacter(_player); 
	
	// 클래스 덱 할당
	SelectCharacter_Card(_player);
	
	Sleep(500);
	system("cls");

	// 전략선택
	FirstChoice(_player);

	Sleep(500);
	system("cls");

	card->Gotoxy(50, 18);
	cout << "<몬스터 생성중 ...>" << endl;
	mMonster->SelectMonster(mMonster); // 몬스터 메모리 할당

	Sleep(1000);
	system("cls");

	while (true)
	{

		system("cls");

		// 몬스터의 데미지 렌덤값을 받음
		int M_Damage = 3 + rand() % 6;

		//카드를 섞고 5장을 뽑음
		DrawCard();
		_player->SetCost(3);
		int Heart = UsedItem(_player, isTrue);
		isTrue = Heart;


		while (true)
		{	
			system("cls");

			//배틀창 출력
			PrintBattleMap();
			_player->Show_PlayerInven();

			// 사용 가능한 코스트 출력
			card->Gotoxy(3, 13);
			cout << "┌───────┐" << endl;
			card->Gotoxy(3, 14);
			cout << "│ " << _player->GetCost() << " / 3 │" << endl;
			card->Gotoxy(3, 15);
			cout << "└───────┘" << endl;

			// 플레이어 및 몬스터 정보 출력
			_player->PrintInfo();
			mMonster->PrintInfo(); 

			// 몬스터가 공격할 데미지 출력
			card->Gotoxy(70, 4);
			cout << "공격 - " << M_Damage + mMonster->GetAttack() << endl;

			// 드로우 패 출력
			printDrawCard();

			// 남아있는 덱 출력
			PrintDeckCard();
			
			//입력칸 출력
			card->Gotoxy(35, 25);
			cout << "사용할 카드의 번호를 입력하세요 ( 99 - 턴 종료)" << endl;
			card->Gotoxy(45, 26);
			cout << "입력 : ";
			cin >> input;

			// 카드 사용 및 사용카드 묘지덱으로 이동 / 덱에서 삭제
			if (_player->GetCost() > 0 || (input != 99 && mDraw[input - 1]->GetName() == "숨고르기"))
			{
				SelectUsingCard(input, mDraw, _player);
				
				if (input == 99)
					break;

				else if (mMonster->GetHp() <= 0)
					break;

				else
					continue;
			}

			if (_player->GetCost() <= 0)
			{
				card->Gotoxy(43, 13);
				cout << "턴 종료" << endl;
				Sleep(1000);
				break;
			}

		}

		//플레이어턴 종료시 패에 있던 카드 모두 묘지로 이동
		for (auto i = 0; i < mDraw.size(); i++)
		{
			mUsedCard.push_back(mDraw[i]);
		}	

		// 패에 있던 벡터 요소 제거
		mDraw.clear();

		// 몬스터
		if (mMonster->GetHp() > 0)
		{
			_player->TakeDamage_player(M_Damage + mMonster->GetAttack());
			
			card->Gotoxy(43, 13);
			cout << "[몬스터 공격] - " << M_Damage + mMonster->GetAttack() << endl;
			
			Sleep(1000);
		}

		// 몬스터 사망시
		if (mMonster->GetHp() <= 0)
		{
			delete mMonster;
			mMonster = nullptr;
			count++;

			system("cls");

			card->Gotoxy(46, 8);
			cout << "--------<몬스터 제거>--------" << endl;
			
			// 묘지덱 플레이어 덱으로 옮긴 후 요소 제거 
			for (int i = 0; i < mUsedCard.size(); i++)
			{
				mPlayerDeck.push_back(mUsedCard[i]);
			}
			mUsedCard.clear();
			Sleep(700);

			//몬스터를 잡았을 때 얻는 리워드
			Monster_Reward(_player, count);

			system("cls");

			if (count % 3 == 0)
			{
				Show_Store(_player);
			}

			Sleep(1000);
			system("cls");

			if (count == 5)
			{
				delete mMonster;
				mMonster = nullptr;
				break;
			}

			if (count % 4 == 0)
			{
				//보스 소환
				mMonster->SelectBossMonster(mMonster);
				continue;
			}
			else
				card->Gotoxy(48, 19);
				cout << "[몬스터 제거 - 재생성중]" << endl;
				mMonster->SelectMonster(mMonster);

			//	if ()
				Sleep(1000);
		}

		if (_player->GetHealth() <= 0)
		{
			delete mMonster;
			mMonster = nullptr;
			break;
		}


	}

	// 플레이어 덱(o), 드로우덱(x), 묘지덱(x) 메모리 해제
	delete _player;
	_player = nullptr;

}

void Battle::TakeDamage_monster(const int _Atk)
{
	mMonster->SetHP(mMonster->GetHp() - _Atk);
}

void Battle::DrawCard()
{
	//vector<Battle> Draw;
	std::random_device rd;

	shuffle(mPlayerDeck.begin(), mPlayerDeck.end(), default_random_engine(rd()));

	for (int i = 0; i < 5; i++)
	{
		if (mPlayerDeck.empty())
		{
			mPlayerDeck.swap(mUsedCard);
		}

		mDraw.push_back(mPlayerDeck.back());
		mPlayerDeck.pop_back();


	}


}

void Battle::SelectUsingCard(int a, vector<CCard*>& _card, CPlayer*& _player)
{
	string _Cname = " ";

	if (a == 99)
		return;

		_Cname = _card[a-1]->GetName();

		if (_player->GetCost() < _card[a-1]->GetCost())
			return;

		if ((_Cname == "체력회복") || (_Cname == "체력회복+"))
		{

			if ((_player->GetHealth()) == (_player->GetMaxHealth()))
			{
				return;
			}
			_player->SetHealth(_player->GetHealth() + _card[a-1]->GetAttack());
		}

		else if ((_Cname == "철벽") || (_Cname == "방어") || (_Cname == "철벽+") || (_Cname == "방어+"))
		{
			_player->SetDefence(_player->GetDefence() + _card[a-1]->GetAttack());
		}

		else if ((_Cname == "참호") || (_Cname == "참호+"))
		{
			_player->SetDefence(_card[a-1]->GetAttack() + _player->GetDefence() * 2);
		}

		else if ((_Cname == "베기") || (_Cname == "찌르기") || (_Cname == "급습") || (_Cname == "단검 투척") || (_Cname == "대검") || (_Cname == "몽둥이질")
			|| (_Cname == "베기+") || (_Cname == "찌르기+") || (_Cname == "급습+") || (_Cname == "단검 투척+") || (_Cname == "대검+") || (_Cname == "몽둥이질+"))
		{
			TakeDamage_monster(_card[a-1]->GetAttack() + _player->GetAttack());
		}
		else if ((_Cname == "방패강타") || (_Cname == "방패강타+"))
		{
			TakeDamage_monster(_card[a-1]->GetAttack() + _player->GetDefence());
		}

		else if ((_Cname == "혈류") || (_Cname == "혈류+"))
		{
			TakeDamage_monster(_card[a - 1]->GetAttack() + _player->GetAttack() );
			_player->SetHealth(_player->GetHealth() - 5);
		}

		else if (( _Cname == "숨고르기") || (_Cname == "숨고르기+"))
		{
			_player->SetCost(_player->GetCost() + _card[a-1]->GetAttack());
		}

		card->Gotoxy(43, 13);
		cout << "카드사용 - ";
		_card[a-1]->Print();
		Sleep(1000);


		if (((_Cname == "체력회복") || (_Cname == "체력회복+")) && (_player->GetHealth()) == (_player->GetMaxHealth()))
			return;
		
		if (a != 99 && (_player->GetCost() < _card[a-1]->GetCost()))
			return;

		if (a > 0 && a < 6)
			_player->SetCost(_player->GetCost() - _card[a - 1]->GetCost());
			mUsedCard.push_back(_card[a - 1]);
			_card.erase(_card.begin() + (a - 1));
		{
		}

		// 여기서 카드 사용 알림

		//if (a == 99)
		//{
		//	for (auto i = 0; i < _card.size(); i++)
		//	{
		//		mUsedCard.push_back(_card[i]);
	
		//	}
		//	_card.clear();
		//	//cout << "턴 종료" << endl;
		//}


}

void Battle::printDrawCard()
{
	int x = 0;
	int y = 16;
	for (auto& i : mDraw)
	{
		i->PrintDraw(x, y);
		x += 24;
		Sleep(100);
	}
}

void Battle::PrintDeckCard()
{
	int _y = 21;
	card->Gotoxy(0, 21);
	cout << "덱" << endl;
	for (auto& i : mPlayerDeck)
	{
		i->PrintDeck_Used(1, _y);
		_y++;
	}
}

void Battle::Monster_Reward(CPlayer*& _player, int _count)
{
	// 카드 3장중 1장 선택후 덱에다 넣기
	for (int i = 0; i < 3; i++)
	{
		int rands = rand() % 11;
		mDraw.push_back(mJabDeck[rands]);
	}

	int input = NULL;
	int _x = 25;
	int _y = 10;
	for (auto& Reward : mDraw)
	{
		Reward->PrintDraw(_x, _y);
		_x += 25;
	}

	card->Gotoxy(48, 16);
	cout << "카드를 선택하세요 (99 - 넘기기)" << endl;
	card->Gotoxy(52, 17);
	cin >> input;

	switch (input)
	{
	case 1: 
		mPlayerDeck.push_back(mDraw[0]);
		mDraw.clear();
		break;

	case 2:
		mPlayerDeck.push_back(mDraw[1]);
		mDraw.clear();
		break;

	case 3:
		mPlayerDeck.push_back(mDraw[2]);
		mDraw.clear();
		break;

	case 99:
		mDraw.clear();
		break;
	}

	system("cls");


	if (_count == 1 || _count == 3)
	{
		int num = 1;
		int x = 15;
		int y = 8;

		card->Gotoxy(x + 28, y + 2);
		cout << "===============<선택>==============" << endl;
		card->Gotoxy(x + 28, y + 3);
		cout << "1. 휴식   2. 카드제거    3. 카드강화" << endl;
		card->Gotoxy(x + 28, y + 4);
		cout << "===================================" << endl;

		card->Gotoxy(x + 28, y + 6);
		cin >> input;

		switch (input)
		{
		case 1: // 휴식

			card->Gotoxy(x + 28, y + 6);
			cout << "휴식 (hp + 30)" << endl;
			_player->SetHealth(_player->GetHealth() + 30);
			break;

		case 2: // 카드 제거

			card->Gotoxy(x, y);
			cout << " ┌──────[덱]──────┐ " << endl;

			card->Gotoxy(x, y + 13);
			cout << " └────────────────┘ " << endl;

			for (auto& _Deck : mPlayerDeck)
			{
				card->Gotoxy(x + 3, y + 1);
				cout << num << ". ";
				_Deck->Print();
				num++;
				y++;
			}
			y = 8;
			card->Gotoxy(x + 28, y + 6);
			cout << "제거할 카드 선택 : ";
			cin >> input;

			card->Gotoxy(x + 28, y + 8);
			cout << "선택된 카드 : ";
			mPlayerDeck[input - 1]->Print();

			Sleep(800);

			mPlayerDeck.erase(mPlayerDeck.begin() + (input - 1));
			break;

		case 3: // 카드 강화

			card->Gotoxy(x, y);
			cout << " ┌──────[덱]──────┐ " << endl;

			card->Gotoxy(x, y + 13);
			cout << " └────────────────┘ " << endl;

			for (auto& _Deck : mPlayerDeck)
			{
				card->Gotoxy(x + 3, y + 1);
				cout << num << ". ";
				_Deck->Print();
				num++;
				y++;
			}

			y = 8;
			card->Gotoxy(x + 28, y + 6);
			cout << "강화할 카드 선택 : ";
			cin >> input;

			card->Gotoxy(x + 28, y + 8);
			cout << "선택된 카드 : ";

			mPlayerDeck[input - 1]->Print();

			// 카드를 선택하면, 그 카드를 강화하는 시스템
			// 카드 선택시, 플레이어 덱에서 카드 제거, 이후 강화카드를 추가 해야함.

			mPlayerDeck[input - 1]->SetName(mPlayerDeck[input - 1]->GetName() + "+");
			for (int i = 0; i < mCardDB->GetDBSize(); i++)
			{
				if (mCardDB->Getcard(i)->GetName() == mPlayerDeck[input - 1]->GetName())
				{
					mPlayerDeck.erase(mPlayerDeck.begin() + (input - 1));
					mPlayerDeck.push_back(mCardDB->Getcard(i));
				}

			}

			card->Gotoxy(x + 52, y + 8);
			cout << "  ─>  ";
			mPlayerDeck.back()->Print();

			Sleep(1000);

		default:
			cout << "잘못 입력했습니다" << endl;
		}
	}

}

void Battle::PrintBattleMap()
{
	card->Gotoxy(16, 1);
	cout << "┌───────────────────────────────────────────────────────────────────────────────┐" << endl;
	card->Gotoxy(16, 2);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 3);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 3);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 4);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 5);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 6);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 7);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 8);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 9);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 10);
	cout << "│" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "│" << endl;
	card->Gotoxy(16, 11);
	cout << "└───────────────────────────────────────────────────────────────────────────────┘" << endl;


}

void Battle::SelectCharacter_Card(CPlayer*& _player)
{
	CCard* _newCard = nullptr;

	// 베기 시작덱에 삽입
	for (int i = 0; i < 3; i++)
	{
		_newCard = mCardDB->Getcard("베기");
		mPlayerDeck.push_back(new CCard(_newCard));
	}
	// 방어 시작덱에 삽입
	for (int i = 0; i < 3; i++)
	{
		_newCard = mCardDB->Getcard("방어");
		mPlayerDeck.push_back(new CCard(_newCard));
	}
	// 숨고르기 시작덱에 삽입
	for (int i = 0; i < 2; i++)
	{
		_newCard = mCardDB->Getcard("숨고르기");
		mPlayerDeck.push_back(new CCard(_newCard));
	}
	// 찌르기 시작덱에 삽입
	_newCard = mCardDB->Getcard("찌르기");
	mPlayerDeck.push_back(new CCard(_newCard));

	_newCard = mCardDB->Getcard("철벽");
	mPlayerDeck.push_back(new CCard(_newCard));

	_newCard = mCardDB->Getcard("방패강타");
	mPlayerDeck.push_back(new CCard(_newCard));


	// 직업덱에 공용카드와 직업카드 삽입
	for (int i = 0; i < mCardDB->GetDBSize(); i++)
	{
		_newCard = mCardDB->Getcard(i);
		if (_newCard->GetJab() == PlayerJab::NONE || _newCard->GetJab() == _player->GetJabClass())
			mJabDeck.push_back(new CCard(_newCard));

	}

}

void Battle::FirstChoice(CPlayer*& _player)
{
	int _RandomGold = (50 + rand() % 50);
	int _RandomAtk = (10 + rand() % 11);
	int _RandomHp = (10 + rand() % 8);
	int input;

	card->Gotoxy(43, 10);
	cout << "=============<전략선택>============" << endl;
	card->Gotoxy(43, 11);
	cout << "= 1. " << _RandomGold << "골드 획득 =" << endl;
	card->Gotoxy(43, 12);
	cout << "= 2. " << _RandomAtk << "피해를 입고 최대체력 + " << _RandomHp << " =" << endl;
	card->Gotoxy(43, 13);
	cout << "= 3. " << _RandomAtk << "피해를 입고 무작위 카드 + 1 " << endl;
	card->Gotoxy(43, 14);
	cout << "===================================" << endl;
	card->Gotoxy(43, 15);
	cin >> input;


	switch (input)
	{
	case 1:
		_player->SetGold(_RandomGold);
		break;
	case 2:
		_player->SetHealth(_player->GetHealth() - _RandomAtk);
		// 최대체력 증가
		_player->SetMaxHealth(_player->GetMaxHealth() + _RandomHp);
		break;

	case 3:
		_player->SetHealth(_player->GetHealth() - _RandomAtk);
		break;
		//	mPlayerDeck.push_back()

	default:
		break;
	}
}

void Battle::Show_Store(CPlayer*& _player)
{

	Store = new CStore(_player);

	
	Store->Store_list();
	Store->BuyItem();

}

int Battle::UsedItem(CPlayer*& _player, int _bool)
{

	for (int i = 0; i < _player->GetInven()->GetinvenSize(); i++)
	{
		CItem* currentitem = _player->GetInven()->GetInvenItem(i);

		if (currentitem->GetName() == "오리하르콘")
		{
			_player->SetDefence(currentitem->GetDefence());

		}
		
		if (currentitem->GetName() == "고기덩어리")
		{
			if (_player->GetHealth() <= _player->GetMaxHealth() / 2)
			{
				_player->SetHealth(_player->GetHealth() + 6);
			}
		}

		if (currentitem->GetName() == "신선한심장" && _bool == true)
		{
			_player->SetMaxHealth(_player->GetMaxHealth() + 10);

			card->Gotoxy(43, 13);
			cout << "[신선한심장] - 최대체력+10 " << endl;
			return false;
		}
	}

}



