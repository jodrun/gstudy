#include "Hard.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Hard::Hard()
{

}

Hard::~Hard()
{
	Release();
}

void Hard::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Hard::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Hard::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Hard::Release()
{

}
