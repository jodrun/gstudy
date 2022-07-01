#include "mainupdate.h"



// singleton == ������ ����, ���� ��ü
// singleton ���ӻ�
// 1, ������(���������ǹ�)
// 2, ��𿡼��� ȣ�� ����

// static �� �����Ϳ���
// �����Ϳ����� ���� �ö�(���)
class singleton
{
private:
	static singleton* instance;
public:
	static int number;                   // ����ƽ�� �Ѱ� 100������ �Ѱ�  ex) single1, single2. number �� �Ѵ� �Ȱ���
	int num;
	static singleton* getinstance()
	{
		if (instance == nullptr)
			instance = new singleton;
		return instance;
	}
};

singleton* singleton::instance = nullptr; //  ����ƽ�� nullptr �̷��� �� 





int main(void)
{
	// ����Ŭ���� ����
	mainupdate main;
	// �ʱ�ȭ
	main.start();



	//singleton
	//���� = l����, ��� = ����
	singleton single1, single2;

	single1.num = 10;
	single1.number = 100;

	single2.num = 20;



	// DWORD;        // unsigned long
	// ULONGLONG;    // unsigned int64
	 
	// DWORD time = GetTickCount()     // max �ð� = 49��, ��ǻ��(����)�� �����ð�
	// ULONGLONG time = GetTickCount64 // max �ð� = 500��, ��ǻ��(����)�� �����ð�

	ULONGLONG time = GetTickCount64();
	ULONGLONG timer = GetTickCount64();

	while (true)
	{
		if (time + 30 <= GetTickCount64())
		{
			time = GetTickCount64();

			system("cls");

			/*
			// �������
			main.update();

			// �׸���
			main.render();
			*/
			main.render();
			if (timer + 1000 <= GetTickCount64())
			{
				timer = GetTickCount64();
				main.update();
			}
			
		}
	}



	return 0;
}