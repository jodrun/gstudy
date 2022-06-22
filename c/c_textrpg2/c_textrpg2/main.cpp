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
	char* Texture[4][10];

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

	USHORT Gold;

	short GoldMin;
	short GoldMax;

	int Color;
	int Option;
};

struct Object
{
	char* Name;
	float Speed;
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


bool bIsJumpping = false;     // ���� ���� ���ΰ�
bool bIsJumpped = false;      // ���� �����Ͽ� �ְ� ������ �ö��°�
bool enemybIsJumpping = false;     
bool enemybIsJumpped = false;

const int Idle = 0;
const int Attack = 1;
const int Down = 2;
const int hit = 3;
const int Move = 4;
 
float udo = 0;                  // ���󰡱� (����) ����
Vector3 udo1 = { 0, 0, 0 };     // ���󰡱� (����) ����

bool enemymoving = false;       // ��������
bool collisiontime = false;     // �浹�� ��� ������ �ֱ�����
bool collisiontime1 = false;    // �浹�� ��� ������ �ֱ�����
bool collisiontime2 = false;    // �浹�� ��� ������ �ֱ�����
bool leveluptime = false;       // �������� ��� ������ �ֱ�����
bool playerattackbool = false;
bool bulletskill = false;
bool playerdie = false;         // �÷��̾� �װ��� ������
bool enemydie = false;

bool weapon = false;
bool weapon1 = false;
bool weapon2 = false;

ULONGLONG Glovertime1 = 0;                 // �浹 ������ �帥 �ð� (������ �ֱ�����)
ULONGLONG Glovertime2 = 0;
ULONGLONG Glovertime3 = 0;
ULONGLONG Glovertime4 = 0;

int levelupexp[10] = { 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 50200 };



void LogoScene();

void SceneManager(Object* _Player, Object* _Enemy, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1, Object* _cusor, Object* _weapon, Object* _weapon1, Object* _weapon2);

void StroeScene(Object* _Player, Object* _cusor, Object* _weapon, Object* _weapon1, Object* _weapon2);

void StageScene(Object* _Player, Object* _Enemy, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1);

void StageScene1(Object* _Player, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1);

void StageScene2(Object* _Player, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1);

char* SetName();

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX = 0, float _PosY = 0, float _PosZ = 0, int _Anim = 0);

void InitializeStatus(Object* _Object, char* _name, int _HP, int _HPMAX, int _MP, int _MPMAX, int _EXP, int _Att, int _ITEMATT, int _Def, int _ITEMDFF, short _Level, short _Gold, short _GoldMax, short _GoldMin);

void UpdateInput(Object* _Object, Object* _Bullet);

void enemymove(Object* _enemy, Object* _player);

void enemy2enemymove(Object* _enemy, Object* _player);

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

void enemyjumping1(Object* _Object);

void enemyjumping2(Object* _Object);

void palyerstatusdraw(Object* _Object);

void enemystatusdraw(Object* _Object);

void levelup(Object* _Object);



int main(void)
{
	HideCursor(false);
	system("mode con:cols=120 lines=30");
	LogoScene();
	system("cls");

	Object* Player = new Object;
	// *************************�÷��̾� �ʱ�ȭ****************************
	Player->Info.Texture[Idle][0] = (char*)" o   /";
	Player->Info.Texture[Idle][1] = (char*)"�� /";
	Player->Info.Texture[Idle][2] = (char*)"11";

	Player->Info.Texture[Attack][0] = (char*)"  o    ";
	Player->Info.Texture[Attack][1] = (char*)" ��  �Ѥ�";
	Player->Info.Texture[Attack][2] = (char*)"����";

	Player->Info.Texture[Down][0] = (char*)"";
	Player->Info.Texture[Down][1] = (char*)"  ����";
	Player->Info.Texture[Down][2] = (char*)"  ��";

	Player->Info.Texture[hit][0] = (char*)"��";
	Player->Info.Texture[hit][1] = (char*)"������";
	Player->Info.Texture[hit][2] = (char*)"//";

	// ** ��ǥ��
	Player->TransInfo.Position = Vector3(35, 15, 0);

	// ** ȸ���� (���� ������ ����.)
	Player->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	Player->State = Idle;

	// ** ũ�Ⱚ
	Player->TransInfo.Scale = Vector3(
		(float)strlen(Player->Info.Texture[Idle][1]), 1.0f, 0.0f);
	// *********************************************************************
	InitializeStatus(Player, nullptr, 100, 100, 10, 10, 0, 50, 0, 10, 0, 1, 50000, 0, 0);
	

	// *************************���ʹ� �ʱ�ȭ****************************
	Object* Enemy[5];
	for (int i = 0; i < 5; ++i)
	{
		Enemy[i] = nullptr;
		Enemy[i] = new Object;
	}
	// *********************************************************************
	Initialize(Enemy[0], (char*)"�Ѥ�", (char*)"   ��", (char*)"    �Ѥ�", 70, 15);
	Enemy[0]->State = Idle;
	Enemy[0]->Info.Texture[Attack][0] = (char*)" �Ѥ�";
	Enemy[0]->Info.Texture[Attack][1] = (char*)"   ��";
	Enemy[0]->Info.Texture[Attack][2] = (char*)"   �Ѥ�";
	Enemy[0]->Speed = 0;
	InitializeStatus(Enemy[0], (char*)"������", 150, 150, 5, 5, 50, 30, 0, 10, 0, 1, 0, 100, 10);
	// *********************************************************************
	Initialize(Enemy[1], (char*)"", (char*)"", (char*)"", 70, 13);
	Enemy[1]->State = Idle;
	Enemy[1]->Info.Texture[Idle][0] = (char*)"        ��������������      ";
	Enemy[1]->Info.Texture[Idle][1] = (char*)"      ��              ��   ";
	Enemy[1]->Info.Texture[Idle][2] = (char*)"  ����     ; ;     ; ; ��  ";
	Enemy[1]->Info.Texture[Idle][3] = (char*)"��o o  ����  ; ;     ; ; ��";
	Enemy[1]->Info.Texture[Idle][4] = (char*)"  ���� ;    ;   ���� ;     ";
	Enemy[1]->Info.Texture[Attack][0] = (char*)"        ��������������      ";
	Enemy[1]->Info.Texture[Attack][1] = (char*)"      ��              ��   ";
	Enemy[1]->Info.Texture[Attack][2] = (char*)"  ����      ; ;     ; ;��  ";
	Enemy[1]->Info.Texture[Attack][3] = (char*)"��o o  ����   ; ;     ; ;��";
	Enemy[1]->Info.Texture[Attack][4] = (char*)"  ����;       ; ����   ;   ";
	Enemy[1]->Speed = 0.3;
	InitializeStatus(Enemy[1], (char*)"�հŹ�", 500, 500, 20, 20, 250, 200, 0, 50, 0, 10, 0, 500, 50);
	Enemy[1]->TransInfo.Scale = Vector3(
		(float)strlen(Enemy[1]->Info.Texture[Idle][3]), 1.0f, 0.0f);
	// *********************************************************************
	Initialize(Enemy[2], (char*)"", (char*)"", (char*)"", 60, 8);
	Enemy[2]->State = Idle;
	Enemy[2]->Info.Texture[Idle][0] = (char*)"                       �ף�������";
	Enemy[2]->Info.Texture[Idle][1] = (char*)"���أ�����������     ��          ��";
	Enemy[2]->Info.Texture[Idle][2] = (char*)"  ; ����  o     �� ��              ��";
	Enemy[2]->Info.Texture[Idle][3] = (char*)"   ;��  ��                           ��";
	Enemy[2]->Info.Texture[Idle][4] = (char*)"     ;    ��          ������   ������  ��";
	Enemy[2]->Info.Texture[Idle][5] = (char*)"      ; �� ��         ��    )  ��     )  ��";
	Enemy[2]->Info.Texture[Idle][6] = (char*)"     ;    ��           (   )     (   )     ��____";
	Enemy[2]->Info.Texture[Idle][7] = (char*)"   ; �� ��             (  )      (  ) �ע�        ��";
	Enemy[2]->Info.Texture[Idle][8] = (char*)"  ; __��         �ע�  ( ) _____ ( )��    ��__�ף��آ�";
	Enemy[2]->Info.Texture[Idle][9] = (char*)"__��___________��   �� ��   ��   ��                   ��";
	Enemy[2]->Info.Texture[Attack][0] = (char*)"                       �ף�������";
	Enemy[2]->Info.Texture[Attack][1] = (char*)"���أ�����������     ��          ��";
	Enemy[2]->Info.Texture[Attack][2] = (char*)"  ; ����  =     �� ��              ��";
	Enemy[2]->Info.Texture[Attack][3] = (char*)"   ;    ��                           l";
	Enemy[2]->Info.Texture[Attack][4] = (char*)"     ;  ����           ������  ������ ����";
	Enemy[2]->Info.Texture[Attack][5] = (char*)"      ;    ��         ��    ) ��    )     ��";
	Enemy[2]->Info.Texture[Attack][6] = (char*)"  �� ;    ��            (   )   (   )       ��____";
	Enemy[2]->Info.Texture[Attack][7] = (char*)"   ;    ��               (  )    (  )  �ע�        ��";
	Enemy[2]->Info.Texture[Attack][8] = (char*)"  ; __��         �ע�____ ( )_____( )��    ��__�ף��آ�";
	Enemy[2]->Info.Texture[Attack][9] = (char*)"__��___________�ע�     �� ��      ��                  ��";
	Enemy[2]->Speed = 0.2;
	InitializeStatus(Enemy[2], (char*)"�յ�����", 2000, 2000, 500, 500, 1000, 1000, 0, 300, 0, 30, 0, 5000, 500);
	Enemy[2]->TransInfo.Scale = Vector3(
		(float)strlen(Enemy[2]->Info.Texture[Idle][8]), 1.0f, 0.0f);
	// *********************************************************************
	Object* Bullet = new Object;
	Initialize(Bullet, (char*)"��", (char*)"", (char*)"", 0, 15);
	// *********************************************************************
	Object* cusor = new Object;
	Initialize(cusor, (char*)"��", (char*)"", (char*)"", 70, 15);
	// *********************************************************************
	Object* weapon[3];
		for (int i = 0; i < 3; ++i)
		{
			weapon[i] = nullptr;
			weapon[i] = new Object;
		}
		Initialize(weapon[0], (char*)"������", (char*)"", (char*)"", 60, 10);
		weapon[0]->Info.ITEMATT = 50;
		Initialize(weapon[1], (char*)"�����", (char*)"", (char*)"", 60, 15);
		weapon[1]->Info.ITEMATT = 500;
		Initialize(weapon[2], (char*)"������", (char*)"", (char*)"", 60, 20);
		weapon[2]->Info.ITEMATT = 5000;
	// *********************************************************************

	ULONGLONG Time = GetTickCount64();   //** ���� ���� �ð� ������
	ULONGLONG Time1 = GetTickCount64();  //** ���ʹ� ���ڸ� ������ ������
	

	while (true)
	{
		srand((unsigned int)time(NULL));

		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			SceneManager(Player, Enemy[0], Enemy[1], Enemy[2], Bullet, Time1, cusor, weapon[0], weapon[1], weapon[2]);
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

	OnDrawText((char*)"�̸��Է� : ", 50, 14, 15);
	cin >> Buffer;

	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return pName;
}

void SceneManager(Object* _Player, Object* _Enemy, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1, Object* _cusor, Object* _weapon, Object* _weapon1, Object* _weapon2)
{
	//���� ���
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
	
	//���� ���
	for (int i = 0; i < 6; ++i)
	{
		OnDrawText((char*)"��                     ��", 3, 18 - i, 15);
	}
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 1, 12, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~~~", 2, 11, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~~~", 3, 10, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~~~", 4, 9, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~~~", 5, 8, 15);
	OnDrawText((char*)"~~~~~~~~~~~~~~~~~~~", 6, 7, 15);
	OnDrawText((char*)"��   ��", 12, 17, 15);
	OnDrawText((char*)"��   ��", 12, 16, 15);
	OnDrawText((char*)"�ѤѤ�", 13, 15, 15);

	OnDrawText((char*)"�Ӥ�", 27, 17, 15);
	OnDrawText((char*)"�Ӥ�", 27, 16, 15);
	OnDrawText((char*)"----------", 25, 15, 15);
	OnDrawText((char*)"��", 24, 14, 15);
	OnDrawText((char*)"��", 34, 14, 15);
	OnDrawText((char*)"----------", 25, 13, 15);
	OnDrawText((char*)"  ����", 26, 14, 15);
	
	//����� ���� ���
	OnDrawText((char*)"�Ӥ�", 110, 17, 15);
	OnDrawText((char*)"�Ӥ�", 110, 16, 15);
	OnDrawText((char*)"----------", 107, 15, 15);
	OnDrawText((char*)"��", 106, 14, 15);
	OnDrawText((char*)"��", 116, 14, 15);
	OnDrawText((char*)"----------", 107, 13, 15);
	OnDrawText((char*)"��������", 108, 14, 15);
	
	//ĳ���� ���&Ű�Է�
	UpdateInput(_Player, _Bullet);
	for (int i = 0; i < 3; ++i)
	{
		OnDrawText(_Player->Info.Texture[_Player->State][i],
			_Player->TransInfo.Position.x,
			_Player->TransInfo.Position.y + i,
			10);
	}

	//�ٴ����
	OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

	//����� �Ѿ�� �ڵ�
	if (_Player->TransInfo.Position.x > 112)
	{
		enemybIsJumpping = false;
		_Player->TransInfo.Position.x = 10;
		_Enemy->TransInfo.Position.x = 70;
		_Enemy->TransInfo.Position.y = 15;
		_Player->Info.HP = _Player->Info.HPMAX;
		_Player->Info.MP = _Player->Info.MPMAX;
		_Enemy->Info.HP = _Enemy->Info.HPMAX;
		_Enemy->Info.MP = _Enemy->Info.HPMAX;
        StageScene(_Player, _Enemy, _Enemy1, _Enemy2, _Bullet, _Time1);

	}

	//fŰ�Է� �ڵ�
	OnDrawText((char*)"F : ��ȣ�ۿ�", 0, 28, 15);
	if (GetAsyncKeyState(0x46) && _Player->TransInfo.Position.x >= 12 && _Player->TransInfo.Position.x <= (strlen("��   ��") + 12))
	{
		StroeScene(_Player, _cusor, _weapon, _weapon1, _weapon2);
	}

	//esc�������� �ڵ�
	OnDrawText((char*)"esc : ��������", 0, 29, 15);
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		system("cls");
		exit(NULL);
	}
}

void StroeScene(Object* _Player, Object* _cusor, Object* _weapon, Object* _weapon1, Object* _weapon2)
{
	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		srand((unsigned int)time(NULL));
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				if (_cusor->TransInfo.Position.y <= 10)
					_cusor->TransInfo.Position.y = 10;
				else
					_cusor->TransInfo.Position.y -= 5;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (_cusor->TransInfo.Position.y >= 20)
					_cusor->TransInfo.Position.y = 20;
				else
				    _cusor->TransInfo.Position.y += 5;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				if (_cusor->TransInfo.Position.x <= 50)
					_cusor->TransInfo.Position.x = 50;
				else
					_cusor->TransInfo.Position.x -= 20;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{

				if (_cusor->TransInfo.Position.x >= 70)
					_cusor->TransInfo.Position.x = 70;
				else
					_cusor->TransInfo.Position.x += 20;
			}
			if (GetAsyncKeyState(VK_SPACE))
			{
				if (_Player->Info.Gold > 200 && _cusor->TransInfo.Position.y == 10 && _cusor->TransInfo.Position.x == 70 && weapon == false)
				{
					_weapon->TransInfo.Position.x = 40;
					_Player->Info.Gold -= 200;
					weapon = true;
				}
				else if (_Player->Info.Gold > 2000 && _cusor->TransInfo.Position.y == 15 && _cusor->TransInfo.Position.x == 70 && weapon1 == false)
				{
					_weapon1->TransInfo.Position.x = 40;
					_Player->Info.Gold -= 2000;
					weapon1 = true;
				}
				else if (_Player->Info.Gold > 20000 && _cusor->TransInfo.Position.y == 20 && _cusor->TransInfo.Position.x == 70 && weapon2 == false)
				{
					_weapon2->TransInfo.Position.x = 40;
					_Player->Info.Gold -= 20000;
					weapon2 = true;
				}

				if (_cusor->TransInfo.Position.y == 10 && _cusor->TransInfo.Position.x == 50 && weapon)
				{
					_Player->Info.ITEMATT = _weapon->Info.ITEMATT;
				}
				else if (_cusor->TransInfo.Position.y == 15 && _cusor->TransInfo.Position.x == 50 && weapon1)
				{
					_Player->Info.ITEMATT = _weapon1->Info.ITEMATT;
				}
				else if (_cusor->TransInfo.Position.y == 20 && _cusor->TransInfo.Position.x == 50 && weapon2)
				{
					_Player->Info.ITEMATT = _weapon2->Info.ITEMATT;
				}
			}
				
			if (GetAsyncKeyState(0x43) & 0x8000)
			{
				system("cls");
				break;
			}

			
			OnDrawText(_cusor->Info.Texture[0][0], _cusor->TransInfo.Position.x, _cusor->TransInfo.Position.y, 10);
			OnDrawText("��������", 60, 9, 15);
			OnDrawText("��     ��", 60, 10, 15);
			OnDrawText("��     ��", 60, 11, 15);
			OnDrawText(" ��������", 60, 12, 15);
			OnDrawText("��������", 60, 14, 15);
			OnDrawText("��     ��", 60, 15, 15);
			OnDrawText("��     ��", 60, 16, 15);
			OnDrawText(" ��������", 60, 17, 15);
			OnDrawText("��������", 60, 19, 15);
			OnDrawText("��     ��", 60, 20, 15);
			OnDrawText("��     ��", 60, 21, 15);
			OnDrawText(" ��������", 60, 22, 15);
			OnDrawText("��������", 40, 9, 10);
			OnDrawText("��     ��", 40, 10, 10);
			OnDrawText("��     ��", 40, 11, 10);
			OnDrawText(" ��������", 40, 12, 10);
			OnDrawText("��������", 40, 14, 10);
			OnDrawText("��     ��", 40, 15, 10);
			OnDrawText("��     ��", 40, 16, 10);
			OnDrawText(" ��������", 40, 17, 10);
			OnDrawText("��������", 40, 19, 10);
			OnDrawText("��     ��", 40, 20, 10);
			OnDrawText("��     ��", 40, 21, 10);
			OnDrawText(" ��������", 40, 22, 10);
			OnDrawText(200, 60, 11, 10);
			OnDrawText(2000, 60, 16, 10);
			OnDrawText(20000, 60, 21, 10);
			OnDrawText(_weapon->Info.Texture[0][0], _weapon->TransInfo.Position.x, _weapon->TransInfo.Position.y, 15);
			OnDrawText(_weapon1->Info.Texture[0][0], _weapon1->TransInfo.Position.x, _weapon1->TransInfo.Position.y, 15);
			OnDrawText(_weapon2->Info.Texture[0][0], _weapon2->TransInfo.Position.x, _weapon2->TransInfo.Position.y, 15);
			OnDrawText("Gold : ", 100, 1, 10);
			OnDrawText("ITEMATT : ", 1, 1, 10);
			OnDrawText(_Player->Info.Gold, 100 + strlen("Gold : "), 1, 10);
			OnDrawText(_Player->Info.ITEMATT, 1 + strlen("ITEMATT : "), 1, 10);
			OnDrawText("C : �ڷΰ���", 0, 29, 15);
		}
	}
}



void StageScene(Object* _Player, Object* _Enemy, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1)
{
	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		levelup(_Player);
		srand((unsigned int)time(NULL));
		if (Time + 50 < GetTickCount64() && _Enemy != nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 3;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
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

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			// ** Enemy ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Enemy->Info.Texture[_Enemy->State][i],
					_Enemy->TransInfo.Position.x,
					_Enemy->TransInfo.Position.y + i,
					6);
			}

			palyerstatusdraw(_Player);
			enemystatusdraw(_Enemy);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			if (enemydie)
			{
				_Enemy = nullptr;
				enemydie = false;
			}
		}

		else if (Time + 50 < GetTickCount64() && _Enemy == nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 5;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
			UpdateInput(_Player, _Bullet);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			palyerstatusdraw(_Player);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);
		}

		if (_Player->TransInfo.Position.x < 5)
		{
			_Player->TransInfo.Position.x = 110;
			break;
		}

		if (playerdie)
		{
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			playerdie = false;
			break;
		}

		if (_Player->TransInfo.Position.x > 112)
		{
			enemybIsJumpping = false;
			_Player->TransInfo.Position.x = 10;
			_Enemy1->TransInfo.Position.x = 70;
			_Enemy1->TransInfo.Position.y = 13;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			_Enemy1->Info.HP = _Enemy1->Info.HPMAX;
			_Enemy1->Info.MP = _Enemy1->Info.MPMAX;
			StageScene1(_Player, _Enemy1, _Enemy2, _Bullet, _Time1);
		}
	}
}

void StageScene1(Object* _Player, Object* _Enemy1, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1)
{
	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		levelup(_Player);
		srand((unsigned int)time(NULL));
		if (Time + 50 < GetTickCount64() && _Enemy1 != nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 3;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
			UpdateInput(_Player, _Bullet);

			udo = GetDistance(_Player, _Enemy1);
			udo1 = GetDirection(_Player, _Enemy1);

			enemymovestage(_Enemy1, _Player);
			if (_Time1 + 350 < GetTickCount64())
			{
				_Enemy1->State = Attack;
				if (_Time1 + 650 < GetTickCount64())
				{
					_Enemy1->State = Idle;
					_Time1 = GetTickCount64();
				}
			}

			CollisionStage(_Player, _Enemy1, _Bullet);
			enemyjumping1(_Enemy1);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			// ** Enemy ���
			for (int i = 0; i < 5; ++i)
			{
				OnDrawText(_Enemy1->Info.Texture[_Enemy1->State][i],
					_Enemy1->TransInfo.Position.x,
					_Enemy1->TransInfo.Position.y + i,
					10);
			}

			palyerstatusdraw(_Player);
			enemystatusdraw(_Enemy1);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			if (enemydie)
			{
				_Enemy1 = nullptr;
				enemydie = false;
			}
		}

		else if (Time + 50 < GetTickCount64() && _Enemy1 == nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 5;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
			UpdateInput(_Player, _Bullet);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			palyerstatusdraw(_Player);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);
		}


		if (_Player->TransInfo.Position.x < 5)
		{
			_Player->TransInfo.Position.x = 110;
			break;
		}

		if (playerdie)
		{
			break;
		}

		if (_Player->TransInfo.Position.x > 112)
		{
			enemybIsJumpping = false;
			_Player->TransInfo.Position.x = 10;
			_Enemy2->TransInfo.Position.x = 60;
			_Enemy2->TransInfo.Position.y = 8;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			_Enemy2->Info.HP = _Enemy2->Info.HPMAX;
			_Enemy2->Info.MP = _Enemy2->Info.MPMAX;
			StageScene2(_Player, _Enemy2, _Bullet, _Time1);
		}
	}
}

void StageScene2(Object* _Player, Object* _Enemy2, Object* _Bullet, ULONGLONG _Time1)
{
	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		levelup(_Player);
		srand((unsigned int)time(NULL));
		if (Time + 50 < GetTickCount64() && _Enemy2 != nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 3;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
			UpdateInput(_Player, _Bullet);

			udo = GetDistance(_Player, _Enemy2);
			udo1 = GetDirection(_Player, _Enemy2);

			enemy2enemymove(_Enemy2, _Player);
			if (_Time1 + 350 < GetTickCount64())
			{
				_Enemy2->State = Attack;
				if (_Time1 + 650 < GetTickCount64())
				{
					_Enemy2->State = Idle;
					_Time1 = GetTickCount64();
				}
			}

			CollisionStage(_Player, _Enemy2, _Bullet);
			enemyjumping2(_Enemy2);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			// ** Enemy ���
			for (int i = 0; i < 10; ++i)
			{
				OnDrawText(_Enemy2->Info.Texture[_Enemy2->State][i],
					_Enemy2->TransInfo.Position.x,
					_Enemy2->TransInfo.Position.y + i,
					12);
			}

			palyerstatusdraw(_Player);
			enemystatusdraw(_Enemy2);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);

			if (enemydie)
			{
				_Enemy2 = nullptr;
				enemydie = false;
			}
		}

		else if (Time + 50 < GetTickCount64() && _Enemy2 == nullptr)
		{
			Time = GetTickCount64();
			system("cls");

			_Bullet->Info.Att = _Player->Info.Att / 5;          //** �ҷ� ������ �ʱ�ȭ
			_Bullet->Info.ITEMATT = _Player->Info.ITEMATT / 2;  //** �ҷ� ������ �ʱ�ȭ
			UpdateInput(_Player, _Bullet);

			if (bulletskill)
			{
				OnDrawText(_Bullet->Info.Texture[0][0],
					_Bullet->TransInfo.Position.x += 2,
					_Bullet->TransInfo.Position.y + 1,
					11);
			}

			// ** Player ���
			for (int i = 0; i < 3; ++i)
			{
				OnDrawText(_Player->Info.Texture[_Player->State][i],
					_Player->TransInfo.Position.x,
					_Player->TransInfo.Position.y + i,
					10);
			}

			palyerstatusdraw(_Player);

			OnDrawText((char*)"========================================================================================================================", 0, 18, 15);
		}


		if (_Player->TransInfo.Position.x < 5)
		{
			_Player->TransInfo.Position.x = 110;
			break;
		}

		if (playerdie)
		{
			break;
		}

		if (_Player->TransInfo.Position.x > 112)
		{
			enemybIsJumpping = false;
			_Player->TransInfo.Position.x = 10;
			_Player->Info.HP = _Player->Info.HPMAX;
			_Player->Info.MP = _Player->Info.MPMAX;
			StageScene2(_Player, _Enemy2, _Bullet, _Time1);
		}
	}
}

void Initialize(Object* _Object, char* _Texture, char* _Texture2, char* _Texture3, float _PosX, float _PosY, float _PosZ, int _Anim)
{
	_Object->Info.Texture[_Anim][0] = _Texture;
	_Object->Info.Texture[_Anim][1] = _Texture2;
	_Object->Info.Texture[_Anim][2] = _Texture3;

	_Object->Speed = 0;

	// ** ��ǥ��
	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);

	// ** ȸ���� (���� ������ ����.)
	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	// ** ũ�Ⱚ
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
		_Object->TransInfo.Position.x -= 2;

	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.x += 2;

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
	if (udo <= 25)       // �÷��̾�, �� �Ÿ��� 25 �̳��� ��������� �����ϴ� �ڵ�
	{
		int i = rand() % 7 + 1;
		if (_enemy->TransInfo.Position.x > _player->TransInfo.Position.x)
		{
			if (i == 3)
			{
				_enemy->TransInfo.Position.x -= (1 + _enemy->Speed * 2);
			}
			else
			{
			    _enemy->TransInfo.Position.x -= (0.2 + _enemy->Speed);
			}
		}
		else if (_enemy->TransInfo.Position.x < _player->TransInfo.Position.x)
		{
			_enemy->TransInfo.Position.x += (0.2 + _enemy->Speed);
		}
		if (_enemy->TransInfo.Position.x <= 65)
			enemymoving = true;
	}
	else if (_enemy->TransInfo.Position.x > 5 && _enemy->TransInfo.Position.x >= 65 && enemymoving == false)
	{
		_enemy->TransInfo.Position.x -= (0.2 + _enemy->Speed);
		if (_enemy->TransInfo.Position.x <= 65)
			enemymoving = true;
	}
    else if (_enemy->TransInfo.Position.x < 115 || _enemy->TransInfo.Position.x <= 75 && enemymoving == true)
	{
		_enemy->TransInfo.Position.x += (0.2 + _enemy->Speed);
		if (_enemy->TransInfo.Position.x >= 75)
			enemymoving = false;
	}
}

void enemy2enemymove(Object* _enemy, Object* _player)
{
	if (udo <= 25)       // �÷��̾�, �� �Ÿ��� 25 �̳��� ��������� �����ϴ� �ڵ�
	{
		int i = rand() % 7 + 1;
		if (_enemy->TransInfo.Position.x > _player->TransInfo.Position.x)
		{
			if (i == 3)
			{
				_enemy->TransInfo.Position.x -= (1 + _enemy->Speed * 2);
			}
			else
			{
				_enemy->TransInfo.Position.x -= (0.2 + _enemy->Speed);
			}
		}
		else if (_enemy->TransInfo.Position.x < _player->TransInfo.Position.x)
		{
			_enemy->TransInfo.Position.x += (0.2 + _enemy->Speed);
		}
		if (_enemy->TransInfo.Position.x <= 45)
			enemymoving = true;
	}
	else if (_enemy->TransInfo.Position.x > 5 && _enemy->TransInfo.Position.x >= 45 && enemymoving == false)
	{
		_enemy->TransInfo.Position.x -= (0.2 + _enemy->Speed);
		if (_enemy->TransInfo.Position.x <= 45)
			enemymoving = true;
	}
	else if (_enemy->TransInfo.Position.x < 115 || _enemy->TransInfo.Position.x <= 55 && enemymoving == true)
	{
		_enemy->TransInfo.Position.x += (0.2 + _enemy->Speed);
		if (_enemy->TransInfo.Position.x >= 55)
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

	// ** sqrt : ������ �Լ�
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
	// ** (_Object->TransInfo.Position.x + _Object->TransInfo.Scale.x)   : ����
	// ** _Object->TransInfo.Position.x   : ����
	// ** Rect �浹�� �������� �׻� ũ��.
	if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y)
		return true;
	else if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y + 2)
		return true;
	else if ((_ObjectA->TransInfo.Position.x + _ObjectA->TransInfo.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y + 7)
		return true;
	return false;
}

bool PlayerAttackCollision(Object* _ObjectA, Object* _ObjectB)
{
	// ** (_Object->TransInfo.Position.x + _Object->TransInfo.Scale.x)   : ����
	// ** _Object->TransInfo.Position.x   : ����
	// ** Rect �浹�� �������� �׻� ũ��.
	if ((_ObjectA->TransInfo.Position.x + _ObjectA->attackscale.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y)
		return true;
	else if ((_ObjectA->TransInfo.Position.x + _ObjectA->attackscale.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y + 2)
		return true;
	else if ((_ObjectA->TransInfo.Position.x + _ObjectA->attackscale.Scale.x) > _ObjectB->TransInfo.Position.x &&
		(_ObjectB->TransInfo.Position.x + _ObjectB->TransInfo.Scale.x) > _ObjectA->TransInfo.Position.x &&
		_ObjectA->TransInfo.Position.y == _ObjectB->TransInfo.Position.y + 7)
		return true;
	return false;
}

void CollisionStage(Object* _ObjectA, Object* _ObjectB, Object* _Bullet)
{
	//**�ҷ� ����
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

	//**�÷��̾ ���� �浹����
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

	//** �浹����
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

	//** ��óġ
	if (_ObjectB->Info.HP <= 0)
	{
		_ObjectA->Info.EXP += _ObjectB->Info.EXP;
		_ObjectA->Info.Gold += rand() % (_ObjectB->Info.GoldMax - _ObjectB->Info.GoldMin + 1) + _ObjectB->Info.GoldMin;
		enemydie = true;
	}

	//** ���ӿ���
	if (_ObjectA->Info.HP <= 0)
	{
		system("cls");
		int Width = (120 / 2) - (int)(strlen("     ::::::::         :::        :::   :::    ::::::::::   ::::::::   :::     :::  ::::::::::  :::::::::") / 2);
		int Height = 9;
		
		OnDrawText((char*)"     ::::::::         :::        :::   :::    ::::::::::   ::::::::   :::     :::  ::::::::::  :::::::::", Width, Height + 1, 12);
		OnDrawText((char*)"    :+:    :+:     :+: :+:     :+:+: :+:+:   :+:         :+:    :+:  :+:     :+:  :+:         :+:    :+:", Width, Height + 2, 12);
		OnDrawText((char*)"   +:+           +:+   +:+   +:+ +:+:+ +:+  +:+         +:+    +:+  +:+     +:+  +:+         +:+    +:+ ", Width, Height + 3, 12);
		OnDrawText((char*)"  :#:          +#++:++#++:  +#+  +:+  +#+  +#++:++#    +#+    +:+  +#+     +:+  +#++:++#    +#++:++#:   ", Width, Height + 4, 12);
		OnDrawText((char*)" +#+   +#+#  +#+     +#+  +#+       +#+   +#+         +#+    +#+  +#+   +#+   +#+         +#+    +#+    ", Width, Height + 5, 12);
		OnDrawText((char*)"#+#    #+#  #+#     #+#  #+#       #+#   #+#         #+#    #+#   #+#+#+#    #+#         #+#    #+#     ", Width, Height + 6, 12);
		OnDrawText((char*)"########   ###     ###  ###       ###   ##########   ########      ###      ##########  ###    ###      ", Width, Height + 7, 12);
		Sleep(1000);
		playerdie = true;
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
		if (_Object->TransInfo.Position.y <= 13)
		{
			enemybIsJumpped = true;
		}
		if (enemybIsJumpped)
		{
			_Object->TransInfo.Position.y++;
		}
		if (enemybIsJumpped && _Object->TransInfo.Position.y >= 15)
		{
			enemybIsJumpped = false;
			enemybIsJumpping = false;
			if (_Object->TransInfo.Position.y != 15)
				_Object->TransInfo.Position.y = 15;
		}
		_Object->TransInfo.Position.x += 2;
	}
}


void enemyjumping1(Object* _Object)
{
	if (enemybIsJumpping)
	{
		if (_Object->TransInfo.Position.y > 10 && enemybIsJumpped == false)
		{
			_Object->TransInfo.Position.y -= 4;
		}
		if (_Object->TransInfo.Position.y <= 10)
		{
			enemybIsJumpped = true;
		}
		if (enemybIsJumpped)
		{
			_Object->TransInfo.Position.y++;
		}
		if (enemybIsJumpped && _Object->TransInfo.Position.y == 14)
		{
			enemybIsJumpped = false;
			enemybIsJumpping = false;
			if (_Object->TransInfo.Position.y != 13)
				_Object->TransInfo.Position.y = 13;
		}
		_Object->TransInfo.Position.x += 1;
	}	
}

void enemyjumping2(Object* _Object)
{
	if (enemybIsJumpping)
	{
		_Object->TransInfo.Position.x += 1;
		enemybIsJumpping = false;
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

void levelup(Object* _Object)
{
	if (_Object->Info.EXP >= levelupexp[_Object->Info.Level - 1])
	{
		Glovertime4 = GetTickCount64();
		leveluptime = true;
		_Object->Info.Level += 1;
		_Object->Info.Att *= 2;
		_Object->Info.Def *= 2;
		_Object->Info.EXP = 0;
		_Object->Info.HP *= 2;
		_Object->Info.HPMAX *= 2;
		_Object->Info.MP *= 2;
		_Object->Info.MPMAX *= 2;
	}
	
	if (leveluptime)
	{
		OnDrawText((char*)"!!������!!", _Object->TransInfo.Position.x - 4, _Object->TransInfo.Position.y - 2, 15);
		if (Glovertime4 + 3000 < GetTickCount64())
		{
			leveluptime = false;
		}
	}
}
