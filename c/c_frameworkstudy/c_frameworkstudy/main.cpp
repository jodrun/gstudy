#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //c++ ����� ���̺귯��

using namespace std; //iostream �� ����Ҷ� �� �������



typedef struct taginfo
{
	int inumber;

	taginfo() //������ (����ü �ȿ����� ����Ҽ� �ִ� �Լ�)
	{
		cout << "�⺻ ������" << endl;
	};

	taginfo(int _inumber) //���������
	{
		inumber = _inumber;
		cout << "���� ������" << endl;
	};

}INFO;



int main()
{
	/*
	//���
	printf_s("���� ���\n");
	
	cout << "���� ���"; // ���� ���� �ǹ� << (����Ʈ������)
	*/

	/*
	//���
	printf_s("\n�ٹٲ�\n");

	cout << "�ٹٲ�" << endl; // ���� ���� �ǹ� (�ٹٲ�)
	*/



	/*
	//�Է�
	int inumber = 0;
	printf_s("�Է� : ");
	scanf("%d", &inumber);

	printf_s("��� : %d", inumber);
	*/
	
	/*
	int inumber = 0;
	cout << "�Է�: ";                                //��� ���Ͱ��� <<
	cin >> inumber;                                  //�Է� ���Ͱ��� >>
										            
	cout << "���: " << inumber;                     //��� ���Ͱ��� <<
	*/



	
	//�����Ҵ�
	INFO* pinfo = (INFO*)malloc(sizeof(INFO));
	
	INFO* pinfo = new INFO(10);                         //���Ͱ���(�����Ҵ�)  ���⼭ �� INFO�� ������ �׷��� ����ü���� �����ڿ��� "������" �� ȣ����
	                                                    //(10)�� ��������� 
	cout << pinfo->inumber << endl;

	//�����Ҵ� �����
	free(pinfo);    

	delete pinfo;  //���Ͱ���
	









	return 0;
}



