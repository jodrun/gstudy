#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>  //rad(����)�Լ� ��� ������ ���
#include <time.h> //�����Լ� ����Ҷ� ��� ���



char* SetName()
{
	char Buffer[1024] = "";

	printf("����� �̸��� �Է��ϼ���.\n");
	printf("�Է� : ");

	scanf("%s", Buffer);

	//     ������� �޾ƿ� ������ ���� (�������� ����� ���ڿ��� �ּҸ� �޾ƿ�)
	//     ��        
	//     ��        �� ������ ����� ���ڿ��� ����
	//     ��        ��     
	//     ��        ��     malloc(ũ��) = �����Ҵ�
	//     ��        ��     ��        
	//     ��        ��     ��        strlen(���ڿ�) = ���ڿ��� ���̸� ��ȯ
	//     ��        ��     ��        ��
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	//��            ��
	//������������������������������    ���� �����̾�� �Ѵ�.


	// ** strcpy(������ ��ġ, ������);
	// ** strcpy(pName, Buffer);  Buffer �� pName���� ������.
	strcpy(pName, Buffer);

	return pName;
}



int main(void)
{
	/*
	printf("������ ���۵˴ϴ�.\n");

	char Buffer[128] = "";
	char* pName = SetName();

	printf("����� �̸��� [%s] �̱��� !!\n", pName);
	*/
	



	/*
	char calphabet;
	char changuel;

	calphabet = 'a';  //�˹ٺ��� ������ ���� ��� 2byte
	changuel = '��';  // 1byte�� char ���� �ѱ� ���� �ȵ� (�ѱ� 2byte)

	printf_s("alphabet : %c / hanguel : %c\n", calphabet, changuel);
	char charray[] = "��";       //�ѱ� ����� ���ڿ� ���
	printf_s("%s\n\n", charray);  //���ڿ� ���Ǵ�"";

	printf_s("%d\n\n", sizeof(charray)); //ũ�� 3����Ʈ �ѱ��� 2����Ʈ 1����Ʈ�� �ΰ�
	*/



	/*
	char buffer[128] = "abcdefg"; // �迭 ���ڿ��� ����� ���ÿ� �ʱ�ȭ �������
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
	//swap �����
	int i = 10;
	int j = 20;

	int temp = i;
	i = j;
	j = temp;

	printf_s("%d\n", i);
	printf_s("%d\n", j);
	*/

    

	/*
	//���� �Լ� �����

	//�����Լ��ʱ�ȭ
	srand(time(NULL));

	//�����Լ�
	int i = rand() % 45 + 1; // 1~44���� ������ ����


	printf_s("d\n", i);
	*/
	


	//�ζ� 6�ڸ� ��÷��ȣ
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