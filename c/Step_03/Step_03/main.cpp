#include <stdio.h>

int main(void)
{
	
	//���� ���� ��� 2����
	//������ ������ �ʱ�ȭ ������� �ʱ�ȭ�� 10,20,30,40 ó�� ���Է��ϴ°�
	int a, b;
	int c = 30, d = 40;

	a = 10;
	b = 20;

	printf_s("%d %d \n", a, b);
	printf_s("%d %d \n", c, d);



	//���ĺ�ȯ ()�ȿ� �����־��ָ� ���ĺ�ȯ
	//ex) fnumber �� (int)fnumber

	float fnumber;
	fnumber = 87.654321;

	printf_s("%f\n", fnumber);          //���� ������ �� 87.654320 �Ҽ���6�ڸ����ڴ� �ٸ�
	printf_s("%d\n", (int)fnumber);       //int�� ��ȯ�ؼ� �������� ���� 87
	printf_s("%c\n", (char)fnumber);     //char ���ڷ� ���ĺ�ȯ
	printf_s("%d\n", fnumber);         //�߸��Ȱ�


	printf_s("%d\n", 3.14);
	printf_s("%d\n", 314);
	printf_s("%d\n", 0x13a);

	printf_s("%x\n", 0x13a); //��ҹ��� ���� %x %X
	printf_s("%X\n", 0X13A);
	

	printf_s("%d\n", 'A');
	printf_s("%c\n", 65);
	printf_s("%X\n", 'A');
	printf_s("%c\n", 'A');
	printf_s("%c\n", 35);
	printf_s("%c\n", 38);
	

	
	int iNum;
	float fNum;

	//scanf�� ������ &������� 
	//scanf�� "�Է¹޴°�" �� f5�������� �ƹ��͵� �ȶ�
	printf_s("iNum �� �Է� : ");
	scanf_s("%d", &iNum);

	printf_s("fNum �� �Է� : ");
	scanf_s("%f", &fNum);

	printf_s("iNum : %d\n", iNum);
	printf_s("fNum : %f\n", fNum);
	

	
	printf_s("%d %d %d %d\n", 0, 1, 2, 3); // f5�� ������ 0,1,2,3 �̷��� ���� ���� �� 0,1,2,3





	return 0;

}