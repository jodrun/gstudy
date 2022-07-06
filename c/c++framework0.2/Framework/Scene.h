#pragma once
#include "Headers.h"

class Scene
{
public:
	virtual void Start()PURE;   //오버라이드 된 함수가 실행됨 로고, 메뉴, 스테이지 등등
	virtual void Update()PURE;	//오버라이드 된 함수가 실행됨 로고, 메뉴, 스테이지 등등
	virtual void Render()PURE;	//오버라이드 된 함수가 실행됨 로고, 메뉴, 스테이지 등등
	virtual void Release()PURE;	//오버라이드 된 함수가 실행됨 로고, 메뉴, 스테이지 등등
public:
	Scene();
	virtual ~Scene();
};

