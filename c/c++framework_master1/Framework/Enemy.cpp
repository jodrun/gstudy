#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Map.h"
#include "MathManager.h"

Enemy::Enemy() : Emap(nullptr)
{
}

Enemy::~Enemy()
{
	Release();
}

void Enemy::Start()
{
	Emap = new Map;

	Info.Position = Vector3(118.0f, 12.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();

	Speed = 0.0f;

	srand(time(NULL));
}

int Enemy::Update()
{
	Emap->SetMaze(Emap->StrMaze);
	int ran = 0;
	ran = (rand() % 5) + 1;

	switch (ran)
	{
	case 1:
		if (Info.Position.y >= 8.0f)
		{
			if (Emap->StrMaze[((int)Info.Position.y - 7) - 1][((int)Info.Position.x - 24) / 2] != '0')
			{
				Info.Position.y--;
			}
		}
		break;
	case 2:
		if (Info.Position.y <= 30.0f)
		{
			if (Emap->StrMaze[((int)Info.Position.y - 7) + 1][((int)Info.Position.x - 24) / 2] != '0')
			{
				Info.Position.y++;
			}
		}
		break;
	case 3:
		if (Info.Position.x >= 26.0f)
		{
			if (Emap->StrMaze[((int)Info.Position.y - 7)][((int)Info.Position.x - 24) / 2 - 1] != '0')
			{
				Info.Position.x -= 2;
			}
		}
		break;
	case 4:
		if (Info.Position.x <= 120.0f)
		{
			if (Emap->StrMaze[((int)Info.Position.y - 7)][((int)Info.Position.x - 24) / 2 + 1] != '0')
			{
				Info.Position.x += 2;
			}
		}
		break;
	}


	if (Time + 250 < GetTickCount64())
	{
		Count++;
	
		if (Count >= 10)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(0);
		}
		else
			ObjectManager::GetInstance()->CreateObject(1);
	
		Time = GetTickCount64();
	}
	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"À¿", 12);
}

void Enemy::Release()
{
	delete Emap;
	Emap = nullptr;
}