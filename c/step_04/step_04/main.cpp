#include <stdio.h>


int main(void)
{
	/*
	 
	//true �� 0�� �ƴѰ��̸� ���� �� "0�̳� �ƴϳ�" 1,2,3 ��� �� true �̰� 0�̸� false
	int i = 0;

	printf_s("1, ��  ��\n");
	printf_s("2, ��  ��\n");
	printf_s("�Է� : ");
	scanf_s("%d", &i);


	if (i == 1)
	{
		printf_s("��縦 ���� �Ͽ����ϴ�.\n");
	}
	else
	{
		printf_s("�ü��� ���� �Ͽ����ϴ�.\n");
	}

	*/

	/*
	//else if �� �б� ������ �߰� ����
	int i = 0; //��� ������ ���۵ǰ����� ���氡��

	printf_s("1, ��  ��\n");
	printf_s("2, ��  ��\n");
	printf_s("3, ������\n");
	printf_s("�Է� : ");
	scanf_s("%d", &i);


	if (i == 1)
	{
		printf_s("��縦 ���� �Ͽ����ϴ�.\n");
	}
	else if (i == 2)
	{
		printf_s("�ü��� ���� �Ͽ����ϴ�.\n");
	}
	else if (i == 3)
	{
		printf_s("�����縦 ���� �Ͽ����ϴ�.\n");
	}
	else
	{
		printf_s("�߸� ���� �Ͽ����ϴ�.\n");
	}

	*/

	/*
	float bmi = 0.0;

	printf_s("�Է� : ");
	scanf_s("%f", &bmi);

	if (bmi >= 30.0)
	{
		printf_s("���� �Դϴ�.\n");
	}
	else if (bmi >= 25.0)
	{
		printf_s("�� �Դϴ�.\n");
	}
	else if (bmi >= 23.0)
	{
		printf_s("��ü�� �Դϴ�.\n");
	}
	else if (bmi >= 18.5)
	{
		printf_s("ǥ�� �Դϴ�.\n");
	}
	else
	{
		printf_s("ü�߹̴� �Դϴ�.\n");
	}

	*/

	int iHeight;
	int iWeight;
	float fHeight;
	float fBmi;

	printf_s("Ű (cm) : ");
	scanf_s("%d", &iHeight);
	printf_s("������ (kg) : ");
	scanf_s("%d", &iWeight);

	fHeight = iHeight / 100.0f;
	fBmi = iWeight / (fHeight * fHeight);

	printf_s("������ : %.1f", fBmi);

	if (fBmi >= 30)
	{
		printf_s("����\n");
	}
	else if (fBmi >= 25)
	{
		printf_s("��\n");
	}
	else if (fBmi >= 23)
	{
		printf_s("��ü��\n");
	}
	else if (fBmi >= 18.5)
	{
		printf_s("ǥ��\n");
	}
	else
	{
		printf_s("ü�� �̴�\n");
	}
	
	
	
	
	return 0;
}