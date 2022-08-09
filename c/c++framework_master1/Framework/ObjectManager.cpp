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
	
}

void ObjectManager::Start()
{
	pMap = ObjectFactory::CreateMap();
	pPlayer = ObjectFactory::CreatePlayer();
	pEnemy = ObjectFactory::CreateEnemy();
}

void ObjectManager::Update()
{
	pMap->Update();
	pPlayer->Update();
	pEnemy->Update();
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