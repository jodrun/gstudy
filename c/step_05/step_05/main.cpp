#include <stdio.h>

//�������� �����
int count;
//�̷��� �����س����� ��念�������� ��밡��
//������ ���ٱ���ó�� �������� ���ſ��� �׷��� �ּ��Ѹ���



//�Ű� ������ �ش� ������ ����� ����.
float getangle(float _deg) //()��ȣ�ȿ� �Ű����� ������
{

	return 0;
}
//�Ű� ������ �� ��ȿ����� ��밡�� {}


// return �� �Լ����
int sum(int _i, int _j)
{
	return _i + _j;
}




int main(void)
{
	/*
	//switch���� if���� ���ݴ� ���� "������ ����� ����"
	int imonth;
	printf_s("ź����! �¾ �� : ");
	scanf_s("%d", &imonth);
	printf_s("����� ź������");

	switch (imonth)
	{
	case 1:
		printf_s("���� �Դϴ�");
		break;
	case 2:
		printf_s("�ڼ��� �Դϴ�");
		break;
	case 3:
		printf_s("����Ƹ��� �Դϴ�");
		break;
	case 4:
		printf_s("���̾Ƹ�� �Դϴ�");
		break;
	case 5:
		printf_s("���޶��� �Դϴ�");
		break;
	case 6:
		printf_s("���� �Դϴ�");
		break;
	case 7:
		printf_s("��� �Դϴ�");
		break;
	case 8:
		printf_s("�丮��Ʈ �Դϴ�");
		break;
	case 9:
		printf_s("�����̾� �Դϴ�");
		break;
	case 10:
		printf_s("���� �Դϴ�");
		break;
	case 11:
		printf_s("������ �Դϴ�");
		break;
    case 12:
		printf_s("��Ű�� �Դϴ�");
		break;
	default:
		printf_s("�߸��Է��ϼ̽��ϴ�");

	}
	*/

	/*
	//��������
	int val = 10;

	if (val == 10)
	{
		int val = 20; //���� �̸��� ������� �ش翵���� �ش��ϴ� ������ �켱���� �� "���⼱ if������ ���� int val = 20 �� �켱����"

		printf_s("%d\n", val);
    }
	*/

	

	sum(10, 20); //���� return ��� �� sum�Լ� ��� 30

	int result = sum(10, 20);
	printf_s("result : %d\n", result);
	
	
	return 0;
}

//�Ű������� ���������� �� ���Լ����� ������ ��밡��