#pragma once
#include "Object.h"

class Map : public Object
{
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Map();
	virtual ~Map();
};