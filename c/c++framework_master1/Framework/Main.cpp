#pragma once
//http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
// ** Framework v11.1
#include "MainUpdate.h"


int main(void)
{
	system("title Ȳ�簩 : �����Ա�");
	system("mode con cols=150 lines=40");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time <= GetTickCount64())
		{
			Main.Update();
			Main.Render();

			Time = GetTickCount64();
		}
	}

	return 0;
}