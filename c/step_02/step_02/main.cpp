#include <stdio.h>



// main = ��ġ�� ������� �����Ϸ��� main ���ϸ��� ã��, �׸��� main�� �����ϰ� �����Ŵ "������Ʈ ���� ���Ѱ��� ���簡��"
int main(void)
{
	//printf = print function(�Լ�) �� ����Լ��� _s�� �Ƚᵵ��
	printf_s("hello, world!!\n");

    //sizeof �ڷ����� ũ�⸦ ����Ʈ ������ ��ȯ�����ִ� ����̴�.
	//%d(����), %f(�Ǽ�), %c(����), %s(���ڿ�) �� ���� �˰������ ���̹��� "���Ĺ���" ġ��� ���� ���°� 
	printf_s("char : %d\n", sizeof(char));
	printf_s("short : %d\n", sizeof(short));
	printf_s("int : %d\n", sizeof(int));
	printf_s("float : %d\n", sizeof(float));
	printf_s("long : %d\n", sizeof(long));
	printf_s("double : %d\n", sizeof(double));

	//\n�� �ٹٲ� \t�� ����
	printf_s("*************************************\n");
	printf_s("let's study c/c++ game programming!!!\n");
	printf_s("*************************************\n");

	//������ ���� \n���� �ٹٲ� �ؼ� ���ٿ� �Է°���
	printf_s("*************************************\nlet's study c/c++ game programming!!!\n*************************************\n");
	
	
	//return 0; �� �Լ��� �����Ű�� ��ɾ�
	return 0;
}



/*****

unsigned = -����
ex) uint, ushort .. ���

*****/