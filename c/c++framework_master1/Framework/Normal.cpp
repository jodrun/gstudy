#include "Normal.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Normal::Normal()
{

}

Normal::~Normal()
{

}

void Normal::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Normal::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Normal::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Normal::Release()
{

}
