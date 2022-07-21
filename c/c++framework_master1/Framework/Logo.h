#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	int Length;
	int MaxSize;
	char* Buffer[8];
	char* Buffer2022[4];
	char* BufferPressEnter;
	int Color;
	int ColorPressEnter;
	ULONGLONG Time;
	ULONGLONG TimeEnter;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};