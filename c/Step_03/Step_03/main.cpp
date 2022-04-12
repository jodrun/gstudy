#include <stdio.h>

int main(void)
{
	
	//변수 선언 방법 2가지
	//변수는 선언후 초기화 해줘야함 초기화란 10,20,30,40 처럼 값입력하는것
	int a, b;
	int c = 30, d = 40;

	a = 10;
	b = 20;

	printf_s("%d %d \n", a, b);
	printf_s("%d %d \n", c, d);



	//형식변환 ()안에 변수넣어주면 형식변환
	//ex) fnumber → (int)fnumber

	float fnumber;
	fnumber = 87.654321;

	printf_s("%f\n", fnumber);          //가장 적절한 식 87.654320 소수점6자리숫자는 다름
	printf_s("%d\n", (int)fnumber);       //int로 변환해서 정수값만 받음 87
	printf_s("%c\n", (char)fnumber);     //char 문자로 형식변환
	printf_s("%d\n", fnumber);         //잘못된값


	printf_s("%d\n", 3.14);
	printf_s("%d\n", 314);
	printf_s("%d\n", 0x13a);

	printf_s("%x\n", 0x13a); //대소문자 구분 %x %X
	printf_s("%X\n", 0X13A);
	

	printf_s("%d\n", 'A');
	printf_s("%c\n", 65);
	printf_s("%X\n", 'A');
	printf_s("%c\n", 'A');
	printf_s("%c\n", 35);
	printf_s("%c\n", 38);
	

	
	int iNum;
	float fNum;

	//scanf는 무조건 &써줘야함 
	//scanf는 "입력받는값" 즉 f5번눌러도 아무것도 안뜸
	printf_s("iNum 값 입력 : ");
	scanf_s("%d", &iNum);

	printf_s("fNum 값 입력 : ");
	scanf_s("%f", &fNum);

	printf_s("iNum : %d\n", iNum);
	printf_s("fNum : %f\n", fNum);
	

	
	printf_s("%d %d %d %d\n", 0, 1, 2, 3); // f5번 누르면 0,1,2,3 이렇게 나옴 순서 → 0,1,2,3





	return 0;

}