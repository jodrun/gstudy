#pragma once
#include "Headers.h"

class Map;
class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	Object* pBullet[128];
	Object* pPlayer;
	Object* pEnemy;
	Object* pMap;
public:
	void CreateObject(int _StateIndex);
	void Start();
	void Update();
	void Render();
	void Release();
private:
	ObjectManager();
public:
	~ObjectManager();
};

