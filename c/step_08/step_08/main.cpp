#include <stdio.h>



int main(void)
{
	// ** [������ ��� ��� 3 ����]
	// ** 1. [*] = ������   [&] = �ּ�
	// ** 2. ������ ������� ������ [�����Ҵ�]�� ���ֵ��� �Ѵ�.
	// ** 3. [.] �ƴϸ� [->]ȭ��ǥ



	// �����͸� ���� ������ ����ȭ ���� ū������ �ҷ��ö� ������ ����ϸ� ���� (������������ ��������)
	
	
	int inumber = 19; //�����ͷ� ��������(�ּ�)
	int* pinumber; // ������ ������ ������
	
	pinumber = &inumber; //&�ּҺ�ȯ�� �����ͺ����� ������ &(�ּҰ�)���� �޾ƾ���

	printf_s("inumber  : %d\n", inumber);
	printf_s("*pinumber  : %d\n", *pinumber);
	printf_s("pinumber  : %d\n", pinumber);
	printf_s("&inumber  : %d\n", &inumber);
	printf_s("&pinumber  : %d\n", &pinumber);
	

	
	


	int i = 10;
	int* j;

	j = &i; 

	printf_s("�� : %d\n", j); //i �� �ּ� ���
	printf_s("�� : %d\n", *j); // i �� ������ ���
	
	printf_s("�� : %d\n", &i); //i�� �ּ� ���
	







	int iNumber1 = 19;
	int iNumber2 = iNumber1;

	int* pPointer1 = &iNumber1;
	int* pPointer2 = &iNumber2;

	printf_s("pPointer1 : %d\n", *pPointer1);

	iNumber1 = 100; // ��������� �ؿ� ����غ��� 19����

	printf_s("pPointer2 : %d\n", *pPointer2);
	












return 0;
}