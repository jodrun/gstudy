#pragma once
#include "Object.h"

class Map : public Object
{
public:
	char StrMaze[31][101] = {};
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetMaze(char _Maze[31][101]);
public:
	Map();
	virtual ~Map();
};