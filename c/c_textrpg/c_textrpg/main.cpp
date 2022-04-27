#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <time.h>
#include <Windows.h>



const int Scene_Menu = 0;
const int Scene_Stage = 1;
const int Scene_Exit = 2;

int SceneState = 0;


typedef struct tagInfo
{
	int HP;
	int MP;

	int EXP;

	int Att;
	int Def;

	short Level;

}INFO;

typedef struct tagObject
{
	char* Name;
	INFO Info;

}OBJECT;



void SceneManager(OBJECT* _Player, OBJECT* _Enemy);
char* SetName();

void LogoScene();
void MenuScene();
void StageScene(OBJECT* _Player, OBJECT* _Enemy);

void InitializePlayer(OBJECT* _Player);
void PlayerScene(OBJECT* _Player);
void InitializeEnemy(OBJECT* _Enemy);
void EnemyScene(OBJECT* _Enemy);

void SetPosition(int _x, int _y, char* _str, int _Color = 15);
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
	
	
	Sleep(5000);
}

void MenuScene()
{
	printf_s("MenuScene\n");

	printf_s("1. 이동\n2. 종료\n입력 : ");

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
		SceneState++;
	else if (i == 2)
		SceneState = Scene_Exit;
}

void StageScene(OBJECT* _Player, OBJECT* _Enemy)
{
	// ** 전투
	PlayerScene(_Player);
	EnemyScene(_Enemy);
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
}

void PlayerScene(OBJECT* _Player)
{
	
}

void InitializeEnemy(OBJECT* _Enemy)
{
	_Enemy->Name = (char*)"Enemy";

	_Enemy->Info.Att = 5;
	_Enemy->Info.Def = 15;
	_Enemy->Info.EXP = 0;
	_Enemy->Info.HP = 30;
	_Enemy->Info.MP = 5;
	_Enemy->Info.Level = 1;
}

void EnemyScene(OBJECT* _Enemy)
{

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
