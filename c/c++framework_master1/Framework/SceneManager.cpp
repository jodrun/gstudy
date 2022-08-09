#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Easy.h"
#include "Normal.h"
#include "Hard.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SCENEID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;

	case SCENEID::MENU:
		SceneState = new Menu;
		break;

	case SCENEID::STAGE:
		SceneState = new Stage;
		break;

	case SCENEID::EASY:
		SceneState = new Easy;
		break;

	case SCENEID::NORMAL:
		SceneState = new Normal;
		break;

	case SCENEID::HARD:
		SceneState = new Hard;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;
	}

	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}
