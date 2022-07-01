#include "mainupdate.h"



// singleton == 디자인 패턴, 단일 객체
// singleton 쓰임새
// 1, 관리자(선생같은의미)
// 2, 어디에서나 호출 가능

// static 은 데이터영역
// 데이터영역은 값만 올라감(상수)
class singleton
{
private:
	static singleton* instance;
public:
	static int number;                   // 스테틱은 한개 100개만들어도 한개  ex) single1, single2. number 은 둘다 똑같음
	int num;
	static singleton* getinstance()
	{
		if (instance == nullptr)
			instance = new singleton;
		return instance;
	}
};

singleton* singleton::instance = nullptr; //  스테틱은 nullptr 이렇게 줌 





int main(void)
{
	// 메인클레스 생성
	mainupdate main;
	// 초기화
	main.start();



	//singleton
	//변수 = l벨류, 상수 = 벨류
	singleton single1, single2;

	single1.num = 10;
	single1.number = 100;

	single2.num = 20;



	// DWORD;        // unsigned long
	// ULONGLONG;    // unsigned int64
	 
	// DWORD time = GetTickCount()     // max 시간 = 49일, 컴퓨터(서버)가 켜진시간
	// ULONGLONG time = GetTickCount64 // max 시간 = 500년, 컴퓨터(서버)가 켜진시간

	ULONGLONG time = GetTickCount64();
	ULONGLONG timer = GetTickCount64();

	while (true)
	{
		if (time + 30 <= GetTickCount64())
		{
			time = GetTickCount64();

			system("cls");

			/*
			// 변경사항
			main.update();

			// 그리기
			main.render();
			*/
			main.render();
			if (timer + 1000 <= GetTickCount64())
			{
				timer = GetTickCount64();
				main.update();
			}
			
		}
	}



	return 0;
}