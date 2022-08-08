#pragma once
#include "Headers.h"


class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}
public:
	Scene* GetSceneState;
private:
	Scene* SceneState;
public:
	void SetScene(SCENEID _SceneID);
	void Update();
	void Render();
	void Release();
private:
	SceneManager();
public:
	~SceneManager();
};

