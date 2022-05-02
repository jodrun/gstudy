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
	int MP;

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



void SceneManager(OBJECT* _Player, OBJECT* _Enemy);
char* SetName();

void LogoScene();
void MenuScene();
void StageScene(OBJECT* _Player, OBJECT* _Enemy);
void act1(OBJECT* _Player, OBJECT* _Enemy);
void StoreScene();
void InventoryScene();

void InitializePlayer(OBJECT* _Player);
void PlayerScene(OBJECT* _Player, OBJECT* _Enemy);
void InitializeEnemy(OBJECT* _Enemy);
void EnemyScene(OBJECT* _Enemy, OBJECT* _Player);

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
			SceneManager(Player, Monster);
		}
	}


	return 0;
}



void SceneManager(OBJECT* _Player, OBJECT* _Enemy)
{
	switch (SceneState)
	{
	case Scene_Menu:
		MenuScene();
		break;
	case Scene_Stage:
		StageScene(_Player, _Enemy);
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

void StageScene(OBJECT* _Player, OBJECT* _Enemy)
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

	while (true)
	{
		if (act1choice == 0)
		{
			PlayerScene(_Player, _Enemy);
		}
		else if (act1choice == 1)
		{
			EnemyScene(_Enemy, _Player);
		}
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

	_Player->Info.Att = 10;
	_Player->Info.Def = 10;
	_Player->Info.EXP = 0;
	_Player->Info.HP = 100;
	_Player->Info.MP = 10;
	_Player->Info.Level = 1;
	_Player->iIventory.Gold = 0;
}

void PlayerScene(OBJECT* _Player, OBJECT* _Enemy)
{
	printf_s("%s��\n", _Player->Name);
	printf_s("Player Level : %d\n", _Player->Info.Level);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	printf_s("Player MP : %d\n", _Player->Info.MP);
	printf_s("Player Att : %d\n", _Player->Info.Att);
	printf_s("Player Def : %d\n", _Player->Info.Def);
	printf_s("Player EXP : %d\n\n", _Player->Info.EXP);
	printf_s("���� Gold : %d\n\n", _Player->iIventory.Gold);
	printf_s("1, ����\n2, ���\n3, ��\n�Է� : ");
	

	int sPlayerChoice = 0;
	scanf("%d", &sPlayerChoice);
	printf_s("\n");
	
	if (sPlayerChoice == 1) //�÷��̾� ����
	{
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
		if (_Player->Info.MP >= 5)
		{
			pHealSkill(_Player);
			act1choice++;
		}
		else
		{
			printf_s("MP�� �����մϴ�");
			Sleep(2000);
		}
		system("cls");
	}
	
}

void InitializeEnemy(OBJECT* _Enemy)
{
	_Enemy->Name = (char*)"��ũ";

	_Enemy->Info.Att = 5;
	_Enemy->Info.Def = 30;
	_Enemy->Info.EXP = 0;
	_Enemy->Info.HP = 30;
	_Enemy->Info.MP = 5;
	_Enemy->Info.Level = 1;
	_Enemy->Info.GoldMin = 5;
	_Enemy->Info.GoldMax = 30;
}

void EnemyScene(OBJECT* _Enemy, OBJECT* _Player)
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
			Sleep(2000);
			act1choice = 0;
			system("cls");
			break;
		}
		else if (sEnemyChoice == 2) //���ʹ� ��
		{
			if (_Enemy->Info.MP >= 5)
			{
				mHealSkill(_Enemy);
				act1choice = 0;
				system("cls");
				break;
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

void pHealSkill(OBJECT* _Player)
{
	_Player->Info.MP -= 5;
	_Player->Info.HP += 10;
	printf_s("���� : %d\n", 10);
	printf_s("Player HP : %d\n", _Player->Info.HP);
	Sleep(2000);
}

void mHealSkill(OBJECT* _Enemy)
{
	_Enemy->Info.MP -= 5;
	_Enemy->Info.HP += 10;
	printf_s("���� : %d\n", 10);
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
