#include <stdio.h>


int main(void)
{
	/*
	 
	//true 는 0이 아닌값이면 포함 즉 "0이냐 아니냐" 1,2,3 등등 다 true 이고 0이면 false
	int i = 0;

	printf_s("1, 기  사\n");
	printf_s("2, 궁  수\n");
	printf_s("입력 : ");
	scanf_s("%d", &i);


	if (i == 1)
	{
		printf_s("기사를 선택 하였습니다.\n");
	}
	else
	{
		printf_s("궁수를 선택 하였습니다.\n");
	}

	*/

	/*
	//else if 로 분기 무한히 추가 가능
	int i = 0; //←는 변수라서 시작되고나서도 변경가능

	printf_s("1, 기  사\n");
	printf_s("2, 궁  수\n");
	printf_s("3, 마법사\n");
	printf_s("입력 : ");
	scanf_s("%d", &i);


	if (i == 1)
	{
		printf_s("기사를 선택 하였습니다.\n");
	}
	else if (i == 2)
	{
		printf_s("궁수를 선택 하였습니다.\n");
	}
	else if (i == 3)
	{
		printf_s("마법사를 선택 하였습니다.\n");
	}
	else
	{
		printf_s("잘못 선택 하였습니다.\n");
	}

	*/

	/*
	float bmi = 0.0;

	printf_s("입력 : ");
	scanf_s("%f", &bmi);

	if (bmi >= 30.0)
	{
		printf_s("고도비만 입니다.\n");
	}
	else if (bmi >= 25.0)
	{
		printf_s("비만 입니다.\n");
	}
	else if (bmi >= 23.0)
	{
		printf_s("과체중 입니다.\n");
	}
	else if (bmi >= 18.5)
	{
		printf_s("표준 입니다.\n");
	}
	else
	{
		printf_s("체중미달 입니다.\n");
	}

	*/

	int iHeight;
	int iWeight;
	float fHeight;
	float fBmi;

	printf_s("키 (cm) : ");
	scanf_s("%d", &iHeight);
	printf_s("몸무게 (kg) : ");
	scanf_s("%d", &iWeight);

	fHeight = iHeight / 100.0f;
	fBmi = iWeight / (fHeight * fHeight);

	printf_s("비만지수 : %.1f", fBmi);

	if (fBmi >= 30)
	{
		printf_s("고도비만\n");
	}
	else if (fBmi >= 25)
	{
		printf_s("비만\n");
	}
	else if (fBmi >= 23)
	{
		printf_s("과체중\n");
	}
	else if (fBmi >= 18.5)
	{
		printf_s("표준\n");
	}
	else
	{
		printf_s("체중 미달\n");
	}
	
	
	
	
	return 0;
}