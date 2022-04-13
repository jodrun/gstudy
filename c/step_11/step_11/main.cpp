#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>  //rad(랜덤)함수 사용 가능한 헤더
#include <time.h> //랜덤함수 사용할때 사용 헤더



char* SetName()
{
	char Buffer[1024] = "";

	printf("당신의 이름을 입력하세요.\n");
	printf("입력 : ");

	scanf("%s", Buffer);

	//     결과값을 받아올 포인터 변수 (힘영역에 저장된 문자열의 주소를 받아옴)
	//     ▽        
	//     ▽        힙 영역에 저장될 문자열의 형태
	//     ▽        ▽     
	//     ▽        ▽     malloc(크기) = 동적할당
	//     ▽        ▽     ▽        
	//     ▽        ▽     ▽        strlen(문자열) = 문자열의 길이를 반환
	//     ▽        ▽     ▽        ▽
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	//△            △
	//└─────────────┘    같은 형태이어야 한다.


	// ** strcpy(복상할 위치, 복사대상);
	// ** strcpy(pName, Buffer);  Buffer 를 pName으로 복사함.
	strcpy(pName, Buffer);

	return pName;
}



int main(void)
{
	/*
	printf("게임이 시작됩니다.\n");

	char Buffer[128] = "";
	char* pName = SetName();

	printf("당신의 이름은 [%s] 이군요 !!\n", pName);
	*/
	



	/*
	char calphabet;
	char changuel;

	calphabet = 'a';  //알바벳을 제외한 언어는 모두 2byte
	changuel = '한';  // 1byte인 char 형에 한글 저장 안됨 (한글 2byte)

	printf_s("alphabet : %c / hanguel : %c\n", calphabet, changuel);
	char charray[] = "한";       //한글 저장시 문자열 사용
	printf_s("%s\n\n", charray);  //문자열 정의는"";

	printf_s("%d\n\n", sizeof(charray)); //크기 3바이트 한글은 2바이트 1바이트는 널값
	*/



	/*
	char buffer[128] = "abcdefg"; // 배열 문자열은 선언과 동시에 초기화 해줘야함
	*/



	/*
	char* cparray = (char*)"character pointer array";

	printf_s("&cparray     : %d\n", &cparray);
	printf_s("cparray      : %d\n", cparray);
	printf_s("&cparray[0]  : %d\n", &cparray[0]);
	printf_s("cparray      : %s\n\n", cparray);

	printf_s("*cparray     : %c\n", *cparray);
	printf_s("cparray[0]   : %c\n", cparray[0]);
	printf_s("cparray[1]   : %c\n\n", cparray[1]);

	printf_s("*cparray++   : %c\n", *cparray++);
	printf_s("cparray      : %s\n", cparray);
	printf_s("*cparray     : %c\n", *cparray--);
	printf_s("cparray      : %s\n\n", cparray);

	printf_s("cparray      : %d\n", cparray);
	printf_s("*cparray     : %c\n\n", *cparray);
	cparray++;
	printf_s("cparray      : %d\n", cparray);
	printf_s("cparray[0]   : %c\n\n", cparray[0]);
	*/



	/*
	//swap 사용방법
	int i = 10;
	int j = 20;

	int temp = i;
	i = j;
	j = temp;

	printf_s("%d\n", i);
	printf_s("%d\n", j);
	*/

    

	/*
	//랜덤 함수 사용방법

	//랜덤함수초기화
	srand(time(NULL));

	//랜덤함수
	int i = rand() % 45 + 1; // 1~44까지 랜덤값 나옴


	printf_s("d\n", i);
	*/
	


	//로또 6자리 당첨번호
    const int max = 7;
	
	int array[8];

	time_t ttime = time(NULL);
	int i = 0;

	while (true)
	{
		if (ttime < time(NULL))
		{
			ttime = time(NULL);

			srand(time(NULL));
			array[i] = rand() % 45 + 1;

			i++;

			if (i >= max)
				break;
		}
    }

	for (int i = 0; i < max; ++i)
		printf_s("%d ", array[i]);




	return 0;
}