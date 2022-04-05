#include <stdio.h>

//전역변수 선언부
int count;
//이렇게 선언해놓으면 어드영역에서도 사용가능
//하지만 목욕바구니처럼 많을수록 무거워짐 그래서 최소한만씀



//매개 변수는 해당 영역을 벗어날수 없다.
float getangle(float _deg) //()괄호안에 매개변수 선언함
{

	return 0;
}
//매개 변수는 딱 요안에서만 사용가능 {}


// return 즉 함수사용
int sum(int _i, int _j)
{
	return _i + _j;
}




int main(void)
{
	/*
	//switch문이 if보다 조금더 빠름 "정수인 상수만 가능"
	int imonth;
	printf_s("탄생석! 태어난 달 : ");
	scanf_s("%d", &imonth);
	printf_s("당신의 탄생석은");

	switch (imonth)
	{
	case 1:
		printf_s("가넷 입니다");
		break;
	case 2:
		printf_s("자수정 입니다");
		break;
	case 3:
		printf_s("아쿠아마린 입니다");
		break;
	case 4:
		printf_s("다이아몬드 입니다");
		break;
	case 5:
		printf_s("에메랄드 입니다");
		break;
	case 6:
		printf_s("진주 입니다");
		break;
	case 7:
		printf_s("루비 입니다");
		break;
	case 8:
		printf_s("페리도트 입니다");
		break;
	case 9:
		printf_s("사파이어 입니다");
		break;
	case 10:
		printf_s("오팔 입니다");
		break;
	case 11:
		printf_s("토파즈 입니다");
		break;
    case 12:
		printf_s("터키석 입니다");
		break;
	default:
		printf_s("잘못입력하셨습니다");

	}
	*/

	/*
	//지역변수
	int val = 10;

	if (val == 10)
	{
		int val = 20; //변수 이름이 같을경우 해당영역에 해당하는 변수가 우선순위 즉 "여기선 if영역에 들어온 int val = 20 이 우선순위"

		printf_s("%d\n", val);
    }
	*/

	

	sum(10, 20); //위에 return 사용 즉 sum함수 사용 30

	int result = sum(10, 20);
	printf_s("result : %d\n", result);
	
	
	return 0;
}

//매개변수나 지역변수나 딱 그함수영역 에서만 사용가능