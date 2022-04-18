#define _CRT_SECURE_NO_WARNINGS //strcpy ����Ҷ� ���Ȱ��� ����? ���� ����
#include <stdio.h> //���ٴٵ� ��ǲ �ƿ�ǲ ��� �Լ�����?
#include <string> //���ڿ� ����Ҷ� �ʿ�
#include <malloc.h> //�����Ҵ� �Ҷ� �ʿ�
#include <stdlib.h> //���ٴٵ� ���̺귯�� ��� 
#include <time.h> //rend �Լ� �ʱ�ȭ �Ҷ� �ʿ�?
#include <windows.h> //sleep �Լ� ����Ҷ� �ʿ��� �Լ�?



const int PLAYER = 0;    //
const int ENEMY = 1;     //
const int MAX = 2; 	     //***�𸣰ڽ��ϴ�*** (�� ����� �������)


typedef struct tagInfo   // typedef(Ÿ������(����) struct (����) �پ��� ������ �����ؼ� ��� 
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
	int Level;		     // �÷��̾ ������ �ɷ�ġ�� struct�� ��� ���
					    
}INFO;                   // taginfo ��� struct �� INFO ��� typedef�� ����. 


typedef struct tagObject //
{						 //	   
	INFO Info;			 //	   
						 //	   
}OBJECT; 				 //***�𸣰ڽ��ϴ�*** (�� INFO�� �ٽ� ����ȭ �ϴ���)




void InitializeObject(OBJECT* _Obj, int ObjectType); //***�𸣰ڽ��ϴ�*** 
char* SetName();                                     //***�𸣰ڽ��ϴ�*** (�����ͷ� ��������)


int main (void)          
{

	OBJECT* Objects[MAX];                                 //
														  //
	Objects[PLAYER] = (OBJECT*)malloc(sizeof(OBJECT));	  //
	InitializeObject(Objects[PLAYER], PLAYER);			  //
														  //
	Objects[ENEMY] = (OBJECT*)malloc(sizeof(OBJECT));	  //
	InitializeObject(Objects[ENEMY], ENEMY);			  //***�𸣰ڽ��ϴ�***


	while (true)                                                   // �ݺ��� true ����
	{
		
		system("cls");                                             // �ܼ�â�� ��� ����� �Լ�

		printf_s("\n[%s]\n", Objects[PLAYER]->Info.Name);		   // �÷��̾� �̸����� ���ڿ��� ���
		printf_s("HP : %d\n", Objects[PLAYER]->Info.HP);		   // �÷��̾� hp���� ������ ���
		printf_s("MP : %d\n", Objects[PLAYER]->Info.MP);		   // �÷��̾� mp���� ������ ���
		printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);	   // �÷��̾� ���ݷ��� �Ҽ���2��°�ڸ� ���� �Ǽ������� ���
		printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);	   // �÷��̾� ������ �Ҽ���2��°�ڸ� ���� �Ǽ������� ���
		printf_s("EXP : %d\n", Objects[PLAYER]->Info.EXP);		   // �÷��̾� ����ġ�� ���������� ���
		printf_s("Level : %d\n\n", Objects[PLAYER]->Info.Level);   // �÷��̾� ������ ���������� ���

		Sleep(500);												   // 0.5�ʸ�ŭ ��¿� �����ִ� �Լ�
																   
		printf_s("[%s]\n", Objects[ENEMY]->Info.Name);			   // �� �̸����� ���ڿ��� ���
		printf_s("HP : %d\n", Objects[ENEMY]->Info.HP);			   // �� hp���� ������ ���
		printf_s("MP : %d\n", Objects[ENEMY]->Info.MP);			   // �� mp���� ������ ���
		printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);	   // �� ���ݷ��� �Ҽ���2��°�ڸ� ���� �Ǽ������� ���
		printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);	   // �� ������ �Ҽ���2��°�ڸ� ���� �Ǽ������� ���
		printf_s("EXP : %d\n", Objects[ENEMY]->Info.EXP);		   // �� ����ġ�� ���������� ���
		printf_s("Level : %d\n\n", Objects[ENEMY]->Info.Level);	   // �� ������ ���������� ���

		Sleep(500);												   // 0.5�ʸ�ŭ ��¿� �����ִ� �Լ�

		int iChoice = 0;																		 // ���̽� ���� �ʱ�ȭ (������)
		printf_s("���Ϳ� �������ϴ�. �����Ͻðڽ��ϱ� ?\n1. ����\n2. ����\n�Է� : ");		     // ���
		scanf_s("%d", &iChoice);																 // ���̽� ���� �Է� 1, ���� 2, ����

		switch (iChoice)																		 // ����ġ�б�� : ���̽� ����
		{																						 
		case 1:																					 // ���̽��� 1�̸� (����)
			if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def)							 // �����б⹮ : �÷��̾� ���ݷ��� �����º��� ũ��
			{
				Objects[ENEMY]->Info.HP -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // �����б⹮ : �÷��̾� ���ݷ� - �� ���� ������ŭ �� hp - 
			}
			else
				Objects[ENEMY]->Info.HP -= 1;													 // ���� : �� �����б⹮ ������ �ƴϸ� �� hp - 1
			break;																				 // �극��ũ : ����ġ���� �������� ���Ϲ����� �ٽ�
		case 2:																					 // ���̽��� 2�̸�
			printf_s("����ġ�°Ϳ� [����] �߽��ϴ�.\n");										 // �������� ���
			break;																				 // �극��ũ : ����ġ���� �������� ���Ϲ����� �ٽ�
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
		break;												// ***�𸣰ڽ��ϴ�***
	}
}

char* SetName()												//***�÷��̾� �̸� �Լ� (�����ʹ� �� ��� �Ǿ����� �𸣰ڽ��ϴ�)
{															
	char Buffer[128] = "";									// �ѱ۷� �Է� �Ϸ��� ���� char���� �ʿ� �׷��� �迭 ���
															
	printf_s("�̸� �Է� : ");								// �̸� �Է� ���
	scanf("%s", Buffer);									// �̸���(buffer) �Է�
															
	char* pName = (char*)malloc(strlen(Buffer) + 1);		// �����Ҵ�
	strcpy(pName, Buffer);									// ***�𸣰ڽ��ϴ�***
															
	return pName;											// ***�𸣰ڽ��ϴ�***
}
