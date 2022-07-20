#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Menu::Menu() : Color(0), Cursor(0), MaxSize(0), Time(0)
{
	for (int i = 0; i < 4; ++i)
	{
		Buffer[i] = nullptr;
		Length[i] = 0;
	}
}

Menu::~Menu()
{

}


void Menu::Start()
{
	Buffer[0] = (char*)"S t a r t";
	Buffer[1] = (char*)"O p t i o n";
	Buffer[2] = (char*)"S t o r e";
	Buffer[3] = (char*)"E x i t";

	Length[0] = strlen(Buffer[0]);
	Length[1] = strlen(Buffer[1]);
	Length[2] = strlen(Buffer[2]);
	Length[3] = strlen(Buffer[3]);

	MaxSize = 4;

	Color = 8;

	Time = GetTickCount64();


	Cursor = 15;
}

void Menu::Update()
{
	DWORD dwKey1 = InputManager::GetInstance()->GetKey1();

	if (Cursor - 2 >= 15.0f)
	{
		if (dwKey1 & KEY_UP)
			Cursor -= 2;
	}
	if (Cursor + 2 <= (15.0f + (3 * 2)))
	{
		if (dwKey1 & KEY_DOWN)
			Cursor += 2;
	}
	

	if (dwKey1 & KEY_RETURN)
	{
		switch (Cursor)
		{
		case 15:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			break;

		case 17:
			// Option
			break;

		case 19:
			// Store
			break;

		case 21:
			SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
			break;
		}
	}
}

void Menu::Render()
{
	for (int i = 0; i < MaxSize; ++i)
	{
		if (Cursor == (15.0f + (i * 2)))
			Color = 15;
		else
			Color = 8;
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[1] / 2 + 2), 15.0f + (i * 2), (char*)"[             ]", Color);
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[i] / 2), 15.0f + (i * 2), Buffer[i], Color);
	}
}

void Menu::Release()
{

}

