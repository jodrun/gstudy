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
	char* Texture;
	char* Texture2;
	char* Texture3;

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



void LogoScene();

char* SetName();

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX = 0, float _PosY = 0, float _PosZ = 0);

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
	Initialize(Player, (char*)" o   /", (char*)"ㅁ /", (char*)"ll", 35, 15);
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
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");
			
			UpdateInput(Player);

			// ** 배경 출력
			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			// ** Player 출력
			OnDrawText(Player->Info.Texture,
				Player->TransInfo.Position.x,
				Player->TransInfo.Position.y,
				10);
			OnDrawText(Player->Info.Texture2,
				Player->TransInfo.Position.x,
				Player->TransInfo.Position.y + 1,
				10);
			OnDrawText(Player->Info.Texture3,
				Player->TransInfo.Position.x,
				Player->TransInfo.Position.y + 2,
				10);

			// ** Enemy 출력
			OnDrawText(Enemy[0]->Info.Texture,
				Enemy[0]->TransInfo.Position.x,
				Enemy[0]->TransInfo.Position.y,
				10);
			OnDrawText(Enemy[0]->Info.Texture2,
				Enemy[0]->TransInfo.Position.x,
				Enemy[0]->TransInfo.Position.y + 1,
				10);
			OnDrawText(Enemy[0]->Info.Texture3,
				Enemy[0]->TransInfo.Position.x,
				Enemy[0]->TransInfo.Position.y + 2,
				10);

	
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

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX, float _PosY, float _PosZ)
{
	_Object->Info.Texture = _Texture;
	_Object->Info.Texture2 = _Texture2;
	_Object->Info.Texture3 = _Texture3;

	_Object->Speed = 0;

	// ** 좌표값
	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);

	// ** 회전값 (현재 사용되지 않음.)
	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	// ** 크기값
	_Object->TransInfo.Scale = Vector3(
		(float)strlen(_Object->Info.Texture), 1.0f, 0.0f);
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
			_Object->TransInfo.Position.y -= 3;
		}
		else if (_Object->TransInfo.Position.y == 12)
		{
			bIsJumpped = true;
		}
		else if (bIsJumpped)
		{
			_Object->TransInfo.Position.y += 3;
		}
		else if (bIsJumpped && _Object->TransInfo.Position.y == 12)
		{
			bIsJumpped = false;
			bIsJumpping = false;
		}
	}
	else
	{
		if (_Object->TransInfo.Position.y < 15)
			_Object->TransInfo.Position.y++;
	}


	// ** [하] 키를 입력받음.
	if (GetAsyncKeyState(VK_DOWN))
		_Object->TransInfo.Position.y += 1;

	// ** [좌] 키를 입력받음.
	if (GetAsyncKeyState(VK_LEFT))
		_Object->TransInfo.Position.x -= 1;

	// ** [우] 키를 입력받음.
	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.x += 1;

	if (GetAsyncKeyState(VK_SPACE))
	{
		_Object->Info.Texture = (char*)"  o    ";
		_Object->Info.Texture2 = (char*)" ㅁ  ㅡㅡ";
		_Object->Info.Texture3 = (char*)"／＼";
	}
	else
	{
		_Object->Info.Texture = (char*)" o   /";
		_Object->Info.Texture2 = (char*)"ㅁ /";
		_Object->Info.Texture3 = (char*)"11";
	}
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