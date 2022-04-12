#define _CRT_SECURE_NO_WARNINGS //맨위에 사용
#include <stdio.h>
#include <string> //strcpy 같은 문자열 함수 사용할때 필요

//#include <string> 문자열 추가
//#define _CRT_SECURE_NO_WARNINGS 문자열 사용할때 오류나면 맨위에 이거입력




//typedef 는 별명지어 주는의미
//struct 는 변수들의 집합 의미 정리정돈
typedef struct taginfo
{
	char name[7];
	int number;

	int ikor;
	int ieng;
	int imath;
	
}INFO;

/*
struct taginfo
{
	int ikor;
	int ieng;
	int imath;
};
*/



int main (void)
{

	/*
	// ** 10명의 학생이 있고, 각각의 학생은 국어, 영어, 수학 점수가 있다.
	// ** 임이의 값으로 초기화 해서 출력해보자.

	int iKor[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int iEnd[10] = { 70, 50, 100, 25, 30, 40, 60, 80, 20, 90};
	int iMath[10] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

	for (int i = 0; i < 10; ++i)
	{
		printf_s("%d %d %d\n", iKor[i], iEnd[i], iMath[i]);
	}
	*/
	


	/*
	taginfo studenta;
	taginfo studentb;

	printf_s("studenta : \n");
	printf_s("국어점수 : ");
	scanf_s("%d", &studenta.ikor);
	printf_s("영어점수 : ");
	scanf_s("%d", &studenta.ieng);
	printf_s("수학점수 : ");
	scanf_s("%d", &studenta.imath);
	printf_s("국 : %d, 영 : %d, 수 : %d\n", studenta.ikor, studenta.ieng, studenta.imath);

	printf_s("studentb: \n");
	printf_s("국어점수 : ");
	scanf_s("%d", &studentb.ikor);
	printf_s("영어점수 : ");
	scanf_s("%d", &studentb.ieng);
	printf_s("수학점수 : ");
	scanf_s("%d", &studentb.imath);
	printf_s("국 : %d, 영 : %d, 수 : %d\n", studentb.ikor, studentb.ieng, studentb.imath);
    */


	/*
	// 선언
	INFO Info;

	// 문자열 복사
	strcpy(Info.Name, "홍길동");

	Info.iKor = 10;
	Info.iEng = 20;
	Info.iMath = 30;

	printf_s("%s\n", Info.Name);
	printf_s("%d\n", Info.iKor);
	printf_s("%d\n", Info.iEng);
	printf_s("%d\n", Info.iMath);
	*/


	/*
	INFO info;
	int iindex = 0;

	printf_s("당신의 직업은 무엇 입니까?\n");
	printf_s("****************************\n");
	printf_s("*     1. 도        적       *\n");
	printf_s("*     2. 마   법   사       *\n");
	printf_s("*     3. 전        사       *\n");
	printf_s("****************************\n");
	scanf_s("%d", &iindex);

	switch (iindex)
	{
	case 1:
		strcpy(info.name, "도적");
		break;
	case 2:
		strcpy(info.name, "마법사");
		break;
	case 3:
		strcpy(info.name, "전사");
		break;
	}

	printf_s("%s\n", info.name);
	*/




	// ** 3명의 학생 정보(이름, 국어, 영어, 수학)를 직접 입력하고,
	// ** 모든 입력이 끝나면 자동으로 입력한 내용을 출력하는 프로그램을 만들어보자.

	INFO student[3];
	
	

	printf_s("이름 입력 :");

	char name[128] = "";

	scanf_s("%s", name, strlen(name));
	
	printf_s("%s\n", name);



	






	return 0;

}