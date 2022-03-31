#include <stdio.h>



// main = 위치에 상관없이 컴파일러는 main 제일먼저 찾음, 그리고 main만 실행하고 종료시킴 "프로젝트 마다 딱한개만 존재가능"
int main(void)
{
	//printf = print function(함수) 즉 출력함수다 _s는 안써도됨
	printf_s("hello, world!!\n");

    //sizeof 자료형의 크기를 바이트 단위로 변환시켜주는 명령이다.
	//%d(정수), %f(실수), %c(문자), %s(문자열) 에 대해 알고싶으면 네이버에 "서식문자" 치면됨 많이 쓰는거 
	printf_s("char : %d\n", sizeof(char));
	printf_s("short : %d\n", sizeof(short));
	printf_s("int : %d\n", sizeof(int));
	printf_s("float : %d\n", sizeof(float));
	printf_s("long : %d\n", sizeof(long));
	printf_s("double : %d\n", sizeof(double));

	//\n은 줄바꿈 \t는 공백
	printf_s("*************************************\n");
	printf_s("let's study c/c++ game programming!!!\n");
	printf_s("*************************************\n");

	//위에랑 같음 \n으로 줄바꿈 해서 한줄에 입력가능
	printf_s("*************************************\nlet's study c/c++ game programming!!!\n*************************************\n");
	
	
	//return 0; 는 함수를 종료시키는 명령어
	return 0;
}



/*****

unsigned = -생략
ex) uint, ushort .. 등등

*****/