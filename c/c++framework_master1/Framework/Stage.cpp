#include "Stage.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Stage::Stage() : Color(0), MaxSize(0), Cursor(0)
{
	for (int i = 0; i < 4; ++i)
	{
		Buffer[i] = nullptr;
		Length[i] = 0;
	}
}

Stage::~Stage()
{
	
}


void Stage::Start()
{
	Buffer[0] = (char*)"E a s y";
	Buffer[1] = (char*)"N o r m a l";
	Buffer[2] = (char*)"H a r d";
	Buffer[3] = (char*)"B a c k";

	Length[0] = strlen(Buffer[0]);
	Length[1] = strlen(Buffer[1]);
	Length[2] = strlen(Buffer[2]);
	Length[3] = strlen(Buffer[3]);

	MaxSize = 4;

	Color = 8;

	Cursor = 15;
}

void Stage::Update()
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
			SceneManager::GetInstance()->SetScene(SCENEID::EASY);
			break;

		case 17:
			SceneManager::GetInstance()->SetScene(SCENEID::NORMAL);
			break;

		case 19:
			SceneManager::GetInstance()->SetScene(SCENEID::HARD);
			break;

		case 21:
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
			break;
		}
	}
}

void Stage::Render()
{
	for (int i = 0; i < MaxSize; ++i)
	{
		if (Cursor == (15.0f + (i * 2)))
			Color = 15;
		else
			Color = 8;
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[1] / 2 + 4), 15.0f + (i * 2), (char*)"[[[             ]]]", Color);
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[i] / 2), 15.0f + (i * 2), Buffer[i], Color);
	}
}

void Stage::Release()
{
	
}

