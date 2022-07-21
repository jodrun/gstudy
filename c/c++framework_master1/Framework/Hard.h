#pragma once
#include "Scene.h"

class Hard : public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Hard();
	virtual ~Hard();
};

