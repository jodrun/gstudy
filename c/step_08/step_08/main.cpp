#include <stdio.h>



int main(void)
{
	// ** [포인터 사용 방법 3 가지]
	// ** 1. [*] = 데이터   [&] = 주소
	// ** 2. 포인터 변수라면 무조건 [동적할당]을 해주도록 한다.
	// ** 3. [.] 아니면 [->]화살표



	// 포인터를 쓰는 이유는 최적화 문제 큰데이터 불러올때 포인터 사용하면 좋음 (굉장히빠르고 안정적임)
	
	
	int inumber = 19; //포인터로 받을변수(주소)
	int* pinumber; // 포인터 변수를 선언함
	
	pinumber = &inumber; //&주소변환자 포인터변수는 무조건 &(주소값)으로 받아야함

	printf_s("inumber  : %d\n", inumber);
	printf_s("*pinumber  : %d\n", *pinumber);
	printf_s("pinumber  : %d\n", pinumber);
	printf_s("&inumber  : %d\n", &inumber);
	printf_s("&pinumber  : %d\n", &pinumber);
	

	
	


	int i = 10;
	int* j;

	j = &i; 

	printf_s("값 : %d\n", j); //i 의 주소 출력
	printf_s("값 : %d\n", *j); // i 의 데이터 출력
	
	printf_s("값 : %d\n", &i); //i의 주소 출력
	







	int iNumber1 = 19;
	int iNumber2 = iNumber1;

	int* pPointer1 = &iNumber1;
	int* pPointer2 = &iNumber2;

	printf_s("pPointer1 : %d\n", *pPointer1);

	iNumber1 = 100; // 변경됬지만 밑에 출력해보면 19나옴

	printf_s("pPointer2 : %d\n", *pPointer2);
	












return 0;
}