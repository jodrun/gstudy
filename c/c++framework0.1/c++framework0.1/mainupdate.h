#pragma once
#include "header.h"

class Object;        //cpp���Ͽ��� "������Ʈ ��� ��Ŭ�����" (���)
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
	void start();    //�ʱ�ȭ
	void update();   //������� �� �浹 ���� �̺�Ʈ üũ
	void render();   //����(�׸���)
	void release();  //�޸� ����
public:
	mainupdate();
	~mainupdate();
};

