#pragma once
#include "Headers.h"

class Scene
{
public:
	virtual void Start()PURE;   //�������̵� �� �Լ��� ����� �ΰ�, �޴�, �������� ���
	virtual void Update()PURE;	//�������̵� �� �Լ��� ����� �ΰ�, �޴�, �������� ���
	virtual void Render()PURE;	//�������̵� �� �Լ��� ����� �ΰ�, �޴�, �������� ���
	virtual void Release()PURE;	//�������̵� �� �Լ��� ����� �ΰ�, �޴�, �������� ���
public:
	Scene();
	virtual ~Scene();
};

