/*
#include "scanner.h"

int main()
{
	Token token;
	FILE *fp;
	InitScanner("test_scanner.txt");
	printf("�Ǻ�����    �ַ���     ����ֵ     ����ָ��\n");
	printf("------------------------------------------\n");
	while (1)
	{
		token = GetToken();//��üǺ�
		if (token.type != NONTOKEN)//��ӡ�Ǻ�����
			printf("%4d,%12s,%12f,%12x\n", token.type, token.lexeme, token.value, token.FuncPtr);
		else break;
	}
	printf("------------------------------------------\n");
	CloseScanner();
}
*/