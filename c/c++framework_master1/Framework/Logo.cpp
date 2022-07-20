#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Logo::Logo() : Color(0), Length(0), MaxSize(0), Time(0)
{
	for (int i = 0; i < 8; ++i)
	{
		Buffer[i] = nullptr;
	}
	for (int i = 0; i < 4; ++i)
	{
		Buffer2022[i] = nullptr;
	}
}

Logo::~Logo()
{
	Release();
}


void Logo::Start()
{
	Buffer[0] = (char*)"88888888888 8888888888 Y88b   d88P 88888888888       .d8888b.         d8888 888b     d888 8888888888";
	Buffer[1] = (char*)"    888     888         Y88b d88P      888          d88P  Y88b       d88888 8888b   d8888 888       ";
	Buffer[2] = (char*)"    888     888          Y88o88P       888          888    888      d88P888 88888b.d88888 888       ";
	Buffer[3] = (char*)"    888     8888888       Y888P        888          888            d88P 888 888Y88888P888 8888888   ";
	Buffer[4] = (char*)"    888     888           d888b        888          888  88888    d88P  888 888 Y888P 888 888       ";
	Buffer[5] = (char*)"    888     888          d88888b       888          888    888   d88P   888 888  Y8P  888 888       ";
	Buffer[6] = (char*)"    888     888         d88P Y88b      888          Y88b  d88P  d8888888888 888   '   888 888       ";
	Buffer[7] = (char*)"    888     8888888888 d88P   Y88b     888           'Y8888P88 d88P     888 888       888 8888888888";

	Buffer2022[0] = (char*)" ___ ___ ___ ___ ";
	Buffer2022[1] = (char*)"|_  |   |_  |_  |";
	Buffer2022[2] = (char*)"|  _| | |  _|  _|";
	Buffer2022[3] = (char*)"|___|___|___|___|";

	Length = strlen("88888888888 8888888888 Y88b   d88P 88888888888       .d8888b.         d8888 888b     d888 8888888888");

	MaxSize = 8;

	Color = 15;

	Time = GetTickCount64();
}

void Logo::Update()
{
	if (Time + 500 < GetTickCount64())
	{
		Time = GetTickCount64();

		Color = rand() % 7 + 9;
	}

	DWORD dwKey1 = InputManager::GetInstance()->GetKey1();

	if (dwKey1 & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	for (int i = 0; i < MaxSize ; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length / 2), 5.0f + i, Buffer[i], Color);

	for (int i = 0; i < 4; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (17 / 2), 32.0f + i, Buffer2022[i], 15);
}

void Logo::Release()
{
	
}













