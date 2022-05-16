#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //c++ 입출력 라이브러리

using namespace std; //iostream 을 사용할때 꼭 써줘야함



typedef struct taginfo
{
	int inumber;

	taginfo() //생성자 (구조체 안에서만 사용할수 있는 함수)
	{
		cout << "기본 생성장" << endl;
	};

	taginfo(int _inumber) //복사생성자
	{
		inumber = _inumber;
		cout << "복사 생성장" << endl;
	};

}INFO;



int main()
{
	/*
	//출력
	printf_s("문자 출력\n");
	
	cout << "문자 출력"; // 위랑 같은 의미 << (쉬프트연산자)
	*/

	/*
	//출력
	printf_s("\n줄바꿈\n");

	cout << "줄바꿈" << endl; // 위랑 같은 의미 (줄바꿈)
	*/



	/*
	//입력
	int inumber = 0;
	printf_s("입력 : ");
	scanf("%d", &inumber);

	printf_s("출력 : %d", inumber);
	*/
	
	/*
	int inumber = 0;
	cout << "입력: ";                                //출력 위와같음 <<
	cin >> inumber;                                  //입력 위와같음 >>
										            
	cout << "출력: " << inumber;                     //출력 위와같음 <<
	*/



	
	//동적할당
	INFO* pinfo = (INFO*)malloc(sizeof(INFO));
	
	INFO* pinfo = new INFO(10);                         //위와같음(동적할당)  여기서 뒤 INFO는 생성자 그래서 구조체안의 생성자에서 "생성자" 를 호출함
	                                                    //(10)은 복사생성자 
	cout << pinfo->inumber << endl;

	//동적할당 지우기
	free(pinfo);    

	delete pinfo;  //위와같음
	









	return 0;
}



