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
	Info.Position = Vector3(6.0f, 4.0f);
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
	for(int i = 0; i < 110; ++i)
		CursorManager::GetInstance()->WriteBuffer(6.0f + i, 2.0f, (char*)"#", 7);
	for (int i = 0; i < 34; ++i)
		CursorManager::GetInstance()->WriteBuffer(6.0f, 3.0f + i, (char*)"#", 7);
	for (int i = 0; i < 34; ++i)
		CursorManager::GetInstance()->WriteBuffer(115.0f, 3.0f + i, (char*)"#", 7);
	for (int i = 0; i < 110; ++i)
		CursorManager::GetInstance()->WriteBuffer(6.0f + i, 37.0f, (char*)"#", 7);
}

void Map::Release()
{

}
