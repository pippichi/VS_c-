#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include"stack.h"


class Calculator {
	Stack<double> s;
	void enter(double num);//��numѹ��ջ
	bool getTwoOperands(double &oper1, double &oper2);//��������������������ջ�������oper1��oper2��
	void compute(char op);//ִ�в�����op���м���
public:
	void run();
	void clear();
};

#endif