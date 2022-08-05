#include "Map.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"

Map::Map()
{
}

Map::~Map()
{
}

void Map::Start()
{
	SetMaze(StrMaze);

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
}

int Map::Update()
{
	return 0;
}

void Map::Render()
{
	//  for(int i = 0; i < 110; ++i)
	//  	CursorManager::GetInstance()->WriteBuffer(6.0f + i, 2.0f, (char*)"#", 7);
	//  for (int i = 0; i < 34; ++i)
	//  	CursorManager::GetInstance()->WriteBuffer(6.0f, 3.0f + i, (char*)"#", 7);
	//  for (int i = 0; i < 34; ++i)
	//  	CursorManager::GetInstance()->WriteBuffer(115.0f, 3.0f + i, (char*)"#", 7);
	//  for (int i = 0; i < 110; ++i)
	//  	CursorManager::GetInstance()->WriteBuffer(6.0f + i, 37.0f, (char*)"#", 7);
	
	OutPutMaze(StrMaze);
}

void Map::Release()
{
	
}

void Map::SetMaze(char _Maze[MAPY][MAPX])
{
	strcpy_s(_Maze[0],  "00000000000000000000");
	strcpy_s(_Maze[1],  "00000000000000000000");
	strcpy_s(_Maze[2],  "00000000000000000000");
	strcpy_s(_Maze[3],  "00000000000000000000");
	strcpy_s(_Maze[4],  "00000000000000000000");
	strcpy_s(_Maze[5],  "00000000000000000000");
	strcpy_s(_Maze[6],  "00000000000000000000");
	strcpy_s(_Maze[7],  "00000000000000000000");
	strcpy_s(_Maze[8],  "00000000000000000000");
	strcpy_s(_Maze[9],  "00000000000000000000");
	strcpy_s(_Maze[10], "00000000000000000000");
	strcpy_s(_Maze[11], "00000000000000000000");
	strcpy_s(_Maze[12], "00000000000000000000");
	strcpy_s(_Maze[13], "00000000000000000000");
	strcpy_s(_Maze[14], "00000000000000000000");
	strcpy_s(_Maze[15], "00000000000000000000");
	strcpy_s(_Maze[16], "00000000000000000000");
	strcpy_s(_Maze[17], "00000000000000000000");
	strcpy_s(_Maze[18], "00000000000000000000");
	strcpy_s(_Maze[19], "00000000000000000003");
}

void Map::OutPutMaze(char _Maze[MAPY][MAPX])
{
    for (int i = 0; i < 1; ++i)
    {
    	for (int j = 0; j < MAPX; ++j)
    	{
    		if (_Maze[0][j] == '0')
    			CursorManager::GetInstance()->WriteBuffer(Info.Position.x += 1, Info.Position.y, (char*)"¡á");
    		//  else if (_Maze[i][j] == '1')
    		//  	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"  ");
    		//  else if (_Maze[i][j] == '2')
    		//  	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"¡Ú");
    		//  else if (_Maze[i][j] == '3')
    		//  	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"¡Ù");
    	}
    }
}
