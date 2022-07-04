#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::Checkey()
{
	dwkey = 0;

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		dwkey |= KEY_UP;
	}

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		dwkey |= KEY_DOWN;
	}

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		dwkey |= KEY_LEFT;
	}

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		dwkey |= KEY_RIGHT;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		dwkey |= KEY_SPACE;
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		dwkey |= KEY_RETURN;
	}

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		dwkey |= KEY_ESCAPE;
	}
}
