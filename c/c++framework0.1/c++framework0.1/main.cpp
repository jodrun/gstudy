#include <iostream>
#include <windows.h>

using namespace std;


int main(void)
{
	// DWORD;        // unsigned long
	// ULONGLONG;    // unsigned int64
	 
	// DWORD time = GetTickCount()     // max �ð� = 49��, ��ǻ��(����)�� �����ð�
	// ULONGLONG time = GetTickCount64 // max �ð� = 500��, ��ǻ��(����)�� �����ð�

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 1000 <= GetTickCount64())
		{
			time = GetTickCount64();
		}
	}



	return 0;
}