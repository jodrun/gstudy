#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = ObjectFactory::CreateBullet(Vector3(74.0f, 1.0f));

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = MathManager::GetDirection(pBullet[i]->GetPosition(), pPlayer->GetPosition());
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			}
				break;
			case 1:
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			}
			break;
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();
	pEnemy = ObjectFactory::CreateEnemy();
}

void ObjectManager::Update()
{
	pPlayer->Update();
	pEnemy->Update();

	int result = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])               // if문 사용하는 이유는 createobject가 실행이 안됬으면 계속 nullptr 이기 때문에 오류나는거임
		{
			result = pBullet[i]->Update();

			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(), 
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다.");
				//delete pBullet[i];		 // 충돌후 불렛삭제
				//pBullet[i] = nullptr;    // 충돌후 불렛삭제
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}

void ObjectManager::Render()
{
	pPlayer->Render();
	pEnemy->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}