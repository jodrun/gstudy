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

	Info.Position = Vector3(24.0f, 7.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
}

int Map::Update()
{
	Info.Position = Vector3(24.0f, 7.0f);
	return 0;
}

void Map::Render()
{
	OutPutMaze(StrMaze);
}

void Map::Release()
{
	
}

void Map::SetMaze(char _Maze[MAPY][MAPX])
{
	strcpy_s(_Maze[0],  "21110111111111111111110011111001111111110000000000");
	strcpy_s(_Maze[1],  "10000100000000000000100010001111000000010000000000");
	strcpy_s(_Maze[2],  "10000111111111110000111110000000000000010000000000");
	strcpy_s(_Maze[3],  "10000100000010000000100011111111111000010000000000");
	strcpy_s(_Maze[4],  "11111100000010000000100000000000001111011111000000");
	strcpy_s(_Maze[5],  "00000111111011111111100000000000001000000001111100");
	strcpy_s(_Maze[6],  "01000000001000000000000000111111111111100001000000");
	strcpy_s(_Maze[7],  "01000000001000000000000000000000000000100001000000");
	strcpy_s(_Maze[8],  "01011110001000000000000000000000000000100001111100");
	strcpy_s(_Maze[9],  "01010010001111111111111000000000000000100000000100");
	strcpy_s(_Maze[10], "01010011111000000000001111111111111111100000000100");
	strcpy_s(_Maze[11], "01011010001000000000000100000000000000100001111100");
	strcpy_s(_Maze[12], "01011010001000000000111100111111111111100001000000");
	strcpy_s(_Maze[13], "01000010001111111110100000111111111000101111111100");
	strcpy_s(_Maze[14], "01111110000000000010101111100000000000100000000100");
	strcpy_s(_Maze[15], "00000000000000000010100000101111111111111111110100");
	strcpy_s(_Maze[16], "00111111111111111110111111101000000000100000001100");
	strcpy_s(_Maze[17], "00100000000000000010000000001000000000100000111000");
	strcpy_s(_Maze[18], "00100000000000000011100000001000000000100000100000");
	strcpy_s(_Maze[19], "00100000000000000000010000000000000000000000100000");
	strcpy_s(_Maze[20], "00111111111111111110010000001111111111111111100000");
	strcpy_s(_Maze[21], "00000010000000000000010000000000000000101000000000");
	strcpy_s(_Maze[22], "00011111111111111111111100011111111111101011111111");
	strcpy_s(_Maze[23], "00000000000000000000000000010000000000001000010010");
	strcpy_s(_Maze[24], "00000000000000000000000000011111111101111111110013");
}

void Map::OutPutMaze(char _Maze[MAPY][MAPX])
{

    for (int i = 0; i < MAPY; ++i)
    {
    	for (int j = 0; j < MAPX; ++j)
    	{
    		if (_Maze[i][j] == '0')
    			CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"¡á");
    	    else if (_Maze[i][j] == '1')
    		 	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"  ");
    		else if (_Maze[i][j] == '2')
    		  	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"¡Ú");
    		else if (_Maze[i][j] == '3')
    		  	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"¡Ù");
			Info.Position.x += 2;
    	}
		Info.Position.x = 24;
		Info.Position.y += 1;
    }

}
