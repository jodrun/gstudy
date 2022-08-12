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

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	pMap = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::CreateObject(int _StateIndex)
{
	switch(_StateIndex)
		case 1:

			break;

}

void ObjectManager::Start()
{
	pMap = ObjectFactory::CreateMap();
	pPlayer = ObjectFactory::CreatePlayer();
	pEnemy = ObjectFactory::CreateEnemy();
}

void ObjectManager::Update()
{
	int result = 0;

	pMap->Update();
	pPlayer->Update();

	if (pEnemy)
	{
		result = pEnemy->Update();

		if (CollisionManager::RectCollision(
			pPlayer->GetTransform(),
			pEnemy->GetTransform()))
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다.");
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
		}
	}
}

void ObjectManager::Render()
{
	pMap->Render();
	pPlayer->Render();
	pEnemy->Render();
}

void ObjectManager::Release()
{
	delete pMap;
	pMap = nullptr;

	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;
}