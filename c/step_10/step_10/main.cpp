#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>  //�����Ҵ�� �ʿ��� ���

//�����ʹ� �� ���°�? �޸𸮿� �Ҵ� ���ִ� ������ �����Ϳ� 4����Ʈ �ּҸ����� �����Ҽ� �־ ���α׷��� ������ ����


//�����Ҵ�(memory allocation) �̶� ����(��ȭ)(����)���� �ٲ��ִ°�
//�޸𸮿��� ����Ÿ(data), ��(heap), ����(stack), 3���������� �ִ�. "�����Ҵ��� �������� �Ҵ��"
//stack �� ž���� �����ϸ� �� ������ ���� �ڷᰡ ó������ ������
//heap �� �������� �۵��� �ʿ������ ���ڷᵵ �������� ������ (�޸� ����)

//�����Ҵ��� #include <malloc.h>�� ���ش�

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
	INFO2* pinfo = (INFO2*)malloc(sizeof(INFO2)); //�����Ҵ� ��   �Ǿ� ��ȣ��(���������ĺ�ȯ*)
	pinfo->pinventory = (INVENTORY*)malloc(sizeof(INVENTORY)); //�����Ҵ� ��

	pinfo->ix = 10;
	pinfo->iy = 20;
	pinfo->pinventory->ihpotion = 1;
	pinfo->pinventory->impotion = 2;

	printf_s("ix : iy = %d : %d\n", pinfo->ix, pinfo->iy);
	printf_s("ihpotion : impotion = %d : %d\n",
		pinfo->pinventory->ihpotion, pinfo->pinventory->impotion);

	free(pinfo->pinventory); //�����߿� struct�ȿ� �ִ� �����ͺ��� ������
	free(pinfo);
	*/




	/*
	//�Է��� ���Ƿ� ������ ����.
	char buffer[128] = "";
    
	printf_s("�̸� �Է� : ");

	//�Է��� ����
	scanf("%s", buffer);         //***** �迭�� &�Ƚ��� *****

	//������ ������ (���ڿ��� ���̸�ŭ) �����Ҵ� ����
	//�����Ҵ��̶� ����(��ȭ)�ϰ� �ٲ���
	char* pname = (char*)malloc(strlen(buffer) + 1);

	//���ڿ� ����
	strcpy(pname, buffer);

	//���
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

	printf_s("�������� : %d\n", pinfo->ikor);
	printf_s("�������� : %d\n", pinfo->ieng);
	printf_s("�������� : %d\n", pinfo->imath);

	free(pinfo); //free() �����Ҵ� �����
	*/


	


	return 0;
}


char* SetName()
{
	// ** �Է��� ���Ƿ� ������ ����.
	char Buffer[128] = "";

	printf_s("�̸� �Է� : ");

	// ** �Է��� ����.
	scanf("%s", Buffer);

	// ** ������ ������ (���ڿ��� ���̸�ŭ) �����Ҵ��� ���ش�. 
	char* pName = (char*)malloc(strlen(Buffer) + 1);

	// ** ���ڿ� ����.
	strcpy(pName, Buffer);


	return pName;
}
