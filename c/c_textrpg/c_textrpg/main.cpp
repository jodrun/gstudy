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



typedef struct _Iventory
{
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
	int Def;

	short Level;
	
	short GoldMin;
	short GoldMax;
}INFO;

typedef struct tagObject
{
	char* Name;
	Iventory iIventory;
	INFO Info;

}OBJECT;



void SceneManager(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2);
char* SetName();

void LogoScene();
void MenuScene();
void StageScene(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2);
void act1(OBJECT* _Player, OBJECT* _Enemy);
void act2(OBJECT* _Player, OBJECT* _Enemy1);
void act3(OBJECT* _Player, OBJECT* _Enemy2);
void StoreScene();
void InventoryScene();

void InitializePlayer(OBJECT* _Player);
void PlayerSceneact1(OBJECT* _Player, OBJECT* _Enemy);
void PlayerSceneact2(OBJECT* _Player, OBJECT* _Enemy1);
void PlayerSceneact3(OBJECT* _Player, OBJECT* _Enemy2);
void InitializeEnemy(OBJECT* _Enemy);
void InitializeEnemy1(OBJECT* _Enemy1);
void InitializeEnemy2(OBJECT* _Enemy2);
void EnemySceneact1(OBJECT* _Enemy, OBJECT* _Player);
void EnemySceneact2(OBJECT* _Enemy1, OBJECT* _Player);
void EnemySceneact3(OBJECT* _Enemy2, OBJECT* _Player);

void pHealSkill(OBJECT* _Player);
void mHealSkill(OBJECT* _Enemy);

void SetPosition(int _x, int _y, char* _str, int _Color = 15);
void SetColor(int _Color);







int main(void)
{
	system("mode con:cols=120 lines=30");
	system("title Ȳ�簩 textrpg");

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


	DWORD dwTime = GetTickCount();
	int Delay = 1000;

	while (true)
	{
		if (dwTime + Delay < GetTickCount())
		{
			dwTime = GetTickCount();

		
			system("cls");
			printf_s("%s��\n\n", Player->Name);

			// ** ���� ����
			SceneManager(Player, Monster, Monster1, Monster2);
		}
	}


	return 0;
}







void SceneManager(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2)
{
	switch (SceneState)
	{
	case Scene_Menu:
		MenuScene();
		break;
	case Scene_Stage:
		StageScene(_Player, _Enemy, _Enemy1, _Enemy2);
		break;
	case Scene_Store:
		StoreScene();
		break;
	case Scene_Inventory:
		InventoryScene();
		break;
	case Scene_Exit:

		exit(NULL);
		break;
	}
}

char* SetName()
{
	char Buffer[128] = "";
	printf_s("�̸� �Է� : ");
	scanf("%s", Buffer);
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);
	return pName;
}

void LogoScene()
{
	int Width = (120 / 2) - (strlen(" ####                      ") / 2);
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
	printf_s("���θ޴�\n\n");

	printf_s("1. ��������\n2. ����\n3. ����\n4. ����\n\n�Է� : ");

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

void StageScene(OBJECT* _Player, OBJECT* _Enemy, OBJECT* _Enemy1, OBJECT* _Enemy2)
{
	printf_s("���������� ������\n\n");
	printf_s("1, ��������1(����)\n");
	printf_s("2, ��������2(����)\n");
	printf_s("3, ��������3(�����)\n");
	printf_s("4, ���θ޴��� ����\n\n");
	printf_s("�Է� : ");
	scanf("%d", &iStageScene);
	system("cls");

	if (iStageScene == 1)
	{
		act1(_Player, _Enemy);
	}
	else if (iStageScene == 2)
	{
		act2(_Player, _Enemy1);
	}
	else if (iStageScene == 3)
	{
		act3(_Player, _Enemy2);
	}
	else if (iStageScene == 4)
	{
		SceneState--;
	}
}

void act1(OBJECT* _Player, OBJECT* _Enemy)
{

	printf_s("1, ��������1(����)\n\n");
	Sleep(2000);
	system("cls");
	act1choice = 0;

	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact1(_Player, _Enemy);
		}
		else if (act1choice == 1)
		{
			EnemySceneact1(_Enemy, _Player);
		}
		else if (act1choice == 9) //��������
		{
			break;
		}
		GetGold = 0;
	}
}

void act2(OBJECT* _Player, OBJECT* _Enemy1)
{
	printf_s("2, ��������2(����)\n\n");
	Sleep(2000);
	system("cls");
	act1choice = 0;

	
	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact2(_Player, _Enemy1);
		}
		else if (act1choice == 1)
		{
			EnemySceneact2(_Enemy1, _Player);
		}
		else if (act1choice == 9) //��������
		{
			break;
		}
		GetGold = 0;
	}
}

void act3(OBJECT* _Player, OBJECT* _Enemy2)
{
	printf_s("3, ��������3(�����)\n\n");
	Sleep(2000);
	system("cls");
	act1choice = 0;

	while (true)
	{
		if (act1choice == 0)
		{
			PlayerSceneact3(_Player, _Enemy2);
		}
		else if (act1choice == 1)
		{
			EnemySceneact3(_Enemy2, _Player);
		}
		else if (act1choice == 9) //��������
		{
			break;
		}
		GetGold = 0;
	}

}

void StoreScene()
{
	
}

void InventoryScene()
{
	
}

void InitializePlayer(OBJECT* _Player)
{
	_Player->Name = SetName();

	_Player->Info.Att = 30;
	_Player->Info.Def = 10;
	_Player->Info.EXP = 0;
	_Player->Info.HP = 100;
	_Player->Info.HPMAX = 100;
	_Player->Info.MP = 10;
	_Player->Info.MPMAX = 10;
	_Player->Info.Level = 1;
	_Player->iIventory.Gold = 0;
}

void PlayerSceneact1(OBJECT* _Player, OBJECT* _Enemy)
{
	printf_s("%s��\n", _Player->Name);
	printf_s("Player Level : %d\n", _Player->Info.Level);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	printf_s("Player MP : %d\n", _Player->Info.MP);
	printf_s("Player Att : %d\n", _Player->Info.Att);
	printf_s("Player Def : %d\n", _Player->Info.Def);
	printf_s("Player EXP : %d\n\n", _Player->Info.EXP);
	printf_s("���� Gold : %d\n\n", _Player->iIventory.Gold);
	printf_s("1, ����\n2, ���\n3, ��\n9, ��������\n�Է� : ");
	

	int sPlayerChoice = 0;
	scanf("%d", &sPlayerChoice);
	printf_s("\n");

	if (sPlayerChoice == 1) //�÷��̾� ����
	{
		//���׿����ڷε� �Ҽ����� �ּҰ� �ټ�����
		//_Player->Info.Att = (_Player->Info.Att <= 0 ? 1 : _Player->Info.Att;)
		if (_Player->Info.Att - (_Enemy->Info.Def / 5) <= 0)
		{
			--_Enemy->Info.HP;
			printf_s("������ : %d\n", 1);
			printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
		}
		else
		{
			_Enemy->Info.HP -= (_Player->Info.Att - (_Enemy->Info.Def / 5));
			printf_s("������ : %d\n", _Player->Info.Att - _Enemy->Info.Def / 5);
			printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
		}
		Sleep(2000);
		act1choice++;
		system("cls");
	}
	else if (sPlayerChoice == 2) //�÷��̾� ���
	{
		if (_Enemy->Info.Att > _Player->Info.Def)
		{
			_Player->Info.HP -= (_Enemy->Info.Att - _Player->Info.Def);
			printf_s("���� ������ : %d\n", _Enemy->Info.Att - _Player->Info.Def);
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}
		else
		{
			_Player->Info.HP -= 2;
			printf_s("���� ������ : %d\n", 2);
			printf_s("Player HP : %d\n", _Player->Info.HP);
		}
		Sleep(2000);
		system("cls");
	}
	else if (sPlayerChoice == 3) //�÷��̾� ��
	{
		if (_Player->Info.MP >= 5 && _Player->Info.HP < _Player->Info.HPMAX)
		{
			pHealSkill(_Player);
			act1choice++;
		}
		else if (_Player->Info.HP >= _Player->Info.HPMAX)
		{
			printf_s("HP�� ���� á���ϴ�\n");
			Sleep(2000);
		}
		else
		{
			printf_s("MP�� �����մϴ�\n");
			Sleep(2000);
		}
		system("cls");
	}
    else if (sPlayerChoice == 9) //�÷��̾� ����
	{
		srand(time(NULL));
		int runaway = rand() % 3 + 1;
		if (runaway == 1)
		{
			printf_s("��������\n");
			Sleep(2000);
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			act1choice = 9;
		}
		else
		{
			printf_s("��������\n");
			Sleep(2000);
			act1choice++;
		}
	}

	//�ڵ� ����ȸ��
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
		

	//���� óġ��
	if (_Enemy->Info.HP <= 0)
	{
		srand(time(NULL));
		GetGold = rand() % (_Enemy->Info.GoldMax - _Enemy->Info.GoldMin + 1) + _Enemy->Info.GoldMin;
		_Player->iIventory.Gold += GetGold;
		_Player->Info.EXP += _Enemy->Info.EXP;

		printf_s("\n���� óġ�Ͽ����ϴ�.\n");
		printf_s("ȹ�� ��� : %d\n", GetGold);
		printf_s("ȹ�� ����ġ : %d\n", _Enemy->Info.EXP);
		Sleep(3000);
		
		_Enemy->Info.HP = _Enemy->Info.HPMAX;
		_Enemy->Info.MP = _Enemy->Info.MPMAX;
		_Player->Info.HP = _Player->Info.HPMAX;
		_Player->Info.MP = _Player->Info.MPMAX;

		act1choice = 9;
	}



}

void PlayerSceneact2(OBJECT* _Player, OBJECT* _Enemy1)
{

}

void PlayerSceneact3(OBJECT* _Player, OBJECT* _Enemy2)
{

}

void InitializeEnemy(OBJECT* _Enemy)
{
	_Enemy->Name = (char*)"������";

	_Enemy->Info.Att = 10;
	_Enemy->Info.Def = 40;
	_Enemy->Info.EXP = 50;
	_Enemy->Info.HP = 30;
	_Enemy->Info.HPMAX = 30;
	_Enemy->Info.MP = 5;
	_Enemy->Info.MPMAX = 5;
	_Enemy->Info.Level = 1;
	_Enemy->Info.GoldMin = 5;
	_Enemy->Info.GoldMax = 30;
}

void InitializeEnemy1(OBJECT* _Enemy1)
{
	_Enemy1->Name = (char*)"������";
		  
	_Enemy1->Info.Att = 20;
	_Enemy1->Info.Def = 40;
	_Enemy1->Info.EXP = 50;
	_Enemy1->Info.HP = 30;
	_Enemy1->Info.HPMAX = 30;
	_Enemy1->Info.MP = 5;
	_Enemy1->Info.MPMAX = 5;
	_Enemy1->Info.Level = 1;
	_Enemy1->Info.GoldMin = 5;
	_Enemy1->Info.GoldMax = 30;
}

void InitializeEnemy2(OBJECT* _Enemy2)
{
	_Enemy2->Name = (char*)"������";
		  
	_Enemy2->Info.Att = 20;
	_Enemy2->Info.Def = 40;
	_Enemy2->Info.EXP = 50;
	_Enemy2->Info.HP = 30;
	_Enemy2->Info.HPMAX = 30;
	_Enemy2->Info.MP = 5;
	_Enemy2->Info.MPMAX = 5;
	_Enemy2->Info.Level = 1;
	_Enemy2->Info.GoldMin = 5;
	_Enemy2->Info.GoldMax = 30;
}		  


void EnemySceneact1(OBJECT* _Enemy, OBJECT* _Player)
{

	printf_s("�� ���� �Դϴ�.\n");
    Sleep(1500);
	system("cls");
	printf_s("%s\n", _Enemy->Name);
	printf_s("Enemy Level : %d\n", _Enemy->Info.Level);
	printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
	printf_s("Enemy MP : %d\n", _Enemy->Info.MP);
	printf_s("Enemy Att : %d\n", _Enemy->Info.Att);
	printf_s("Enemy Def : %d\n", _Enemy->Info.Def);
	printf_s("Enemy EXP : %d\n\n", _Enemy->Info.EXP);
	Sleep(3000);
	
	srand(time(NULL));
	int sEnemyChoice = rand() % 2 + 1;
	while (true)               ///// while ���� ���� ���� else if ���� else ���� sEnemyChoice = 1; ���൵ �ڵ������ �ٽ� ������ �ö� ���� �ʱ�ȭ��
	{                          ///// ���ֱ� ������ �ƹ��ǹ̰� ���µ� ���Ϲ����� �����Լ����� �ؿ� �ּ� ���Ϲ����� �����ؼ� �ذ�
		if (sEnemyChoice == 1) //���ʹ� ����
		{
			printf_s("���� �����մϴ�.\n");
			Sleep(1000);
			if (_Enemy->Info.Att - (_Player->Info.Def / 5) <= 0)
			{
				--_Player->Info.HP;
				printf_s("������ : %d\n", 1);
				printf_s("Enemy HP : %d\n", _Player->Info.HP);
			}
			else
			{
				_Player->Info.HP -= (_Enemy->Info.Att - (_Player->Info.Def / 5));
				printf_s("������ : %d\n", _Enemy->Info.Att - _Player->Info.Def / 5);
				printf_s("Player HP : %d\n", _Player->Info.HP);
			}

			if (_Player->Info.HP <= 0) //�÷��̾� ����
			{
				_Enemy->Info.HP = _Enemy->Info.HPMAX;
				_Enemy->Info.MP = _Enemy->Info.MPMAX;
				_Player->Info.HP = _Player->Info.HPMAX;
				_Player->Info.MP = _Player->Info.MPMAX;

				_Player->Info.EXP -= (_Player->Info.EXP * 0.1f);
				
				Sleep(2000);
				system("cls");
				printf_s("\n������ ���߽��ϴ�.\n");
				printf_s("\n����ġ�� �Ҿ����ϴ�.\n");
				Sleep(3000);
				

				act1choice = 9;
				break;
			}

			Sleep(2000);
			act1choice = 0;
			system("cls");
			break;
		}
		else if (sEnemyChoice == 2) //���ʹ� ��
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
				printf_s("MP�� �����մϴ�\n");
				Sleep(2000);
				sEnemyChoice = 1;
			}
		}
	}
}

void EnemySceneact2(OBJECT* _Enemy1, OBJECT* _Player)
{

}

void EnemySceneact3(OBJECT* _Enemy2, OBJECT* _Player)
{

}

void pHealSkill(OBJECT* _Player)
{
	_Player->Info.MP -= 5;
	if (_Player->Info.HP + 10 <= _Player->Info.HPMAX) 
	{
		printf_s("���� : %d\n", 10);
		_Player->Info.HP += 10;
	}
	else if (_Player->Info.HP + 10 > _Player->Info.HPMAX && _Player->Info.HP < _Player->Info.HPMAX)
	{
		printf_s("���� : %d\n", _Player->Info.HPMAX - _Player->Info.HP);
		_Player->Info.HP += _Player->Info.HPMAX - _Player->Info.HP;
	}
	
	printf_s("Player HP : %d\n", _Player->Info.HP);
	Sleep(2000);
}

void mHealSkill(OBJECT* _Enemy)
{
	_Enemy->Info.MP -= 5;
	if (_Enemy->Info.HP + 10 <= _Enemy->Info.HPMAX)
	{
		printf_s("���� : %d\n", 10);
		_Enemy->Info.HP += 10;
	}
	else if (_Enemy->Info.HP + 10 > _Enemy->Info.HPMAX && _Enemy->Info.HP < _Enemy->Info.HPMAX)
	{
		printf_s("���� : %d\n", _Enemy->Info.HPMAX - _Enemy->Info.HP);
		_Enemy->Info.HP += _Enemy->Info.HPMAX - _Enemy->Info.HP;
	}
	
	printf_s("Enemy HP : %d\n", _Enemy->Info.HP);
	Sleep(2000);
}

void SetPosition(int _x, int _y, char* _str, int _Color)
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
