#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;

struct Vector3
{
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3() {};
	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) { };
	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) { };

};

struct Trasnsform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Information
{
	char* Texture[4][3];

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

	short Gold;

	short GoldMin;
	short GoldMax;

	int Color;
	int Option;
};

struct Object
{
	char* Name;
	int Speed;
	int State;

	Information Info;
	Trasnsform TransInfo;
	Trasnsform attackscale;
};

struct DrawTextInfo
{
	Information Info;
	Trasnsform TransInfo;
};


bool bIsJumpping = false;     // 현재 점프 중인가
bool bIsJumpped = false;      // 현재 점프하여 최고 지점에 올랐는가
bool enemybIsJumpping = false;     
bool enemybIsJumpped = false;

const int Idle = 0;
const int Attack = 1;
const int Down = 2;
const int hit = 3;
const int Move = 4;
 
float udo = 0;                  // 따라가기 (길이) 변수
Vector3 udo1 = { 0, 0, 0 };     // 따라가기 (방향) 변수

bool enemymoving = false;       // 적움직임
bool collisiontime = false;     // 충돌후 출력 딜레이 주기위함
bool collisiontime1 = false;    // 충돌후 출력 딜레이 주기위함
bool collisiontime2 = false;    // 충돌후 출력 딜레이 주기위함
bool playerattackbool = false;
bool bulletskill = false;

ULONGLONG Glovertime1;                 // 충돌 했을때 흐른 시간 (딜레이 주기위함)
ULONGLONG Glovertime2;
ULONGLONG Glovertime3;




void LogoScene();

void SceneManager(Object* _Player, Object* _Enemy, Object* _Bullet, ULONGLONG _Time1);

void StageScene(Object* _Player, Object* _Enemy, Object* _Bullet, ULONGLONG _Time1);

char* SetName();

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX = 0, float _PosY = 0, float _PosZ = 0, int _Anim = 0);

void InitializeStatus(Object* _Object, char* _name, int _HP, int _HPMAX, int _MP, int _MPMAX, int _EXP, int _Att, int _ITEMATT, int _Def, int _ITEMDFF, short _Level, short _Gold, short _GoldMax, short _GoldMin);

void UpdateInput(Object* _Object, Object* _Bullet);

void enemymove(Object* _enemy, Object* _player);

void enemymovestage(Object* _enemy, Object* _player);




void SetCursorPosition(const float _x, const float _y);

void SetTextColor(const int _Color);

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

void HideCursor(const bool _Visible);

float GetDistance(const Object* _ObjectA, const Object* _ObjectB);

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB);

bool Collision(const Object* _ObjectA, const Object* _ObjectB);

bool PlayerAttackCollision(Object* _ObjectA, Object* _ObjectB);

void CollisionStage(Object* _ObjectA, Object* _ObjectB, Object* _Bullet);

void enemyjumping(Object* _Object);

void palyerstatusdraw(Object* _Object);

void enemystatusdraw(Object* _Object);



int main(void)
{
	system("mode con:cols=120 lines=30");
	LogoScene();
	system("cls");

	Object* Player = new Object;
	// *************************플레이어 초기화****************************
	Player->Info.Texture[Idle][0] = (char*)" o   /";
	Player->Info.Texture[Idle][1] = (char*)"ㅁ /";
	Player->Info.Texture[Idle][2] = (char*)"11";

	Player->Info.Texture[Attack][0] = (char*)"  o    ";
	Player->Info.Texture[Attack][1] = (char*)" ㅁ  ㅡㅡ";
	Player->Info.Texture[Attack][2] = (char*)"／＼";

	Player->Info.Texture[Down][0] = (char*)"";
	Player->Info.Texture[Down][1] = (char*)"  ㅁ ㅇ";
	Player->Info.Texture[Down][2] = (char*)"┌ ┐";

	Player->Info.Texture[hit][0] = (char*)"ㅇ";
	Player->Info.Texture[hit][1] = (char*)"／ㅁ＼";
	Player->Info.Texture[hit][2] = (char*)"//";

	// ** 좌표값
	Player->TransInfo.Position = Vector3(35, 15, 0);

	// ** 회전값 (현재 사용되지 않음.)
	Player->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	Player->State = Idle;

	// ** 크기값
	Player->TransInfo.Scale = Vector3(
		(float)strlen(Player->Info.Texture[Idle][1]), 1.0f, 0.0f);
	// *********************************************************************
	InitializeStatus(Player, nullptr, 100, 100, 10, 10, 0, 20, 0, 10, 0, 1, 0, 0, 0);
	

	Object* Enemy[5];
	for (int i = 0; i < 5; ++i)
	{
		Enemy[i] = nullptr;
		Enemy[i] = new Object;
	}
 
	Initialize(Enemy[0], (char*)"ㅡㅡ", (char*)"   ㅣ", (char*)"    ㅡㅡ", 70, 15);
	Enemy[0]->State = Idle;
	Enemy[0]->Info.Texture[Attack][0] = (char*)" ㅡㅡ";
	Enemy[0]->Info.Texture[Attack][1] = (char*)"   ／";
	Enemy[0]->Info.Texture[Attack][2] = (char*)"   ㅡㅡ";
	InitializeStatus(Enemy[0], (char*)"지렁이", 150, 150, 5, 5, 50, 30, 0, 10, 0, 1, 0, 100, 10);

	Object* Bullet = new Object;
	Initialize(Bullet, (char*)"→", (char*)"", (char*)"", 0, 15);

	ULONGLONG Time = GetTickCount64();   //** 게임 메인 시간 딜레이
	ULONGLONG Time1 = GetTickCount64();  //** 에너미 제자리 움직임 딜레이
	

	while (true)
	{
		srand((unsigned int)time(NULL));

		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			SceneManager(Player, Enemy[0], Bullet, Time1);
		}
	}
	return 0;
}



void LogoScene()
{
	int Width = (120 / 2) - (int)(strlen("::::::::::: :::::::::: :::    ::: :::::::::::    :::::::::  :::::::::   ::::::::     :::::::       :::::::: ") / 2);
	int Height = 9;

    OnDrawText((char*)"::::::::::: :::::::::: :::    ::: :::::::::::    :::::::::  :::::::::   ::::::::     :::::::       ::::::::  ", Width, Height + 1, 10);
    OnDrawText((char*)"    :+:     :+:        :+:    :+:     :+:        :+:    :+: :+:    :+: :+:    :+:   :+:   :+:     :+:    :+: ", Width, Height + 2, 10);
    OnDrawText((char*)"    +:+     +:+         +:+  +:+      +:+        +:+    +:+ +:+    +:+ +:+          +:+  :+:+           +:+  ", Width, Height + 3, 10);
    OnDrawText((char*)"    +#+     +#++:++#     +#++:+       +#+        +#++:++#:  +#++:++#+  :#:          +#+ + +:+         +#+    ", Width, Height + 4, 10);
    OnDrawText((char*)"    +#+     +#+         +#+  +#+      +#+        +#+    +#+ +#+        +#+   +#+#   +#+#  +#+       +#+      ", Width, Height + 5, 10);
    OnDrawText((char*)"    #+#     #+#        #+#    #+#     #+#        #+#    #+# #+#        #+#    #+#   #+#   #+# #+#  #+#       ", Width, Height + 6, 10);
    OnDrawText((char*)"    ###     ########## ###    ###     ###        ###    ### ###         ########     #######  ### ########## ", Width, Height + 7, 10);

	Sleep(1000);
}

char* SetName()
{
	char Buffer[128] = "";

	OnDrawText((char*)"이름입력 : ", 50, 14, 15);
	cin >> Buffer;

	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return pName;
}

void SceneManager(Object* _Player, Object* _Enemy, Object* _Bullet, ULONGLONG _Time1)
{
	//나무 출력
	for (int tree = 0; tree < 7; ++tree)
	{
		OnDrawText((char*)"#######", 40, 17 - tree, 4);
	}
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~", 35, 10, 2);
	OnDrawText((char*)"~~~~~~~~~~~~~~~", 36, 9, 2);
	OnDrawText((char*)"~~~~~~~~~~~~~", 37, 8, 2);
	OnDrawText((char*)"~~~~~~~~~~~", 38, 7, 2);
	OnDrawText((char*)"~~~~~~~~~", 39, 6, 2);
	OnDrawText((char*)"~~~~~~~", 40, 5, 2);
	OnDrawText((char*)"~~~~~", 41, 4, 2);
	OnDrawText((char*)"~~~", 42, 3, 2);
	OnDrawText((char*)"~", 43, 2, 2);

	for (int tree = 0; tree < 7; ++tree)
	{
		OnDrawText((char*)"#######", 80, 17 - tree, 4);
	}
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~", 75, 10, 2);
	OnDrawText((char*)"~~~~~~~~~~~~~~~", 76, 9, 2);
	OnDrawText((char*)"~~~~~~~~~~~~~", 77, 8, 2);
	OnDrawText((char*)"~~~~~~~~~~~", 78, 7, 2);
	OnDrawText((char*)"~~~~~~~~~", 79, 6, 2);
	OnDrawText((char*)"~~~~~~~", 80, 5, 2);
	OnDrawText((char*)"~~~~~", 81, 4, 2);
	OnDrawText((char*)"~~~", 82, 3, 2);
	OnDrawText((char*)"~", 83, 2, 2);
	
	//상점 출력
	for (int i = 0; i < 6; ++i)
	{
		OnDrawText((char*)"∥                     ∥", 3, 18 - i, 15);
	}
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 1, 12, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~", 2, 11, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~", 3, 10, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~", 4, 9, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~", 5, 8, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~", 6, 7, 15);
	OnDrawText((char*)"ㅣ   ㅣ", 12, 17, 15);
	OnDrawText((char*)"ㅣ   ㅣ", 12, 16, 15);
	OnDrawText((char*)"ㅡㅡㅡ", 13, 15, 15);

	OnDrawText((char*)"ㅣㅣ", 27, 17, 15);
	OnDrawText((char*)"ㅣㅣ", 27, 16, 15);
	OnDrawText((char*)"----------", 24, 15, 15);
	OnDrawText((char*)"ㅣ", 23, 14, 15);
	OnDrawText((char*)"ㅣ", 33, 14, 15);
	OnDrawText((char*)"----------", 24, 13, 15);
	OnDrawText((char*)"상점", 27, 14, 15);
	
	//사냥터 간판 출력
	OnDrawText((char*)"ㅣㅣ", 110, 17, 15);
	OnDrawText((char*)"ㅣㅣ", 110, 16, 15);
	OnDrawText((char*)"----------", 107, 15, 15);
	OnDrawText((char*)"ㅣ", 106, 14, 15);
	OnDrawText((char*)"ㅣ", 116, 14, 15);
	OnDrawText((char*)"----------", 107, 13, 15);
	OnDrawText((char*)"스테이지", 108, 14, 15);
	
	//캐릭터 출력&키입력
	UpdateInput(_Player, _Bullet);
	for (int i = 0; i < 3; ++i)
	{
		OnDrawText(_Player->Info.Texture[_Player->State][i],
			_Player->TransInfo.Position.x,
			_Player->TransInfo.Position.y + i,
			10);
	}

	//바닥출력
	OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

	//사냥터 넘어가는 코드
	if (_Player->TransInfo.Position.x > 112)
	{
		system("cls");
		_Player->TransInfo.Position.x = 10;
        StageScene(_Player, _Enemy, _Bullet, _Time1);

	}

	//f키입력 코드
	OnDrawText((char*)"F : 상호작용", 0, 28, 15);
	if (GetAsyncKeyState(0x46) && _Player->TransInfo.Position.x >= 12 && _Player->TransInfo.Position.x <= (strlen("ㅣ   ㅣ") + 12))
	{
		exit(NULL);
	}

	//esc게임종료 코드
	OnDrawText((char*)"esc : 게임종료", 0, 29, 15);
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(NULL);
	}
}



void StageScene(Object* _Player, Object* _Enemy, Object* _Bullet, ULONGLONG _Time1)
{
	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		srand((unsigned int)time(NULL));
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 5;          //** 불렛 데미지 초기화
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** 불렛 데미지 초기화
			UpdateInput(_Player, _Bullet);

			udo = GetDistance(_Player, _Enemy);
			udo1 = GetDirection(_Player, _Enemy);

			enemymovestage(_Enemy, _Player);
			if (_Time1 + 350 < GetTickCount64())
			{
				_Enemy->State = Attack;
				if (_Time1 + 650 < GetTickCount64())
				{
					_Enemy->State = Idle;
					_Time1 = GetTickCount64();
				}
			}

			CollisionStage(_Player, _Enemy, _Bullet);
			enemyjumping(_Enemy);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player 출력
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			// ** Enemy 출력
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Enemy->Info.Texture[_Enemy->State][i],
					_Enemy->TransInfo.Position.x,
					_Enemy->TransInfo.Position.y + i,
					10);
			}

			palyerstatusdraw(_Player);
			enemystatusdraw(_Enemy);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			if (_Player->TransInfo.Position.x < 5)
			{
				_Player->TransInfo.Position.x = 110;
				break;
			}
		}
	}
}

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX, float _PosY, float _PosZ, int _Anim)
{
	_Object->Info.Texture[_Anim][0] = _Texture;
	_Object->Info.Texture[_Anim][1] = _Texture2;
	_Object->Info.Texture[_Anim][2] = _Texture3;

	_Object->Speed = 0;

	// ** 좌표값
	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);

	// ** 회전값 (현재 사용되지 않음.)
	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	// ** 크기값
	_Object->TransInfo.Scale = Vector3(
		(float)strlen(_Object->Info.Texture[_Anim][1]), 1.0f, 0.0f);
}

void InitializeStatus(Object* _Object, char* _name, int _HP, int _HPMAX, int _MP, int _MPMAX, int _EXP, int _Att, int _ITEMATT, int _Def, int _ITEMDFF, short _Level, short _Gold, short _GoldMax, short _GoldMin)
{
	_Object->Name = (_name == nullptr) ? SetName() : _name;
	_Object->Info.HP = _HP, _Object->Info.HPMAX = _HPMAX;
	_Object->Info.MP = _MP, _Object->Info.MPMAX = _MPMAX;
	_Object->Info.EXP = _EXP;
	_Object->Info.Att = _Att, _Object->Info.ITEMATT = _ITEMATT;
	_Object->Info.Def = _Def, _Object->Info.ITEMDFF = _ITEMDFF;
	_Object->Info.Level = _Level, _Object->Info.Gold = _Gold;
	_Object->Info.GoldMax = _GoldMax, _Object->Info.GoldMin = _GoldMin;
}

void UpdateInput(Object* _Object, Object* _Bullet)
{
	if (GetAsyncKeyState(VK_UP))
	{
		bIsJumpping = true;
	}
	
	if (bIsJumpping)
	{
		if (_Object->TransInfo.Position.y > 14 && bIsJumpped == false)
		{
			_Object->TransInfo.Position.y -= 4;
		}
		if (_Object->TransInfo.Position.y < 14)
		{
			bIsJumpped = true;
		}
		if (bIsJumpped == true)
		{
			_Object->TransInfo.Position.y ++;
		}
		if (bIsJumpped && _Object->TransInfo.Position.y == 15)
		{
			bIsJumpped = false;
			bIsJumpping = false;
		}	
	}

	if (GetAsyncKeyState(VK_DOWN))
		_Object->State = Down;
	else
		_Object->State = Idle;

	if (GetAsyncKeyState(VK_LEFT))
		_Object->TransInfo.Position.x -= 1;

	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.x += 1;

	if (GetAsyncKeyState(VK_SPACE))
	{
		_Object->State = Attack;
		playerattackbool = true;
		if (playerattackbool)
		{
			_Object->attackscale.Scale.x = (float)strlen(_Object->Info.Texture[Attack][1]);
		}
	}
	else
	{
		if (_Object->State != Down)
		{
			playerattackbool = false;
			_Object->attackscale.Scale.x = 0;
			_Object->State = Idle;
		}
		else if (_Object->State == Down)
		{
			playerattackbool = false;
			_Object->attackscale.Scale.x = 0;
		}
	}

	if (bulletskill != true)
	{
		if (GetAsyncKeyState(0x43) & 0x0001)
		{
			_Bullet->TransInfo.Position.x = _Object->TransInfo.Position.x + strlen(_Object->Info.Texture[Idle][1]) + 1;
			bulletskill = true;
		}
	}
}

void enemymove(Object* _enemy, Object* _player)
{
	if (udo <= 25)       // 플레이어, 적 거리가 25 이내로 가까워지면 접근하는 코드
	{
		int i = rand() % 7 + 1;
		if (_enemy->TransInfo.Position.x > _player->TransInfo.Position.x)
		{
			if (i == 3)
			{
				_enemy->TransInfo.Position.x -= 1;
			}
			else
			{
			    _enemy->TransInfo.Position.x -= 0.2;
			}
		}
		else if (_enemy->TransInfo.Position.x < _player->TransInfo.Position.x)
		{
			_enemy->TransInfo.Position.x += 0.2;
		}
		if (_enemy->TransInfo.Position.x <= 65)
			enemymoving = true;
	}
	else if (_enemy->TransInfo.Position.x > 5 && _enemy->TransInfo.Position.x >= 65 && enemymoving == false)
	{
		_enemy->TransInfo.Position.x -= 0.2;
		if (_enemy->TransInfo.Position.x <= 65)
			enemymoving = true;
	}
    else if (_enemy->TransInfo.Position.x < 115 || _enemy->TransInfo.Position.x <= 75 && enemymoving == true)
	{
		_enemy->TransInfo.Position.x += 0.2;
		if (_enemy->TransInfo.Position.x >= 75)
			enemymoving = false;
	}
}

void enemymovestage(Object* _enemy, Object* _player)
{
	enemymove(_enemy, _player);
}







void SetCursorPosition(const float _x, const float _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetTextColor(const int _Color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
	_itoa(_Value, pText, 10);
	cout << _Value;
}

void HideCursor(const bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}

float GetDistance(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectA->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	// ** sqrt : 제곱근 함수
	return sqrt((x * x) + (y * y));
}

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectA->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	float Distance = sqrt((x * x) + (y * y));

	return Vector3(x / Distance, y / Distance);
}

bool Collision(Object* _ObjectA, Object* _ObjectB)
{
	// ** (_Object->TransInfo.Position.x + _Object->TransInfo.Scale.x)   : 우측
	// ** _Object->TransInfo.Position.x   : 좌측
	// ** Rect 충돌시 우측선은 항상 크다.
	if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y)
		return true;
	return false;
}

bool PlayerAttackCollision(Object* _ObjectA, Object* _ObjectB)
{
	// ** (_Object->TransInfo.Position.x + _Object->TransInfo.Scale.x)   : 우측
	// ** _Object->TransInfo.Position.x   : 좌측
	// ** Rect 충돌시 우측선은 항상 크다.
	if ((_ObjectA->TransInfo.Position.x + _ObjectA->attackscale.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y)
		return true;
	return false;
}

void CollisionStage(Object* _ObjectA, Object* _ObjectB, Object* _Bullet)
{
	//**불렛 판정
	if (bulletskill)
	{
		if (Collision(_Bullet, _ObjectB))
		{
			Glovertime3 = GetTickCount64();
			collisiontime2 = true;
			bulletskill = false;

			if ((_Bullet->Info.Att + _Bullet->Info.ITEMATT) - (_ObjectB->Info.Def / 2) <= 0)
				--_ObjectB->Info.HP;
			else
			{
				_ObjectB->Info.HP -= ((_Bullet->Info.Att + _Bullet->Info.ITEMATT)) - (_ObjectB->Info.Def / 2);
			}
		}
		if (_Bullet->TransInfo.Position.x > 119)
		{
			bulletskill = false;
		}
	}

	//**플레이어가 공격 충돌판정
	if (playerattackbool && PlayerAttackCollision(_ObjectA, _ObjectB))
	{
		Glovertime2 = GetTickCount64();
		collisiontime1 = true;
		enemybIsJumpping = true;

		if ((_ObjectA->Info.Att + _ObjectA->Info.ITEMATT) - (_ObjectB->Info.Def / 2) <= 0)
			--_ObjectB->Info.HP;
		else
		{
			_ObjectB->Info.HP -= ((_ObjectA->Info.Att + _ObjectA->Info.ITEMATT)) - (_ObjectB->Info.Def / 2);
		}
	}

	//** 충돌판정
	if (Collision(_ObjectA, _ObjectB))
	{
		Glovertime1 = GetTickCount64();
		collisiontime = true;
		_ObjectA->State = hit;
		bIsJumpping = true;

		if ((_ObjectB->Info.Att + _ObjectB->Info.ITEMATT) - (_ObjectA->Info.Def) <= 0)
			--_ObjectA->Info.HP;
		else
		{
			_ObjectA->Info.HP -= ((_ObjectB->Info.Att + _ObjectB->Info.ITEMATT)) - (_ObjectA->Info.Def);
		}

		if (bIsJumpping)
		{
			if (_ObjectA->TransInfo.Position.y > 14 && bIsJumpped == false)
			{
				_ObjectA->TransInfo.Position.y -= 2;
			}
			if (_ObjectA->TransInfo.Position.y < 14)
			{
				bIsJumpped = true;
			}
			if (bIsJumpped == true)
			{
				_ObjectA->TransInfo.Position.y++;
			}
			if (bIsJumpped && _ObjectA->TransInfo.Position.y == 15)
			{
				bIsJumpped = false;
				bIsJumpping = false;
			}
			for (int j = 0; j < 7; ++j)
			{
				_ObjectA->TransInfo.Position.x += udo1.x;
			}
		}
	}
	
	if (collisiontime)
	{
		OnDrawText((_ObjectB->Info.Att + _ObjectB->Info.ITEMATT) - (_ObjectA->Info.Def), _ObjectA->TransInfo.Position.x, _ObjectA->TransInfo.Position.y - 2);

		if (Glovertime1 + 500 < GetTickCount64())
		{
			collisiontime = false;
		}
	}

	if (collisiontime1)
	{
		OnDrawText((_ObjectA->Info.Att + _ObjectA->Info.ITEMATT) - (_ObjectB->Info.Def / 2), _ObjectB->TransInfo.Position.x + 2, _ObjectB->TransInfo.Position.y - 2);

		if (Glovertime2 + 500 < GetTickCount64())
		{
			collisiontime1 = false;
		}
	}

	if (collisiontime2)
	{
		OnDrawText((_Bullet->Info.Att + _Bullet->Info.ITEMATT) - (_ObjectB->Info.Def / 2), _ObjectB->TransInfo.Position.x + 2, _ObjectB->TransInfo.Position.y - 2);

		if (Glovertime3 + 500 < GetTickCount64())
		{
			collisiontime2 = false;
		}
	}

	//** 적처치
	if (_ObjectB->Info.HP <= 0)
	{
		_ObjectA->Info.EXP += _ObjectB->Info.EXP;
		_ObjectA->Info.Gold += rand() % (_ObjectB->Info.GoldMax - _ObjectB->Info.GoldMin + 1) + _ObjectB->Info.GoldMin;
		
	}

	//** 게임오버
	if (_ObjectA->Info.HP <= 0)
	{
		system("cls");
		int Width = (120 / 2) - (int)(strlen("	 ::::::::           :::          :::   :::       ::::::::::        ::::::::    :::     :::       ::::::::::       :::::::::") / 2);
		int Height = 9;
		
		OnDrawText((char*)"   ::::::::           :::          :::   :::       ::::::::::        ::::::::    :::     :::       ::::::::::       :::::::::" 
		OnDrawText((char*)" :+:    :+:        :+: :+:       :+:+: :+:+:      :+:              :+:    :+:   :+:     :+:       :+:              :+:    :+:"
		OnDrawText((char*)" +:+              +:+   +:+     +:+ +:+:+ +:+     +:+              +:+    +:+   +:+     +:+       +:+              +:+    +:+"
		OnDrawText((char*)" :#:             +#++:++#++:    +#+  +:+  +#+     +#++:++#         +#+    +:+   +#+     +:+       +#++:++#         +#++:++#:"
		OnDrawText((char*)"+#+   +#+#      +#+     +#+    +#+       +#+     +#+              +#+    +#+    +#+   +#+        +#+              +#+    +#+"
		OnDrawText((char*)"#+#    #+#      #+#     #+#    #+#       #+#     #+#              #+#    #+#     #+#+#+#         #+#              #+#    #+#"
		OnDrawText((char*)"########       ###     ###    ###       ###     ##########        ########        ###           ##########       ###    ###"





		Sleep(1000);
	}
}

void enemyjumping(Object* _Object)
{
	if (enemybIsJumpping)
	{
		if (_Object->TransInfo.Position.y > 14 && enemybIsJumpped == false)
		{
			_Object->TransInfo.Position.y -= 3;
		}
		if (_Object->TransInfo.Position.y <= 14)
		{
			enemybIsJumpped = true;
		}
		if (enemybIsJumpped)
		{
			_Object->TransInfo.Position.y++;
		}
		if (enemybIsJumpped && _Object->TransInfo.Position.y == 15)
		{
			enemybIsJumpped = false;
			enemybIsJumpping = false;
		}
		_Object->TransInfo.Position.x += 2;
	}
}

void palyerstatusdraw(Object* _Object)
{
	OnDrawText((char*)"Name : ", 1, 1, 15), OnDrawText(_Object->Name, strlen("Name :  "), 1, 15);
	OnDrawText((char*)"HP : ", 1, 2, 15), OnDrawText(_Object->Info.HP, strlen("HP :  "), 2, 14);
	OnDrawText((char*)"MP : ", 1 + strlen("HP :  ") + sizeof(_Object->Info.HP), 2, 15), OnDrawText(_Object->Info.MP, 1 + strlen("HP :  ") + sizeof(_Object->Info.HP) + strlen("MP : "), 2, 14);
	OnDrawText((char*)"EXP : ", 1, 3, 15), OnDrawText(_Object->Info.EXP, strlen("EXP :  "), 3, 15);
	OnDrawText((char*)"ATT : ", 1, 4, 15), OnDrawText(_Object->Info.Att, strlen("ATT :  "), 4, 15);
	OnDrawText((char*)"ITEMATT : ", 1, 5, 15), OnDrawText(_Object->Info.ITEMATT, strlen("ITEMATT :  "), 5, 15);
	OnDrawText((char*)"DEF : ", 1, 6, 15), OnDrawText(_Object->Info.Def, strlen("DEF :  "), 6, 15);
	OnDrawText((char*)"ITEMDEF : ", 1, 7, 15), OnDrawText(_Object->Info.ITEMDFF, strlen("ITEMDEF :  "), 7, 15);
	OnDrawText((char*)"LEVEL : ", 1, 8, 15), OnDrawText(_Object->Info.Level, strlen("LEVEL :  "), 8, 15);
	OnDrawText((char*)"GOLD : ", 1, 9, 15), OnDrawText(_Object->Info.Gold, strlen("GOLD :  "), 9, 15);
}

void enemystatusdraw(Object* _Object)
{
	OnDrawText((char*)"Name : ", 105, 1, 15), OnDrawText(_Object->Name, 105 + strlen("Name : "), 1, 15);
	OnDrawText((char*)"HP : ", 105, 2, 15), OnDrawText(_Object->Info.HP, 105 + strlen("HP : "), 2, 14);
    OnDrawText((char*)"MP : ", 105, 3, 15), OnDrawText(_Object->Info.MP, 105 + strlen("MP : "), 3, 14);
	OnDrawText((char*)"LEVEL : ", 105, 4, 15), OnDrawText(_Object->Info.Level, 105 + strlen("LEVEL : "), 4, 15);
}