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
	DWORD dwkey;
public:
	void Checkey();
	DWORD GetKEY()
	{ 
		return dwkey; 
	}

private:
	InputManager();
public:
	~InputManager();
};
