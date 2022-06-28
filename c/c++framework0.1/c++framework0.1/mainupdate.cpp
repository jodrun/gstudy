#include "mainupdate.h"
#include "Object.h"               // ★★★헤더파일에는 메인헤더파일 빼고는 넣지않음★★★

mainupdate::mainupdate()
{

}

mainupdate::~mainupdate()
{
	release();
}

void mainupdate::start()
{
	h = 0;
	hc = 60;
	m = 0;
	mc = 60;
	s = 0;

	pPlayer = new Object;
	pPlayer->Start();
}
void mainupdate::update()
{
	s++;
	if (s > mc)
	{
		mc += 60;
		m += 1;
	}
	if (m > hc)
	{
		hc += 60;
		h += 1;
	}

	pPlayer->Update();
}
void mainupdate::render()
{
	cout << "h : " << h << endl;
	cout << "m : " << m << endl;
	cout << "s : " << s << endl;

	pPlayer->Render();
	
}
void mainupdate::release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
