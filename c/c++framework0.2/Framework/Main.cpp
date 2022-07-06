#pragma once
#include "MainUpdate.h"

int main(void)
{
	//연산자 오버로딩 & 방향구하기
	//v1 에서 v2를 빼면 v1로가는 방향이 나옴
	//v2 에서 v1을 빼면 v2로가는 방향이 나옴
	Vector3 V1 = Vector3(1.0f, 1.0f);
	Vector3 V2 = Vector3(10.0f, 10.0f);

	Vector3 V3 = V1 - V2;    //v1으로 가는방향 x : -9.0, y : -9.0  

	cout << "X : " << V3.x << endl;
	cout << "Y : " << V3.y << endl;
	
	

	/*
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 100 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	*/
	

	return 0;
}



// 비트연산

	// ★플러스 연산★
	//      11 
	// 0000 0010 = 2
	// 0000 0110 = 6
	//---------------
	// 0000 1000 = 8


	// ★마이너스 연산★
	// 뒤에 뺄수를 음수로 반전시키고 + 1 한다음 플러스 연산
	// 양수를 음수, 음수를 양수로 바꾸는법  =  반전시키고 + 1
	//    00000100 4
	//    00000101 5   ->   음수로 반전시킴 + 1   ->   11111011 
	//   
	//    00000100 4
	//    11111011 -5
	//   --------------
	//    11111111 -1 


	//    00000101 5
	//    00000100 4  
	// 
	//    00000101  5
	//    11111100 -4
	// -----------------
	// (1)00000001  1    ->    올라간 1이 끝까지 뒤로 밀리면 ★★★버림★★★