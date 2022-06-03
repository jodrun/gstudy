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
};

struct DrawTextInfo
{
	Information Info;
	Trasnsform TransInfo;
};



bool bIsJumpping = false;     // 현재 점프 중인가
bool bIsJumpped = false;      // 현재 점프하여 최고 지점에 올랐는가


const int Idle = 0;
const int Attack = 1;
const int Down = 2;
const int hit = 3;
const int Move = 4;
 






void LogoScene();

char* SetName();

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX = 0, float _PosY = 0, float _PosZ = 0, int _Anim = 0);

void InitializeStatus(Object* _Object, char* _name, int _HP, int _HPMAX, int _MP, int _MPMAX, int _EXP, int _Att,
	int _ITEMATT, int _Def, int _ITEMDFF, short _Level, short _GoldMin, short _GoldMax, short _Gold);

void UpdateInput(Object* _Object);




void SetCursorPosition(const float _x, const float _y);

void SetTextColor(const int _Color);

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

void HideCursor(const bool _Visible);



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

	// ** 좌표값
	Player->TransInfo.Position = Vector3(35, 15, 0);

	// ** 회전값 (현재 사용되지 않음.)
	Player->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	Player->State = Idle;

	// ** 크기값
	Player->TransInfo.Scale = Vector3(
		(float)strlen(Player->Info.Texture[Idle][1]), 1.0f, 0.0f);
	// *********************************************************************
	InitializeStatus(Player, nullptr, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	

	Object* Enemy[5];
	for (int i = 0; i < 5; ++i)
	{
		Enemy[i] = nullptr;
		Enemy[i] = new Object;
	}
 
	Initialize(Enemy[0], (char*)"ㅡㅡ", (char*)"   ㅣ ", (char*)"    ㅡㅡ   ", 70, 15);
	InitializeStatus(Enemy[0], (char*)"지렁이", 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	



	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		srand((unsigned int)time(NULL));

		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");
			
			UpdateInput(Player);

			// ** 배경 출력
			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			// ** Player 출력

			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(Player->Info.Texture[Player->State][i],
					Player->TransInfo.Position.x,
					Player->TransInfo.Position.y + i,
					10);
			}

			// ** Enemy 출력
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(Enemy[0]->Info.Texture[0][i],
					Enemy[0]->TransInfo.Position.x,
					Enemy[0]->TransInfo.Position.y + i,
					10);
			}
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

void InitializeStatus(Object* _Object, char* _name, int _HP, int _HPMAX, int _MP, int _MPMAX, int _EXP, int _Att, int _ITEMATT, int _Def, int _ITEMDFF, short _Level, short _GoldMin, short _GoldMax, short _Gold)
{
	_Object->Name = (_name == nullptr) ? SetName() : _name;
	_Object->Info.HP = _HP, _Object->Info.HPMAX = _HPMAX;
	_Object->Info.MP = _MP, _Object->Info.MPMAX = _MPMAX;
	_Object->Info.EXP = _EXP;
}

void UpdateInput(Object* _Object)
{
	// ** [상] 키를 입력받음.
	if (GetAsyncKeyState(VK_UP))
	{
		bIsJumpping = true;
	}
	
	if (bIsJumpping)
	{
		if (_Object->TransInfo.Position.y > 12 && bIsJumpped == false)
		{
			_Object->TransInfo.Position.y--;	
		}
		if (_Object->TransInfo.Position.y == 12)
		{
			bIsJumpped = true;
		}
		if (bIsJumpped == true)
		{
			_Object->TransInfo.Position.y++;
		}
		if (bIsJumpped && _Object->TransInfo.Position.y == 15)
		{
			bIsJumpped = false;
			bIsJumpping = false;
		}	
	}

	// ** [하] 키를 입력받음.
	if (GetAsyncKeyState(VK_DOWN))
		_Object->State = Down;
	else
		_Object->State = Idle;

	// ** [좌] 키를 입력받음.
	if (GetAsyncKeyState(VK_LEFT))
		_Object->TransInfo.Position.x -= 1;

	// ** [우] 키를 입력받음.
	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.x += 1;

	if (GetAsyncKeyState(VK_SPACE))
		_Object->State = Attack;
	else
		if(_Object->State != Down)
			_Object->State = Idle;
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