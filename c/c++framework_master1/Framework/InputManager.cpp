#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : dwKey(0), dwKey1(0)
{
	for (int i = 0; i < 7; ++i)
	{
		PressedKey[i] = false;
	}
}

InputManager::~InputManager()
{

}

void InputManager::CheckKey()
{
	dwKey = 0;
	dwKey1 = 0;

	//dwKey
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W') )
		dwKey |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') )
		dwKey |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		dwKey |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		dwKey |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		dwKey |= KEY_RETURN;

	if (GetAsyncKeyState(VK_ESCAPE))
		dwKey |= KEY_ESCAPE;

	//dwKey1
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (PressedKey[0] == false)
		{
			dwKey1 |= KEY_UP;
			PressedKey[0] = true;
		}
	}
	else
	{
		PressedKey[0] = false;
	}

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (PressedKey[1] == false)
		{
			dwKey1 |= KEY_DOWN;
			PressedKey[1] = true;
		}
	}
	else
	{
		PressedKey[1] = false;
	}

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (PressedKey[2] == false)
		{
			dwKey1 |= KEY_LEFT;
			PressedKey[2] = true;
		}
	}
	else
	{
		PressedKey[2] = false;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (PressedKey[3] == false)
		{
			dwKey1 |= KEY_RIGHT;
			PressedKey[3] = true;
		}
	}
	else
	{
		PressedKey[3] = false;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (PressedKey[4] == false)
		{
			dwKey1 |= KEY_SPACE;
			PressedKey[4] = true;
		}
	}
	else
	{
		PressedKey[4] = false;
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		if (PressedKey[5] == false)
		{
			dwKey1 |= KEY_RETURN;
			PressedKey[5] = true;
		}
	}
	else
	{
		PressedKey[5] = false;
	}
		
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		if (PressedKey[6] == false)
		{
			dwKey1 |= KEY_ESCAPE;
			PressedKey[6] = true;
		}
	}
	else
	{
		PressedKey[6] = false;
	}
}
