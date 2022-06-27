#include <iostream>
#include <windows.h>

using namespace std;


int main(void)
{
	// DWORD;        // unsigned long
	// ULONGLONG;    // unsigned int64
	 
	// DWORD time = GetTickCount()     // max 시간 = 49일, 컴퓨터(서버)가 켜진시간
	// ULONGLONG time = GetTickCount64 // max 시간 = 500년, 컴퓨터(서버)가 켜진시간

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