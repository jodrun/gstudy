#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "SceneManager.h"


ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), MapInt(0), ObjMap(nullptr)
{
	for (int i = 0; i < 128; ++i)
	{
		pBullet[i] = nullptr;
		pEnemy[i] = nullptr;
		pMap[i] = nullptr;
	}
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::CreateObject(int _StateIndex)
{
	switch (_StateIndex)
	{
	case 1:
		if (pMap[0] == nullptr && pEnemy[0] == nullptr)
		{
			pMap[0] = ObjectFactory::CreateMap();
			pEnemy[0] = ObjectFactory::CreateEnemy();
			MapInt = _StateIndex;
		}
		break;
	case 2:
		MapInt = _StateIndex;
		break;
	}	
}

void ObjectManager::Start()
{
	ObjMap = new Map;

	ObjMap->SetMaze(ObjMap->StrMaze);

	pPlayer = ObjectFactory::CreatePlayer();
}

void ObjectManager::Update()
{
	int result = 0;

	switch (MapInt)
	{
	case 1:
		pMap[0]->Update();
		break;
	case 2:
		break;
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pEnemy[i])
		{
			result = pEnemy[i]->Update();

			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pEnemy[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다.");
				SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			}
		}
	}

	// 멥[0] 골인
	if (pPlayer)
	{
		pPlayer->Update();

		if(pPlayer->Info.Position.x == 122 && pPlayer->Info.Position.y == 31 && (ObjMap->StrMaze[((int)pPlayer->Info.Position.y - 7)][((int)pPlayer->Info.Position.x - 24) / 2] == '3'))
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"클리어!.");
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < 128; ++i)
	{
		if (pMap[i])
			pMap[i]->Render();
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pEnemy[i])
			pEnemy[i]->Render();
	}
	
	pPlayer->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete ObjMap;
	ObjMap = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pMap[i])
		{
			delete pMap[i];
			pMap[i] = nullptr;
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}