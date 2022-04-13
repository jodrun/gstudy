#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>  //동적할당시 필요한 헤더

//포인터는 왜 쓰는가? 메모리에 할당 되있는 고정된 데이터에 4바이트 주소만으로 접근할수 있어서 프로그램을 가볍게 만듬


//동적할당(memory allocation) 이란 동적(변화)(변수)으로 바꿔주는것
//메모리에는 데이타(data), 힙(heap), 스텍(stack), 3가지영역이 있다. "동적할당은 힙영역에 할당됨"
//stack 은 탑으로 생각하면 됨 마지막 들어온 자료가 처음으로 나가짐
//heap 은 수동으로 작동함 필요없어진 힙자료도 수동으로 지워줌 (메모리 관리)

//동적할당은 #include <malloc.h>를 해준다

typedef struct taginventory
{
	int ihpotion;
	int impotion;
}INVENTORY;

typedef struct taginfo2
{
	int ix;
	int iy;
	INVENTORY* pinventory;
}INFO2;

typedef struct taginfo
{
	int ikor;
	int ieng;
	int imath;
}INFO;

char* SetName();


int main(void)
{

	/*
	INFO2* pinfo = (INFO2*)malloc(sizeof(INFO2)); //동적할당 식   맨앞 괄호는(포인터형식변환*)
	pinfo->pinventory = (INVENTORY*)malloc(sizeof(INVENTORY)); //동적할당 식

	pinfo->ix = 10;
	pinfo->iy = 20;
	pinfo->pinventory->ihpotion = 1;
	pinfo->pinventory->impotion = 2;

	printf_s("ix : iy = %d : %d\n", pinfo->ix, pinfo->iy);
	printf_s("ihpotion : impotion = %d : %d\n",
		pinfo->pinventory->ihpotion, pinfo->pinventory->impotion);

	free(pinfo->pinventory); //순서중요 struct안에 있는 포인터부터 지워줌
	free(pinfo);
	*/




	/*
	//입력을 임의로 저장할 공간.
	char buffer[128] = "";
    
	printf_s("이름 입력 : ");

	//입력을 받음
	scanf("%s", buffer);         //***** 배열은 &안써줌 *****

	//포인터 변수에 (문자열의 길이만큼) 동적할당 해줌
	//동적할당이란 동적(변화)하게 바꿔줌
	char* pname = (char*)malloc(strlen(buffer) + 1);

	//문자열 복사
	strcpy(pname, buffer);

	//출력
	printf_s("%s\n", pname);
	*/
	

	
	
	/*
	printf_s("%d\n", sizeof(INFO*));
	printf_s("%d\n", sizeof(INFO));
	*/

	
	
	/*
	INFO* pinfo = (INFO*)malloc(sizeof(INFO));

	pinfo->ikor = 10;
	pinfo->ieng = 20;
	pinfo->imath = 30;

	printf_s("국어점수 : %d\n", pinfo->ikor);
	printf_s("영어점수 : %d\n", pinfo->ieng);
	printf_s("수학점수 : %d\n", pinfo->imath);

	free(pinfo); //free() 동적할당 지우기
	*/


	


	return 0;
}


char* SetName()
{
	// ** 입력을 임의로 저장할 공간.
	char Buffer[128] = "";

	printf_s("이름 입력 : ");

	// ** 입력을 받음.
	scanf("%s", Buffer);

	// ** 포인터 변수에 (문자열의 길이만큼) 동적할당을 해준다. 
	char* pName = (char*)malloc(strlen(Buffer) + 1);

	// ** 문자열 복사.
	strcpy(pName, Buffer);


	return pName;
}
