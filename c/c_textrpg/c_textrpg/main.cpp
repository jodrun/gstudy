#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <time.h>
#include <Windows.h>



typedef struct tagInfo
{
	int HP;
	int MP;

	int EXP;

	int Att;
	int Def;

	short Level;

}INFO;

typedef struct tagObject
{
	char* Name;
	INFO Info;

}OBJECT;



char* SetName();



int main(void)
{
	SetName();
	





















	return 0;
}

char* SetName()
{
	char Buffer[128] = "";
	printf_s("이름 입력 : ");
	scanf_s("%s", Buffer);
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	strcpy(pName, Buffer);
	return pName;
}