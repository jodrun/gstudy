#include "Easy.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Easy::Easy()
{

}

Easy::~Easy()
{
	Release();
}

void Easy::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Easy::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Easy::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Easy::Release()
{

}