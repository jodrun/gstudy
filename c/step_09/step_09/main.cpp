#define _CRT_SECURE_NO_WARNINGS //������ ���
#include <stdio.h>
#include <string> //strcpy ���� ���ڿ� �Լ� ����Ҷ� �ʿ�

//#include <string> ���ڿ� �߰�
//#define _CRT_SECURE_NO_WARNINGS ���ڿ� ����Ҷ� �������� ������ �̰��Է�




//typedef �� �������� �ִ��ǹ�
//struct �� �������� ���� �ǹ� ��������
typedef struct taginfo
{
	char name[7];
	int number;

	int ikor;
	int ieng;
	int imath;
	
}INFO;

/*
struct taginfo
{
	int ikor;
	int ieng;
	int imath;
};
*/



int main (void)
{

	/*
	// ** 10���� �л��� �ְ�, ������ �л��� ����, ����, ���� ������ �ִ�.
	// ** ������ ������ �ʱ�ȭ �ؼ� ����غ���.

	int iKor[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int iEnd[10] = { 70, 50, 100, 25, 30, 40, 60, 80, 20, 90};
	int iMath[10] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

	for (int i = 0; i < 10; ++i)
	{
		printf_s("%d %d %d\n", iKor[i], iEnd[i], iMath[i]);
	}
	*/
	


	/*
	taginfo studenta;
	taginfo studentb;

	printf_s("studenta : \n");
	printf_s("�������� : ");
	scanf_s("%d", &studenta.ikor);
	printf_s("�������� : ");
	scanf_s("%d", &studenta.ieng);
	printf_s("�������� : ");
	scanf_s("%d", &studenta.imath);
	printf_s("�� : %d, �� : %d, �� : %d\n", studenta.ikor, studenta.ieng, studenta.imath);

	printf_s("studentb: \n");
	printf_s("�������� : ");
	scanf_s("%d", &studentb.ikor);
	printf_s("�������� : ");
	scanf_s("%d", &studentb.ieng);
	printf_s("�������� : ");
	scanf_s("%d", &studentb.imath);
	printf_s("�� : %d, �� : %d, �� : %d\n", studentb.ikor, studentb.ieng, studentb.imath);
    */


	/*
	// ����
	INFO Info;

	// ���ڿ� ����
	strcpy(Info.Name, "ȫ�浿");

	Info.iKor = 10;
	Info.iEng = 20;
	Info.iMath = 30;

	printf_s("%s\n", Info.Name);
	printf_s("%d\n", Info.iKor);
	printf_s("%d\n", Info.iEng);
	printf_s("%d\n", Info.iMath);
	*/


	/*
	INFO info;
	int iindex = 0;

	printf_s("����� ������ ���� �Դϱ�?\n");
	printf_s("****************************\n");
	printf_s("*     1. ��        ��       *\n");
	printf_s("*     2. ��   ��   ��       *\n");
	printf_s("*     3. ��        ��       *\n");
	printf_s("****************************\n");
	scanf_s("%d", &iindex);

	switch (iindex)
	{
	case 1:
		strcpy(info.name, "����");
		break;
	case 2:
		strcpy(info.name, "������");
		break;
	case 3:
		strcpy(info.name, "����");
		break;
	}

	printf_s("%s\n", info.name);
	*/




	// ** 3���� �л� ����(�̸�, ����, ����, ����)�� ���� �Է��ϰ�,
	// ** ��� �Է��� ������ �ڵ����� �Է��� ������ ����ϴ� ���α׷��� ������.

	INFO student[3];
	
	

	printf_s("�̸� �Է� :");

	char name[128] = "";

	scanf_s("%s", name, strlen(name));
	
	printf_s("%s\n", name);



	






	return 0;

}