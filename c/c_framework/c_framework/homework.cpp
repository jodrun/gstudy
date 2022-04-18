#define _CRT_SECURE_NO_WARNINGS //strcpy 사용할때 보안관련 에러? 에러 무시
#include <stdio.h> //스텐다드 인풋 아웃풋 헤더 함수모음?
#include <string> //문자열 사용할때 필요
#include <malloc.h> //동적할당 할때 필요
#include <stdlib.h> //스텐다드 라이브러리 헤더 
#include <time.h> //rend 함수 초기화 할때 필요?
#include <windows.h> //sleep 함수 사용할때 필요한 함수?



const int PLAYER = 0;    //
const int ENEMY = 1;     //
const int MAX = 2; 	     //***모르겠습니다*** (왜 상수가 사용됬는지)


typedef struct tagInfo   // typedef(타입정의(별명) struct (구조) 다양한 변수를 저장해서 사용 
{
	char* Name;          //
	int HP; 		     //
	int MP;			     //
					     //
	int EXP;		     //
					     //
	float Att;		     //
	float Def;		     //
					     //
	int Level;		     // 플레이어나 몬스터의 능력치를 struct로 묶어서 사용
					    
}INFO;                   // taginfo 라는 struct 를 INFO 라는 typedef로 정의. 


typedef struct tagObject //
{						 //	   
	INFO Info;			 //	   
						 //	   
}OBJECT; 				 //***모르겠습니다*** (왜 INFO를 다시 구조화 하는지)




void InitializeObject(OBJECT* _Obj, int ObjectType); //***모르겠습니다*** 
char* SetName();                                     //***모르겠습니다*** (포인터로 쓰인이유)


int main (void)          
{

	OBJECT* Objects[MAX];                                 //
														  //
	Objects[PLAYER] = (OBJECT*)malloc(sizeof(OBJECT));	  //
	InitializeObject(Objects[PLAYER], PLAYER);			  //
														  //
	Objects[ENEMY] = (OBJECT*)malloc(sizeof(OBJECT));	  //
	InitializeObject(Objects[ENEMY], ENEMY);			  //***모르겠습니다***


	while (true)                                                   // 반복문 true 실행
	{
		
		system("cls");                                             // 콘솔창을 모두 지우는 함수

		printf_s("\n[%s]\n", Objects[PLAYER]->Info.Name);		   // 플레이어 이름값을 문자열로 출력
		printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);		   // 플레이어 hp값을 정수로 출력
		printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);		   // 플레이어 mp값을 정수로 출력
		printf_s("공격력 : %.2f\n", Objects[PLAYER]->Info.Att);	   // 플레이어 공격력을 소수점2번째자리 까지 실수형으로 출력
		printf_s("방어력 : %.2f\n", Objects[PLAYER]->Info.Def);	   // 플레이어 방어력을 소수점2번째자리 까지 실수형으로 출력
		printf_s("EXP : %d\n", Objects[PLAYER]->Info.EXP);		   // 플레이어 경험치를 정수형으로 출력
		printf_s("Level : %d\n\n", Objects[PLAYER]->Info.Level);   // 플레이어 레벨을 정수형으로 출력

		Sleep(500);												   // 0.5초만큼 출력에 텀을주는 함수
																   
		printf_s("[%s]\n", Objects[ENEMY]->Info.Name);			   // 적 이름값을 문자열로 출력
		printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);			   // 적 hp값을 정수로 출력
		printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);			   // 적 mp값을 정수로 출력
		printf_s("공격력 : %.2f\n", Objects[ENEMY]->Info.Att);	   // 적 공격력을 소수점2번째자리 까지 실수형으로 출력
		printf_s("방어력 : %.2f\n", Objects[ENEMY]->Info.Def);	   // 적 방어력을 소수점2번째자리 까지 실수형으로 출력
		printf_s("EXP : %d\n", Objects[ENEMY]->Info.EXP);		   // 적 경험치를 정수형으로 출력
		printf_s("Level : %d\n\n", Objects[ENEMY]->Info.Level);	   // 적 레벨을 정수형으로 출력

		Sleep(500);												   // 0.5초만큼 출력에 텀을주는 함수

		int iChoice = 0;																		 // 초이스 변수 초기화 (선택지)
		printf_s("몬스터와 만났습니다. 공격하시겠습니까 ?\n1. 공격\n2. 도망\n입력 : ");		     // 출력
		scanf_s("%d", &iChoice);																 // 초이스 값을 입력 1, 공격 2, 도망

		switch (iChoice)																		 // 스위치분기분 : 초이스 조건
		{																						 
		case 1:																					 // 초이스가 1이면 (공격)
			if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)							 // 이프분기문 : 플레이어 공격력이 적방어력보다 크면
			{
				Objects[ENEMY]->Info.HP -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // 이프분기문 : 플레이어 공격력 - 적 방어력 뺀값만큼 적 hp - 
			}
			else
				Objects[ENEMY]->Info.HP -= 1;													 // 엘스 : 위 이프분기문 조건이 아니면 적 hp - 1
			break;																				 // 브레이크 : 스위치문을 빠저나옴 와일문부터 다시
		case 2:																					 // 초이스가 2이면
			printf_s("도망치는것에 [성공] 했습니다.\n");										 // 도망성공 출력
			break;																				 // 브레이크 : 스위치문을 빠저나옴 와일문부터 다시
		}
	}

	return 0;
}




void InitializeObject(OBJECT* _Obj, int ObjectType)         //          
{															
	switch (ObjectType)										// 
	{														
	case PLAYER:											// 
		_Obj->Info.Name = SetName();						// 
															
		_Obj->Info.Att = 10;								// 
		_Obj->Info.Def = 10;								// 
		_Obj->Info.EXP = 0;									// 
		_Obj->Info.HP = 100;								// 
		_Obj->Info.MP = 10;									// 
		_Obj->Info.Level = 1;								// 
		break;												// 
	case ENEMY:												// 
		_Obj->Info.Name = (char*)"Enemy";					// 
															
		_Obj->Info.Att = 5;									// 
		_Obj->Info.Def = 15;								// 
		_Obj->Info.EXP = 0;									// 
		_Obj->Info.HP = 30;									// 
		_Obj->Info.MP = 5;									// 
		_Obj->Info.Level = 1;								// 
		break;												// ***모르겠습니다***
	}
}

char* SetName()												//***플레이어 이름 함수 (포인터는 왜 사용 되었는지 모르겠습니다)
{															
	char Buffer[128] = "";									// 한글로 입력 하려면 여러 char변수 필요 그래서 배열 사용
															
	printf_s("이름 입력 : ");								// 이름 입력 출력
	scanf("%s", Buffer);									// 이름값(buffer) 입력
															
	char* pName = (char*)malloc(strlen(Buffer) + 1);		// 동적할당
	strcpy(pName, Buffer);									// ***모르겠습니다***
															
	return pName;											// ***모르겠습니다***
}
