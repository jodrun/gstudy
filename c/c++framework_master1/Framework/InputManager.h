#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
private:
	DWORD dwKey;
	DWORD dwKey1;
	bool PressedKey[8];
public:
	void CheckKey();
	DWORD GetKey() { return dwKey; }
	DWORD GetKey1() { return dwKey1; }
private:
	InputManager();
public:
	~InputManager();
};

