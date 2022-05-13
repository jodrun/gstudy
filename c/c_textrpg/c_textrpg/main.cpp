#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <time.h>
#include <Windows.h>



const int Scene_Menu      = 0;
const int Scene_Stage     = 1;
const int Scene_Store     = 2;  
const int Scene_Inventory = 3;  
const int Scene_Exit      = 4;

int GetGold = 0;

int SceneState = 0;
int iStageScene = 0;
int act1choice = 0;

int itemchoice1 = 0;
int itemchoice2 = 0;
int itemchoice3 = 0;
int itemchoice4 = 0;
int itemchoice5 = 0;
int itemchoice6 = 0;

int inventorycountweapon = 0;
int inventorycountamor = 0;

int levelupexp[10] = { 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 50200 };

typedef struct _item
{
	char* itemname;
	int itematt;
	int itemdff;
	int price;
}ITEM;


typedef struct _Iventory
{
	ITEM item1;
	ITEM item2;
	ITEM item3;
	ITEM item4;
	ITEM item5;
	ITEM item6;
	int Gold;
}Iventory;



typedef struct tagInfo
{
	int HP;
	int HPMAX;
	int MP;
	int MPMAX;

	int EXP;

	int Att;
	int ITEMATT;
	int Def;
	int ITEMDFF;

	short Level;
	
	short GoldMin;
	short GoldMax;
}INFO;

typedef struct tagObject
{
	char* Name;
	INFO Info;

}OBJECT;



void SceneManager(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2, Iventory* _item);
char* SetName();

void LogoScene();
void MenuScene();
void StageScene(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2, Iventory* _item);
void act1(OBJECT* _Player, OBJECT* _Enemy, Iventory* _item);
void act2(OBJECT* _Player, OBJECT* _Enemy1, Iventory* _item);
void act3(OBJECT* _Player, OBJECT* _Enemy2, Iventory* _item);

int StoreScene(Iventory* _item);
int WeaponStore(Iventory* _item);
int AmorStore(Iventory* _item);
int InventoryScene(OBJECT* _Player, Iventory* _item);

void InitializeItem1(Iventory* _item);

void InitializePlayer(OBJECT* _Player);
void levelup(OBJECT* _Player);

void PlayerSceneact1(OBJECT* _Player, OBJECT* _Enemy, Iventory* _item);
void PlayerSceneact2(OBJECT* _Player, OBJECT* _Enemy1, Iventory* _item);
void PlayerSceneact3(OBJECT* _Player, OBJECT* _Enemy2, Iventory* _item);
void InitializeEnemy(OBJECT* _Enemy);
void InitializeEnemy1(OBJECT* _Enemy1);
void InitializeEnemy2(OBJECT* _Enemy2);
void EnemySceneact1(OBJECT* _Enemy, OBJECT* _Player, Iventory* _item);
void EnemySceneact2(OBJECT* _Enemy1, OBJECT* _Player, Iventory* _item);
void EnemySceneact3(OBJECT* _Enemy2, OBJECT* _Player, Iventory* _item);

void pHealSkill(OBJECT* _Player);
void mHealSkill(OBJECT* _Enemy);

void SetPosition(short _x, short _y, char* _str, int _Color = 15);
void SetColor(int _Color);







int main(void)
{
	system("mode con:cols=120 lines=30");
	system("title 황재갑 textrpg");

	LogoScene();
	system("cls");

	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT));
	InitializePlayer(Player);

	OBJECT* Monster = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeEnemy(Monster);
	
	OBJECT* Monster1 = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeEnemy1(Monster1);

	OBJECT* Monster2 = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeEnemy2(Monster2);

	Iventory* Item1 = (Iventory*)malloc(sizeof(Iventory));
	InitializeItem1(Item1);

	DWORD dwTime = GetTickCount();
	int Delay = 1000;

	while (true)
	{
		if (dwTime + Delay < GetTickCount())
		{
			dwTime = GetTickCount();

		
			system("cls");
			printf_s("%s님\n\n", Player->Name);

			// ** 게임 루프
			SceneManager(Player, Monster, Monster1, Monster2, Item1);
		}
	}


	return 0;
}







void SceneManager(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2, Iventory* _item)
{
	switch (SceneState) 
	{
	case Scene_Menu:
		MenuScene();
		break;
	case Scene_Stage:
		StageScene(_Player, _Enemy, _Enemy1, _Enemy2, _item);
		break;
	case Scene_Store:
		StoreScene(_item);
		break;
	case Scene_Inventory:
		InventoryScene(_Player, _item);
		break;
	case Scene_Exit:
        
		exit(NULL);
		break;
	}
}

char* SetName()
{
	char Buffer[128] = "";
	printf_s("이름 입력 : ");
	scanf("%s", Buffer);
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);
	return pName;
}

void LogoScene()
{
	int Width = (120 / 2) - (int)(strlen(" ####                      ") / 2);
	int Height = 8;

	SetPosition(Width, Height + 1, (char*) "####                      ");
	SetPosition(Width, Height + 2, (char*) " ##                       ");
	SetPosition(Width, Height + 3, (char*) " ##                       ");
	SetPosition(Width, Height + 4, (char*) " ##     ###    ####   ### ");
	SetPosition(Width, Height + 5, (char*) " ##    ## ##  ## ##  ## ##");
	SetPosition(Width, Height + 6, (char*) " ##    ## ##  ## ##  ## ##");
	SetPosition(Width, Height + 7, (char*) " ##    ## ##  ## ##  ## ##");
	SetPosition(Width, Height + 8, (char*) "####    ###    ####   ### ");
	SetPosition(Width, Height + 9, (char*) "                 ##       ");
	SetPosition(Width, Height + 10, (char*)"               ###        ");
	
	
	Sleep(1000);
}

void MenuScene()
{
	printf_s("메인메뉴\n\n");

	printf_s("1. 스테이지\n2. 상점\n3. 가방\n4. 종료\n\n입력 : ");

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
		SceneState++;
	else if (i == 2)
		SceneState = Scene_Store;
	else if (i == 3)
		SceneState = Scene_Inventory;
	else if (i == 4)
		SceneState = Scene_Exit;
}

void StageScene(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2, Iventory* _item)
{
	printf_s("스테이지를 고르세요\n\n");
	printf_s("1, 스테이지1(쉬움)\n");
	printf_s("2, 스테이지2(보통)\n");
	printf_s("3, 스테이지3(어려움)\n");
	printf_s("4, 메인메뉴로 가기\n\n");
	printf_s("입력 : ");
	scanf("%d", &iStageScene);
	system("cls");

	if (iStageScene == 1)
	{
		act1(_Player, _Enemy, _item);
	}
	else if (iStageScene == 2)
	{
		act2(_Player, _Enemy1, _item);
	}
	else if (iStageScene == 3)
	{
		act3(_Player, _Enemy2, _item);
	}
	else if (iStageScene == 4)
	{
		SceneState--;
	}
}

void act1(OBJECT* _Player, OBJECT* _Enemy, Iventory* _item)
{

	printf_s("1, 스테이지1(쉬움)\n\n");
	Sleep(1000);
	system("cls");
	act1choice = 0;

	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact1(_Player, _Enemy, _item);
		}
		else if (act1choice == 1)
		{
			EnemySceneact1(_Enemy, _Player, _item);
		}
		else if (act1choice == 9) //도망성공
		{
			break;
		}
		GetGold = 0;
	}
}

void act2(OBJECT* _Player, OBJECT* _Enemy1, Iventory* _item)
{
	printf_s("2, 스테이지2(보통)\n\n");
	Sleep(1000);
	system("cls");
	act1choice = 0;

	
	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact2(_Player, _Enemy1, _item);
		}
		else if (act1choice == 1)
		{
			EnemySceneact2(_Enemy1, _Player, _item);
		}
		else if (act1choice == 9) //도망성공
		{
			break;
		}
		GetGold = 0;
	}
}

void act3(OBJECT* _Player, OBJECT* _Enemy2, Iventory* _item)
{
	printf_s("3, 스테이지3(어려움)\n\n");
	Sleep(1000);
	system("cls");
	act1choice = 0;

	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact3(_Player, _Enemy2, _item);
		}
		else if (act1choice == 1)
		{
			EnemySceneact3(_Enemy2, _Player, _item);
		}
		else if (act1choice == 9) //도망성공
		{
			break;
		}
		GetGold = 0;
	}

}



int StoreScene(Iventory* _item)
{
	printf_s("*********************상점*********************\n\n");
	printf_s("1, 무기상점\n2, 방어구상점\n3, 뒤로가기\n");
	printf_s("입력 : ");
	int storeselect = 0;
	scanf("%d", &storeselect);

	system("cls");

	if (storeselect == 1)
	{
		WeaponStore(_item);
	}
	else if (storeselect == 2)
	{
		AmorStore(_item);
	}
	else if (storeselect == 3)
	{
		SceneState = Scene_Menu;
	}

	return itemchoice1, itemchoice2, itemchoice3;
}

int WeaponStore(Iventory* _item)
{
	while (true)
	{
	    printf_s("*********************무기상점*********************\n\n");
		printf_s("소지골드 %d\n\n", _item->Gold);
	    printf_s("1, 싸구려검 가격 : %d\n", _item->item1.price);
	    printf_s("2, 보통검   가격 : %d\n", _item->item2.price);
	    printf_s("3, 나이스검 가격 : %d\n", _item->item3.price);
	    printf_s("4, 뒤로가기\n\n");
	    printf_s("입력 : ");
	
	    int a = 0;
	    scanf("%d", &a);
		system("cls");
	
		if (a == 1 && _item->Gold >= _item->item1.price)
		{
			if (itemchoice1 == 1)
			{
				printf_s("싸구려검이 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("싸구려검을 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item1.price;
				itemchoice1 = 1;
			}
		}
		else if (a == 1 && _item->Gold < _item->item1.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}
		
		if (a == 2 && _item->Gold >= _item->item2.price)
		{
        	if (itemchoice2 == 1)
			{
				printf_s("보통검이 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("보통검을 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item2.price;
				itemchoice2 = 1;
			}
		}
		else if (a == 2 && _item->Gold < _item->item2.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}
		
		if (a == 3 && _item->Gold >= _item->item3.price)
		{
			if (itemchoice3 == 1)
			{
				printf_s("나이스검이 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("나이스검을 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item3.price;
				itemchoice3 = 1;
			}
		}
		else if (a == 3 && _item->Gold < _item->item3.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}

		system("cls");

		if (a == 4)
		{
			break;
		}
	}

	return itemchoice1, itemchoice2, itemchoice3;
}

int AmorStore(Iventory* _item)
{
	while (true)
	{
		printf_s("*********************방어구상점*********************\n\n");
		printf_s("소지골드 %d\n\n", _item->Gold);
		printf_s("1, 싸구려방어구 가격 : %d\n", _item->item4.price);
		printf_s("2, 보통방어구   가격 : %d\n", _item->item5.price);
		printf_s("3, 나이스방어구 가격 : %d\n", _item->item6.price);
		printf_s("4, 뒤로가기\n\n");
		printf_s("입력 : ");

		int a = 0;
		scanf("%d", &a);
		system("cls");

		if (a == 1 && _item->Gold >= _item->item4.price)
		{
			if (itemchoice4 == 1)
			{
				printf_s("싸구려방어구가 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("싸구려방어구 를 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item4.price;
				itemchoice4 = 1;
			}
		}
		else if (a == 1 && _item->Gold < _item->item4.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}

		if (a == 2 && _item->Gold >= _item->item5.price)
		{
			if (itemchoice5 == 1)
			{
				printf_s("보통방어구가 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("보통방어구 를 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item5.price;
				itemchoice5 = 1;
			}
		}
		else if (a == 2 && _item->Gold < _item->item5.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}

		if (a == 3 && _item->Gold >= _item->item6.price)
		{
			if (itemchoice6 == 1)
			{
				printf_s("나이스방어구가 이미 있습니다");
				Sleep(1000);
				break;
			}
			else
			{
				printf_s("나이스방어구 를 구입하셨습니다");
				Sleep(1000);
				_item->Gold -= _item->item6.price;
				itemchoice6 = 1;
			}
		}
		else if (a == 3 && _item->Gold < _item->item6.price)
		{
			printf_s("골드가 부족합니다.");
			Sleep(1000);
		}

		system("cls");

		if (a == 4)
		{
			break;
		}
	}

	

	return itemchoice4, itemchoice5, itemchoice6;
}



int InventoryScene(OBJECT* _Player, Iventory* _item)
{
	int att = 0;
	int dff = 0;
	
	printf_s("소지골드 %d\n\n", _item->Gold);
	
	if (itemchoice1 == 1)

	if (itemchoice1 == 1)
	{
			printf_s("싸구려검 을 착용 하시겠습니까?\n");
			printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
			int a = 0;
			scanf("%d", &a);
			system("cls");
			if (a == 1 && inventorycountweapon == 0)
			{
				printf_s("싸구려검 을 착용하였습니다.\n");
				Sleep(1000);
				att = _Player->Info.ITEMATT += _item->item1.itematt;
				++inventorycountweapon;
			}
			else if (a == 1 && inventorycountweapon == 1)
			{
				printf_s("무기를 이미착용중입니다.");
				Sleep(1000);
			}
			else if (a == 2 && inventorycountweapon == 1)
			{
				printf_s("무기를 해제합니다.\n");
				Sleep(1000);
				att = _Player->Info.ITEMATT -= _item->item1.itematt;
				--inventorycountweapon;
			}
			system("cls");
	}

	if (itemchoice2 == 1)
	{
		printf_s("보통검 을 착용 하시겠습니까?\n");
		printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
		int a = 0;
		scanf("%d", &a);
		system("cls");
		if (a == 1 && inventorycountweapon == 0)
		{
			printf_s("보통검 착용하였습니다.\n");
			Sleep(1000);
			att = _Player->Info.ITEMATT += _item->item2.itematt;
			++inventorycountweapon;
		}
		else if (a == 1 && inventorycountweapon == 1)
		{
			printf_s("무기를 이미착용중입니다.");
			Sleep(1000);
			system("cls");
		}
		else if (a == 2 && inventorycountweapon == 1)
		{
			printf_s("무기를 해제합니다.\n");
			Sleep(1000);
			att = _Player->Info.ITEMATT -= _item->item2.itematt;
			--inventorycountweapon;
		}
		system("cls");
	}

	if (itemchoice3 == 1)
	{
		printf_s("나이스검 을 착용 하시겠습니까?\n");
		printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
		int a = 0;
		scanf("%d", &a);
		system("cls");
		if (a == 1 && inventorycountweapon == 0)
		{
			printf_s("나이스검 착용하였습니다.\n");
			Sleep(1000);
			att = _Player->Info.ITEMATT += _item->item3.itematt;
			++inventorycountweapon;
		}
		else if (a == 1 && inventorycountweapon == 1)
		{
			printf_s("무기를 이미착용중입니다.");
			Sleep(1000);
			system("cls");
		}
		else if (a == 2 && inventorycountweapon == 1)
		{
			printf_s("무기를 해제합니다.\n");
			Sleep(1000);
			att = _Player->Info.ITEMATT -= _item->item3.itematt;
			--inventorycountweapon;
		}
		system("cls");
	}

	if (itemchoice4 == 1)
	{
		printf_s("싸구려방어구 을 착용 하시겠습니까?\n");
		printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
		int a = 0;
		scanf("%d", &a);
		system("cls");
		if (a == 1 && inventorycountamor == 0)
		{
			printf_s("싸구려방어구 착용하였습니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF += _item->item4.itemdff;
			++inventorycountamor;
		}
		else if (a == 1 && inventorycountamor == 1)
		{
			printf_s("방어구를 이미착용중입니다.");
			Sleep(1000);
			system("cls");
		}
		else if (a == 2 && inventorycountamor == 1)
		{
			printf_s("방어구를 해제합니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF -= _item->item4.itemdff;
			--inventorycountamor;
		}
		system("cls");
	}

	if (itemchoice5 == 1)
	{
		printf_s("보통방어구 을 착용 하시겠습니까?\n");
		printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
		int a = 0;
		scanf("%d", &a);
		system("cls");
		if (a == 1 && inventorycountamor == 0)
		{
			printf_s("보통방어구 착용하였습니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF += _item->item5.itemdff;
			++inventorycountamor;
		}
		else if (a == 1 && inventorycountamor == 1)
		{
			printf_s("방어구를 이미착용중입니다.");
			Sleep(1000);
			system("cls");
		}
		else if (a == 2 && inventorycountamor == 1)
		{
			printf_s("방어구를 해제합니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF -= _item->item5.itemdff;
			--inventorycountamor;
		}
		system("cls");
	}

	if (itemchoice6 == 1)
	{
		printf_s("나이스방어구 을 착용 하시겠습니까?\n");
		printf_s("1, 착용\n2, 해제\n3, 다음아이템\n");
		int a = 0;
		scanf("%d", &a);
		system("cls");
		if (a == 1 && inventorycountamor == 0)
		{
			printf_s("나이스방어구 착용하였습니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF += _item->item6.itemdff;
			++inventorycountamor;
		}
		else if (a == 1 && inventorycountamor == 1)
		{
			printf_s("방어구를 이미착용중입니다.");
			Sleep(1000);
			system("cls");
		}
		else if (a == 2 && inventorycountamor == 1)
		{
			printf_s("방어구를 해제합니다.\n");
			Sleep(1000);
			dff = _Player->Info.ITEMDFF -= _item->item6.itemdff;
			--inventorycountamor;
		}
		system("cls");
	}

	printf_s("3, 다음아이템\n");
	printf_s("\n9, 나가기\n");
	int i = 0;
	scanf("%d", &i);
	
	if (i == 9)
	{
		SceneState = Scene_Menu;
	}
	
	system("cls");

	return att, dff;
}



void InitializeItem1(Iventory* _item)
{
	_item->Gold = 0;

	_item->item1.itemname = (char*)"싸구려검";
	_item->item1.itematt = 10;
	_item->item1.price = 100;

	_item->item2.itemname = (char*)"보통검";
	_item->item2.itematt = 100;
	_item->item2.price = 1000;

	_item->item3.itemname = (char*)"나이스검";
	_item->item3.itematt = 1000;
	_item->item3.price = 10000;

	_item->item4.itemname = (char*)"싸구려방어구";
	_item->item4.itemdff = 10;
	_item->item4.price = 100;

	_item->item5.itemname = (char*)"보통방어구";
	_item->item5.itemdff = 100;
	_item->item5.price = 1000;

	_item->item6.itemname = (char*)"나이스방어구";
	_item->item6.itemdff = 1000;
	_item->item6.price = 10000;
}



void InitializePlayer(OBJECT* _Player)
{
	_Player->Name = SetName();

	_Player->Info.Att = 10;
	_Player->Info.ITEMATT = 0;
	_Player->Info.Def = 5;
	_Player->Info.ITEMDFF = 0;
	_Player->Info.EXP = 0;
	_Player->Info.HP = 100;
	_Player->Info.HPMAX = 100;
	_Player->Info.MP = 10;
	_Player->Info.MPMAX = 10;
	_Player->Info.Level = 1;
}

void levelup(OBJECT* _Player)
{
	if (_Player->Info.EXP >= levelupexp[_Player->Info.Level - 1])
	{
		printf_s("레벨업을 하였습니다!.");
		Sleep(1000);
		system("cls");
		_Player->Info.Level += 1;
		_Player->Info.Att *= 2;
		_Player->Info.Def *= 2;
		_Player->Info.EXP = 0;
		_Player->Info.HP *= 2;
		_Player->Info.HPMAX *= 2;
		_Player->Info.MP *= 2;
		_Player->Info.MPMAX *= 2;
	}
}



void PlayerSceneact1(OBJECT* _Player, OBJECT* _Enemy, Iventory* _item)
{
	printf_s("%s님\n", _Player->Name);
	printf_s("Player Level : %d\n", _Player->Info.Level);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	printf_s("Player MP : %d\n", _Player->Info.MP);
	printf_s("Player Att : %d\n", _Player->Info.Att);
	printf_s("Player itematt : %d\n", _Player->Info.ITEMATT);
	printf_s("Player Def : %d\n", _Player->Info.Def);
	printf_s("Player itemDef : %d\n", _Player->Info.ITEMDFF);
	printf_s("Player EXP : %d\n\n", _Player->Info.EXP);
	printf_s("보유 Gold : %d\n\n", _item->Gold);
	printf_s("1, 공격\n2, 방어\n3, 힐\n9, 도망가기\n입력 : ");
	

	int sPlayerChoice = 0;
	scanf("%d", &sPlayerChoice);
	printf_s("\n");

	if (sPlayerChoice == 1) //플레이어 공격
	{
		//삼항연산자로도 할수있음 최소값 줄수있음
		//_Player->Info.Att = (_Player->Info.Att <= 0 ? 1 : _Player->Info.Att;)
		if ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy->Info.Def / 5) <= 0)
		{
			--_Enemy->Info.HP;
			printf_s("데미지 : %d\n", 1);
			printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
		}
		else
		{
			_Enemy->Info.HP -= ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy->Info.Def / 5));
			printf_s("데미지 : %d\n", (_Player->Info.Att + _Player->Info.ITEMATT) - _Enemy->Info.Def / 5);
			printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
		}
		Sleep(1000);
		act1choice++;
		system("cls");
	}
	else if (sPlayerChoice == 2) //플레이어 방어
	{
		if (_Enemy->Info.Att > (_Player->Info.Def + _Player->Info.ITEMDFF))
		{
			_Player->Info.HP -= (_Enemy->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("입은 데미지 : %d\n", _Enemy->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}
		else
		{
			_Player->Info.HP -= 1;
			printf_s("입은 데미지 : %d\n", 1);
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}

		if (_Player->Info.HP <= 0)
		{
			_Enemy->Info.HP = _Enemy->Info.HPMAX;
			_Enemy->Info.MP = _Enemy->Info.MPMAX;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;

			_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);
			system("cls");
			printf_s("\n적에게 당했습니다.\n");
			printf_s("\n경험치를 잃었습니다.\n");
			act1choice = 9;
			Sleep(1000);
		}
		Sleep(1000);
		system("cls");

	}
	else if (sPlayerChoice == 3) //플레이어 힐
	{
		if (_Player->Info.MP >= 5 && _Player->Info.HP < _Player->Info.HPMAX)
		{
			pHealSkill(_Player);
			act1choice++;
		}
		else if (_Player->Info.HP >= _Player->Info.HPMAX)
		{
			printf_s("HP가 가득 찼습니다\n");
			Sleep(1000);
		}
		else
		{
			printf_s("MP가 부족합니다\n");
			Sleep(1000);
		}
		system("cls");
	}
    else if (sPlayerChoice == 9) //플레이어 도망
	{
		srand((unsigned int)time(NULL));
		int runaway = rand() % 3 + 1;
		if (runaway == 1)
		{
			printf_s("도망성공\n");
			Sleep(1000);
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			act1choice = 9;
		}
		else
		{
			printf_s("도망실패\n");
			Sleep(1000);
			act1choice++;
		}
	}

	//자동 마나회복
	if (sPlayerChoice == 3)
	{

	}
	else
	{
		if (_Player->Info.MP + 2 <= _Player->Info.MPMAX)
			_Player->Info.MP += 2;
		else if (_Player->Info.MP + 1 <= _Player->Info.MPMAX)
			_Player->Info.MP += 1;
	}
		

	//몬스터 처치시
	if (_Enemy->Info.HP <= 0)
	{
		srand((unsigned int)time(NULL));
		GetGold = rand() % (_Enemy->Info.GoldMax - _Enemy->Info.GoldMin + 1) + _Enemy->Info.GoldMin;
		_item->Gold += GetGold;
		_Player->Info.EXP += _Enemy->Info.EXP;
		levelup(_Player);

		printf_s("\n적을 처치하였습니다.\n");
		printf_s("획득 골드 : %d\n", GetGold);
		printf_s("획득 경험치 : %d\n", _Enemy->Info.EXP);
		Sleep(2000);
		
		_Enemy->Info.HP = _Enemy->Info.HPMAX;
		_Enemy->Info.MP = _Enemy->Info.MPMAX;
		_Player->Info.HP = _Player->Info.HPMAX;
		_Player->Info.MP = _Player->Info.MPMAX;

		act1choice = 9;
	}



}

void PlayerSceneact2(OBJECT* _Player, OBJECT* _Enemy1, Iventory* _item)
{
	printf_s("%s님\n", _Player->Name);
	printf_s("Player Level : %d\n", _Player->Info.Level);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	printf_s("Player MP : %d\n", _Player->Info.MP);
	printf_s("Player Att : %d\n", _Player->Info.Att);
	printf_s("Player itematt : %d\n", _Player->Info.ITEMATT);
	printf_s("Player Def : %d\n", _Player->Info.Def);
	printf_s("Player itemDef : %d\n", _Player->Info.ITEMDFF);
	printf_s("Player EXP : %d\n\n", _Player->Info.EXP);
	printf_s("보유 Gold : %d\n\n", _item->Gold);
	printf_s("1, 공격\n2, 방어\n3, 힐\n9, 도망가기\n입력 : ");


	int sPlayerChoice = 0;
	scanf("%d", &sPlayerChoice);
	printf_s("\n");

	if (sPlayerChoice == 1) //플레이어 공격
	{
		//삼항연산자로도 할수있음 최소값 줄수있음
		//_Player->Info.Att = (_Player->Info.Att <= 0 ? 1 : _Player->Info.Att;)
		if ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy1->Info.Def / 5) <= 0)
		{
			--_Enemy1->Info.HP;
			printf_s("데미지 : %d\n", 1);
			printf_s("Enemy HP : %d\n", _Enemy1->Info.HP);
		}
		else
		{
			_Enemy1->Info.HP -= ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy1->Info.Def / 5));
			printf_s("데미지 : %d\n", (_Player->Info.Att + _Player->Info.ITEMATT) - _Enemy1->Info.Def / 5);
			printf_s("Enemy HP : %d\n", _Enemy1->Info.HP);
		}
		Sleep(1000);
		act1choice++;
		system("cls");
	}
	else if (sPlayerChoice == 2) //플레이어 방어
	{
		if (_Enemy1->Info.Att > (_Player->Info.Def + _Player->Info.ITEMDFF))
		{
			_Player->Info.HP -= (_Enemy1->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("입은 데미지 : %d\n", _Enemy1->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}
		else
		{
			_Player->Info.HP -= 1;
			printf_s("입은 데미지 : %d\n", 1);
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}

		if (_Player->Info.HP <= 0)
		{
			_Enemy1->Info.HP = _Enemy1->Info.HPMAX;
			_Enemy1->Info.MP = _Enemy1->Info.MPMAX;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;

			_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);
			system("cls");
			printf_s("\n적에게 당했습니다.\n");
			printf_s("\n경험치를 잃었습니다.\n");
        	act1choice = 9;
			Sleep(1000);
		}

		Sleep(1000);
		system("cls");
	}
	else if (sPlayerChoice == 3) //플레이어 힐
	{
		if (_Player->Info.MP >= 5 && _Player->Info.HP < _Player->Info.HPMAX)
		{
			pHealSkill(_Player);
			act1choice++;
		}
		else if (_Player->Info.HP >= _Player->Info.HPMAX)
		{
			printf_s("HP가 가득 찼습니다\n");
			Sleep(1000);
		}
		else
		{
			printf_s("MP가 부족합니다\n");
			Sleep(1000);
		}
		system("cls");
	}
	else if (sPlayerChoice == 9) //플레이어 도망
	{
		srand((unsigned int)time(NULL));
		int runaway = rand() % 3 + 1;
		if (runaway == 1)
		{
			printf_s("도망성공\n");
			Sleep(1000);
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			act1choice = 9;
		}
		else
		{
			printf_s("도망실패\n");
			Sleep(1000);
			act1choice++;
		}
	}

	//자동 마나회복
	if (sPlayerChoice == 3)
	{

	}
	else
	{
		if (_Player->Info.MP + 2 <= _Player->Info.MPMAX)
			_Player->Info.MP += 2;
		else if (_Player->Info.MP + 1 <= _Player->Info.MPMAX)
			_Player->Info.MP += 1;
	}


	//몬스터 처치시
	if (_Enemy1->Info.HP <= 0)
	{
		srand((unsigned int)time(NULL));
		GetGold = rand() % (_Enemy1->Info.GoldMax - _Enemy1->Info.GoldMin + 1) + _Enemy1->Info.GoldMin;
		_item->Gold += GetGold;
		_Player->Info.EXP += _Enemy1->Info.EXP;
		levelup(_Player);

		printf_s("\n적을 처치하였습니다.\n");
		printf_s("획득 골드 : %d\n", GetGold);
		printf_s("획득 경험치 : %d\n", _Enemy1->Info.EXP);
		Sleep(2000);

		_Enemy1->Info.HP = _Enemy1->Info.HPMAX;
		_Enemy1->Info.MP = _Enemy1->Info.MPMAX;
		_Player->Info.HP = _Player->Info.HPMAX;
		_Player->Info.MP = _Player->Info.MPMAX;

		act1choice = 9;
	}



}

void PlayerSceneact3(OBJECT* _Player, OBJECT* _Enemy2, Iventory* _item)
{
	printf_s("%s님\n", _Player->Name);
	printf_s("Player Level : %d\n", _Player->Info.Level);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	printf_s("Player MP : %d\n", _Player->Info.MP);
	printf_s("Player Att : %d\n", _Player->Info.Att);
	printf_s("Player itematt : %d\n", _Player->Info.ITEMATT);
	printf_s("Player Def : %d\n", _Player->Info.Def);
	printf_s("Player itemDef : %d\n", _Player->Info.ITEMDFF);
	printf_s("Player EXP : %d\n\n", _Player->Info.EXP);
	printf_s("보유 Gold : %d\n\n", _item->Gold);
	printf_s("1, 공격\n2, 방어\n3, 힐\n9, 도망가기\n입력 : ");


	int sPlayerChoice = 0;
	scanf("%d", &sPlayerChoice);
	printf_s("\n");

	if (sPlayerChoice == 1) //플레이어 공격
	{
		//삼항연산자로도 할수있음 최소값 줄수있음
		//_Player->Info.Att = (_Player->Info.Att <= 0 ? 1 : _Player->Info.Att;)
		if ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy2->Info.Def / 5) <= 0)
		{
			--_Enemy2->Info.HP;
			printf_s("데미지 : %d\n", 1);
			printf_s("Enemy HP : %d\n", _Enemy2->Info.HP);
		}
		else
		{
			_Enemy2->Info.HP -= ((_Player->Info.Att + _Player->Info.ITEMATT) - (_Enemy2->Info.Def / 5));
			printf_s("데미지 : %d\n", (_Player->Info.Att + _Player->Info.ITEMATT) - _Enemy2->Info.Def / 5);
			printf_s("Enemy HP : %d\n", _Enemy2->Info.HP);
		}
		Sleep(1000);
		act1choice++;
		system("cls");
	}
	else if (sPlayerChoice == 2) //플레이어 방어
	{
		if (_Enemy2->Info.Att > (_Player->Info.Def + _Player->Info.ITEMDFF))
		{
			_Player->Info.HP -= (_Enemy2->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("입은 데미지 : %d\n", _Enemy2->Info.Att - (_Player->Info.Def + _Player->Info.ITEMDFF));
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}
		else
		{
			_Player->Info.HP -= 1;
			printf_s("입은 데미지 : %d\n", 1);
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}

		if (_Player->Info.HP <= 0)
		{
			_Enemy2->Info.HP = _Enemy2->Info.HPMAX;
			_Enemy2->Info.MP = _Enemy2->Info.MPMAX;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;

			_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);
			system("cls");
			printf_s("\n적에게 당했습니다.\n");
			printf_s("\n경험치를 잃었습니다.\n");
			act1choice = 9;
			Sleep(1000);
		}

		Sleep(1000);
		system("cls");
	}
	else if (sPlayerChoice == 3) //플레이어 힐
	{
		if (_Player->Info.MP >= 5 && _Player->Info.HP < _Player->Info.HPMAX)
		{
			pHealSkill(_Player);
			act1choice++;
		}
		else if (_Player->Info.HP >= _Player->Info.HPMAX)
		{
			printf_s("HP가 가득 찼습니다\n");
			Sleep(1000);
		}
		else
		{
			printf_s("MP가 부족합니다\n");
			Sleep(1000);
		}
		system("cls");
	}
	else if (sPlayerChoice == 9) //플레이어 도망
	{
		srand((unsigned int)time(NULL));
		int runaway = rand() % 3 + 1;
		if (runaway == 1)
		{
			printf_s("도망성공\n");
			Sleep(1000);
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			act1choice = 9;
		}
		else
		{
			printf_s("도망실패\n");
			Sleep(1000);
			act1choice++;
		}
	}

	//자동 마나회복
	if (sPlayerChoice == 3)
	{

	}
	else
	{
		if (_Player->Info.MP + 2 <= _Player->Info.MPMAX)
			_Player->Info.MP += 2;
		else if (_Player->Info.MP + 1 <= _Player->Info.MPMAX)
			_Player->Info.MP += 1;
	}


	//몬스터 처치시
	if (_Enemy2->Info.HP <= 0)
	{
		srand((unsigned int)time(NULL));
		GetGold = rand() % (_Enemy2->Info.GoldMax - _Enemy2->Info.GoldMin + 1) + _Enemy2->Info.GoldMin;
		_item->Gold += GetGold;
		_Player->Info.EXP += _Enemy2->Info.EXP;
		levelup(_Player);

		printf_s("\n적을 처치하였습니다.\n");
		printf_s("획득 골드 : %d\n", GetGold);
		printf_s("획득 경험치 : %d\n", _Enemy2->Info.EXP);
		Sleep(2000);

		_Enemy2->Info.HP = _Enemy2->Info.HPMAX;
		_Enemy2->Info.MP = _Enemy2->Info.MPMAX;
		_Player->Info.HP = _Player->Info.HPMAX;
		_Player->Info.MP = _Player->Info.MPMAX;

		act1choice = 9;
	}



}



void InitializeEnemy(OBJECT* _Enemy)
{
	_Enemy->Name = (char*)"약한적";

	_Enemy->Info.Att = 10;
	_Enemy->Info.Def = 25;
	_Enemy->Info.EXP = 50;
	_Enemy->Info.HP = 30;
	_Enemy->Info.HPMAX = 30;
	_Enemy->Info.MP = 5;
	_Enemy->Info.MPMAX = 5;
	_Enemy->Info.Level = 1;
	_Enemy->Info.GoldMin = 20;
	_Enemy->Info.GoldMax = 40;
}

void InitializeEnemy1(OBJECT* _Enemy1)
{
	_Enemy1->Name = (char*)"보통적";
		  
	_Enemy1->Info.Att = 100;
	_Enemy1->Info.Def = 200;
	_Enemy1->Info.EXP = 500;
	_Enemy1->Info.HP = 200;
	_Enemy1->Info.HPMAX = 200;
	_Enemy1->Info.MP = 10;
	_Enemy1->Info.MPMAX = 10;
	_Enemy1->Info.Level = 10;
	_Enemy1->Info.GoldMin = 50;
	_Enemy1->Info.GoldMax = 200;
}

void InitializeEnemy2(OBJECT* _Enemy2)
{
	_Enemy2->Name = (char*)"강한적";
		  
	_Enemy2->Info.Att = 1000;
	_Enemy2->Info.Def = 2000;
	_Enemy2->Info.EXP = 5000;
	_Enemy2->Info.HP = 3000;
	_Enemy2->Info.HPMAX = 3000;
	_Enemy2->Info.MP = 30;
	_Enemy2->Info.MPMAX = 30;
	_Enemy2->Info.Level = 50;
	_Enemy2->Info.GoldMin = 500;
	_Enemy2->Info.GoldMax = 1000;
}		  



void EnemySceneact1(OBJECT* _Enemy, OBJECT* _Player, Iventory* _item)
{

	printf_s("적 차례 입니다.\n");
    Sleep(1000);
	system("cls");
	printf_s("%s\n", _Enemy->Name);
	printf_s("Enemy Level : %d\n", _Enemy->Info.Level);
	printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
	printf_s("Enemy MP : %d\n", _Enemy->Info.MP);
	printf_s("Enemy Att : %d\n", _Enemy->Info.Att);
	printf_s("Enemy Def : %d\n", _Enemy->Info.Def);
	printf_s("Enemy EXP : %d\n\n", _Enemy->Info.EXP);
	Sleep(1000);
	
	srand((unsigned int)time(NULL));
	int sEnemyChoice = rand() % 2 + 1;
	while (true)               ///// while 문을 쓰는 이유 else if 에서 else 문에 sEnemyChoice = 1; 해줘도 코드순서상 다시 맨위로 올라 랜덤 초기화를
	{                          ///// 해주기 때문에 아무의미가 없는데 와일문으로 랜덤함수보다 밑에 둬서 와일문부터 돌게해서 해결
		if (sEnemyChoice == 1) //에너미 공격
		{
			printf_s("적이 공격합니다.\n");
			Sleep(1000);
			if (_Enemy->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5) <= 0)
			{
				--_Player->Info.HP;
				printf_s("데미지 : %d\n", 1);
				printf_s("Enemy HP : %d\n", _Player->Info.HP);
			}
			else
			{
				_Player->Info.HP -= (_Enemy->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("데미지 : %d\n", _Enemy->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("Player HP : %d\n", _Player->Info.HP);
			}

			if (_Player->Info.HP <= 0) //플레이어 죽음
			{
				_Enemy->Info.HP = _Enemy->Info.HPMAX;
				_Enemy->Info.MP = _Enemy->Info.MPMAX;
				_Player->Info.HP = _Player->Info.HPMAX;
				_Player->Info.MP = _Player->Info.MPMAX;

				_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);
				
				Sleep(1000);
				system("cls");
				printf_s("\n적에게 당했습니다.\n");
				printf_s("\n경험치를 잃었습니다.\n");
				Sleep(2000);
				

				act1choice = 9;
				break;
			}

			Sleep(1000);
			act1choice = 0;
			system("cls");
			break;
		}
		else if (sEnemyChoice == 2) //에너미 힐
		{
			if (_Enemy->Info.MP >= 5 && _Enemy->Info.HP < _Enemy->Info.HPMAX)
			{
				mHealSkill(_Enemy);
				act1choice = 0;
				system("cls");
				break;
			}
			else if (_Enemy->Info.HP >= _Enemy->Info.HPMAX)
			{
				sEnemyChoice = 1;
			}
			else
			{
				printf_s("MP가 부족합니다\n");
				Sleep(1000);
				sEnemyChoice = 1;
			}
		}
	}
}

void EnemySceneact2(OBJECT* _Enemy1, OBJECT* _Player, Iventory* _item)
{
	printf_s("적 차례 입니다.\n");
	Sleep(1000);
	system("cls");
	printf_s("%s\n", _Enemy1->Name);
	printf_s("Enemy Level : %d\n", _Enemy1->Info.Level);
	printf_s("Enemy HP : %d\n", _Enemy1->Info.HP);
	printf_s("Enemy MP : %d\n", _Enemy1->Info.MP);
	printf_s("Enemy Att : %d\n", _Enemy1->Info.Att);
	printf_s("Enemy Def : %d\n", _Enemy1->Info.Def);
	printf_s("Enemy EXP : %d\n\n", _Enemy1->Info.EXP);
	Sleep(1000);

	srand((unsigned int)time(NULL));
	int sEnemyChoice = rand() % 2 + 1;
	while (true)               ///// while 문을 쓰는 이유 else if 에서 else 문에 sEnemyChoice = 1; 해줘도 코드순서상 다시 맨위로 올라 랜덤 초기화를
	{                          ///// 해주기 때문에 아무의미가 없는데 와일문으로 랜덤함수보다 밑에 둬서 와일문부터 돌게해서 해결
		if (sEnemyChoice == 1) //에너미 공격
		{
			printf_s("적이 공격합니다.\n");
			Sleep(1000);
			if (_Enemy1->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5) <= 0)
			{
				--_Player->Info.HP;
				printf_s("데미지 : %d\n", 1);
				printf_s("Enemy HP : %d\n", _Player->Info.HP);
			}
			else
			{
				_Player->Info.HP -= (_Enemy1->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("데미지 : %d\n", _Enemy1->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("Player HP : %d\n", _Player->Info.HP);
			}

			if (_Player->Info.HP <= 0) //플레이어 죽음
			{
				_Enemy1->Info.HP = _Enemy1->Info.HPMAX;
				_Enemy1->Info.MP = _Enemy1->Info.MPMAX;
				_Player->Info.HP = _Player->Info.HPMAX;
				_Player->Info.MP = _Player->Info.MPMAX;

				_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);

				Sleep(1000);
				system("cls");
				printf_s("\n적에게 당했습니다.\n");
				printf_s("\n경험치를 잃었습니다.\n");
				Sleep(2000);


				act1choice = 9;
				break;
			}

			Sleep(1000);
			act1choice = 0;
			system("cls");
			break;
		}
		else if (sEnemyChoice == 2) //에너미 힐
		{
			if (_Enemy1->Info.MP >= 5 && _Enemy1->Info.HP < _Enemy1->Info.HPMAX)
			{
				mHealSkill(_Enemy1);
				act1choice = 0;
				system("cls");
				break;
			}
			else if (_Enemy1->Info.HP >= _Enemy1->Info.HPMAX)
			{
				sEnemyChoice = 1;
			}
			else
			{
				printf_s("MP가 부족합니다\n");
				Sleep(1000);
				sEnemyChoice = 1;
			}
		}
	}
}

void EnemySceneact3(OBJECT* _Enemy2, OBJECT* _Player, Iventory* _item)
{
	printf_s("적 차례 입니다.\n");
	Sleep(1000);
	system("cls");
	printf_s("%s\n", _Enemy2->Name);
	printf_s("Enemy Level : %d\n", _Enemy2->Info.Level);
	printf_s("Enemy HP : %d\n", _Enemy2->Info.HP);
	printf_s("Enemy MP : %d\n", _Enemy2->Info.MP);
	printf_s("Enemy Att : %d\n", _Enemy2->Info.Att);
	printf_s("Enemy Def : %d\n", _Enemy2->Info.Def);
	printf_s("Enemy EXP : %d\n\n", _Enemy2->Info.EXP);
	Sleep(1000);

	srand((unsigned int)time(NULL));
	int sEnemyChoice = rand() % 2 + 1;
	while (true)               ///// while 문을 쓰는 이유 else if 에서 else 문에 sEnemyChoice = 1; 해줘도 코드순서상 다시 맨위로 올라 랜덤 초기화를
	{                          ///// 해주기 때문에 아무의미가 없는데 와일문으로 랜덤함수보다 밑에 둬서 와일문부터 돌게해서 해결
		if (sEnemyChoice == 1) //에너미 공격
		{
			printf_s("적이 공격합니다.\n");
			Sleep(1000);
			if (_Enemy2->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5) <= 0)
			{
				--_Player->Info.HP;
				printf_s("데미지 : %d\n", 1);
				printf_s("Enemy HP : %d\n", _Player->Info.HP);
			}
			else
			{
				_Player->Info.HP -= (_Enemy2->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("데미지 : %d\n", _Enemy2->Info.Att - ((_Player->Info.Def + _Player->Info.ITEMDFF) / 5));
				printf_s("Player HP : %d\n", _Player->Info.HP);
			}

			if (_Player->Info.HP <= 0) //플레이어 죽음
			{
				_Enemy2->Info.HP = _Enemy2->Info.HPMAX;
				_Enemy2->Info.MP = _Enemy2->Info.MPMAX;
				_Player->Info.HP = _Player->Info.HPMAX;
				_Player->Info.MP = _Player->Info.MPMAX;

				_Player->Info.EXP -= (int)(_Player->Info.EXP * 0.1f);

				Sleep(1000);
				system("cls");
				printf_s("\n적에게 당했습니다.\n");
				printf_s("\n경험치를 잃었습니다.\n");
				Sleep(2000);


				act1choice = 9;
				break;
			}

			Sleep(1000);
			act1choice = 0;
			system("cls");
			break;
		}
		else if (sEnemyChoice == 2) //에너미 힐
		{
			if (_Enemy2->Info.MP >= 5 && _Enemy2->Info.HP < _Enemy2->Info.HPMAX)
			{
				mHealSkill(_Enemy2);
				act1choice = 0;
				system("cls");
				break;
			}
			else if (_Enemy2->Info.HP >= _Enemy2->Info.HPMAX)
			{
				sEnemyChoice = 1;
			}
			else
			{
				printf_s("MP가 부족합니다\n");
				Sleep(1000);
				sEnemyChoice = 1;
			}
		}
	}
}



void pHealSkill(OBJECT* _Player)
{
	_Player->Info.MP -= 5;
	if (_Player->Info.HP + 10 <= _Player->Info.HPMAX) 
	{
		printf_s("힐량 : %d\n", 10);
		_Player->Info.HP += 10;
	}
	else if (_Player->Info.HP + 10 > _Player->Info.HPMAX && _Player->Info.HP < _Player->Info.HPMAX)
	{
		printf_s("힐량 : %d\n", _Player->Info.HPMAX - _Player->Info.HP);
		_Player->Info.HP += _Player->Info.HPMAX - _Player->Info.HP;
	}
	
	printf_s("Player HP : %d\n", _Player->Info.HP);
	Sleep(1000);
}

void mHealSkill(OBJECT* _Enemy)
{
	_Enemy->Info.MP -= 5;
	if (_Enemy->Info.HP + 10 <= _Enemy->Info.HPMAX)
	{
		printf_s("힐량 : %d\n", 10);
		_Enemy->Info.HP += 10;
	}
	else if (_Enemy->Info.HP + 10 > _Enemy->Info.HPMAX && _Enemy->Info.HP < _Enemy->Info.HPMAX)
	{
		printf_s("힐량 : %d\n", _Enemy->Info.HPMAX - _Enemy->Info.HP);
		_Enemy->Info.HP += _Enemy->Info.HPMAX - _Enemy->Info.HP;
	}
	
	printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
	Sleep(1000);
}

void SetPosition(short _x, short _y, char* _str, int _Color)
{
	COORD Pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	SetColor(_Color);

	printf_s("%s", _str);
}

void SetColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}
