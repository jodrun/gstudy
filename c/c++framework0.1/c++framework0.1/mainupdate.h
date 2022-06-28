#pragma once
#include "header.h"

class Object;        //cpp파일에서 "오브젝트 헤더 인클루드함" (허수)
class mainupdate
{
private:
	Object* pPlayer;
private:
	int h;
	int m;
	int s;
	int mc;
	int hc;
public:
	void start();    //초기화
	void update();   //변경사항 및 충돌 등의 이벤트 체크
	void render();   //렌더(그리기)
	void release();  //메모리 해제
public:
	mainupdate();
	~mainupdate();
};

