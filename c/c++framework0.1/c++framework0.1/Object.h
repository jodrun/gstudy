#pragma once
#include "header.h"

class Object
{
private:
	int Time;
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	Object();
	~Object();
};

