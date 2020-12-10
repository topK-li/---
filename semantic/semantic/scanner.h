#ifndef SCANNER_H
#define SCANNER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //ctype.h��C��׼�������е�ͷ�ļ���������һ��C�����ַ����ຯ�������ڲ����ַ��Ƿ������ض����ַ����
//����ĸ�ַ��������ַ��ȵȡ�
#include <stdarg.h>//�ú������Խ��տɱ����
#include <math.h>

enum Token_Type//�Ǻ����ö��
{
	ORIGIN/* 0 */, SCALE/* 1 */, ROT/* 2 */, IS/* 3 */, TO/* 4 */, STEP/* 5 */, DRAW/* 6 */, FOR/* 7 */, FROM/* 8 */,//������
	T/* 9 */,//����
	SEMICO/* 10 */, L_BRACKET/* 11 */, R_BRACKET/* 12 */, COMMA/* 13 */,//�ֲ����
	PLUS/* 14 */, MINUS/* 15 */, MUL/* 16 */, DIV/* 17 */, POWER/* 18 */,//�����
	FUNC/*19 */,//����
	CONST_ID/* 20 */,//����
	NONTOKEN/* 21 */,//�ռǺţ����Դ�����ļ��Ľ���
	ERRTOKEN/* 22 *///����Ǻţ���ǷǷ�����
};

typedef double(*MathFuncPtr)(double);//MathFuncPtr����һ��ָ�򷵻�doubleֵ������һ��double�βεĺ�����ָ�������

struct Token
{
	Token_Type type;//�Ǻ����
	char* lexeme;//���ԣ��ַ�����ָ��char���͵�ָ��
	double value;//���ԣ�������ֵ��double��
	double(*FuncPtr)(double);//���ԣ�����ָ�룬����һ��ָ�򷵻�doubleֵ������һ��double�βεĺ�����ָ�������
};

static Token TokenTab[] = //���ű�����
{
	{ CONST_ID,	(char*)"PI", 3.1415926,	NULL },
	{ CONST_ID,	(char*)"E",	2.71828,	NULL },
	{ T,		(char*)"T",		0.0,	NULL },
	{ FUNC,		(char*)"SIN",		0.0,	sin },
	{ FUNC,		(char*)"COS",		0.0,	cos },
	{ FUNC,		(char*)"TAN",		0.0,	tan },
	{ FUNC,		(char*)"LN",		0.0,	log },
	{ FUNC,		(char*)"EXP",		0.0,	exp },
	{ FUNC,		(char*)"SQRT",		0.0,	sqrt },
	{ ORIGIN,	(char*)"ORIGIN",	0.0,	NULL },
	{ SCALE,	(char*)"SCALE",	0.0,	NULL },
	{ ROT,		(char*)"ROT",		0.0,	NULL },
	{ IS,		(char*)"IS",		0.0,	NULL },
	{ FOR,		(char*)"FOR",		0.0,	NULL },
	{ FROM,		(char*)"FROM",		0.0,	NULL },
	{ TO,		(char*)"TO",		0.0,	NULL },
	{ STEP,		(char*)"STEP",		0.0,	NULL },
	{ DRAW,		(char*)"DRAW",		0.0,	NULL },
};

extern unsigned int LineNo;//���ټǺ�����Դ�ļ��к�
extern int InitScanner(const char*);//��ʼ���ʷ�������
extern Token GetToken(void);//��ȡ�Ǻź���
extern void CloseScanner(void);//�رմʷ�������

#endif#pragma once
#pragma once
