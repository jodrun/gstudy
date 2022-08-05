#pragma once
#include "Object.h"

class Map : public Object
{
public:
	char StrMaze[MAPY][MAPX] = {};
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetMaze(char _Maze[MAPY][MAPX]);
	void OutPutMaze(char _Maze[MAPY][MAPX]);
public:
	Map();
	virtual ~Map();
};