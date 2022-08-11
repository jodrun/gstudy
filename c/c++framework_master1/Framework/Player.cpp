#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Map.h"

Player::Player() : Maze(nullptr)
{
}

Player::~Player() 
{
	Release();
}

void Player::Start()
{
	Info.Position = Vector3(24.0f, 7.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
}

int Player::Update()
{
	Maze = new Map;
	Maze->SetMaze(Maze->StrMaze);

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (Info.Position.y >= 8.0f)
	{
		if (Maze->StrMaze[((int)Info.Position.y - 7) - 1][((int)Info.Position.x - 24) / 2] != '0')
		{
			if (dwKey & KEY_UP)
				Info.Position.y--;
		}
	}

	if (Info.Position.y <= 30.0f)
	{
		if (Maze->StrMaze[((int)Info.Position.y - 7) + 1][((int)Info.Position.x - 24) / 2] != '0')
		{
			if (dwKey & KEY_DOWN)
				Info.Position.y++;
		}
	}

	if (Info.Position.x >= 26.0f)
	{
		if (Maze->StrMaze[((int)Info.Position.y - 7)][((int)Info.Position.x - 24) / 2 - 1] != '0')
		{
			if (dwKey & KEY_LEFT)
				Info.Position.x -= 2;
		}
	}

	if (Info.Position.x <= 120.0f)
	{
		if (Maze->StrMaze[((int)Info.Position.y - 7)][((int)Info.Position.x - 24) / 2 + 1] != '0')
		{
			if (dwKey & KEY_RIGHT)
				Info.Position.x += 2;
		}
	}

	if (dwKey & KEY_SPACE)
		
	if (dwKey & KEY_ESCAPE)

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"À¿", 10);
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x - Info.Position.x + 70, Info.Position.y - Info.Position.y, (char*)"X : ");
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x - Info.Position.x + 74, Info.Position.y - Info.Position.y, Info.Position.x);
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x - Info.Position.x + 78, Info.Position.y - Info.Position.y, (char*)"Y : ");
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x - Info.Position.x + 82, Info.Position.y - Info.Position.y, Info.Position.y);
}

void Player::Release()
{
	delete Maze;
	Maze = nullptr;
}