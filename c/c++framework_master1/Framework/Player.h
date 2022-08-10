#pragma once
#include "Object.h"

class Map;
class Player : public Object
{
public:
	Map* Maze;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Player();
	virtual ~Player();
};

