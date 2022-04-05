#include <stdio.h>

int input(int _inumber);
char output(int _inumber);

int main(void)
{
	int inumber;
	printf_s("1~255 중 하나 : ");
	scanf_s("%d", &inumber);

	switch (input(inumber))
	{
	case 1:
		printf_s("숫자 1 입력\n\n");
		break;
	case 2:
		printf_s("숫자 2 입력\n\n");
		break;
	case 3:
		printf_s("숫자 3 입력\n\n");
		break;
	default:
		printf_s("%c\n", output(inumber));
	}
	return 0;
}

int input(int _inumber)
{
	return _inumber;
}

char output(int _inumber)
{
	return _inumber;
}