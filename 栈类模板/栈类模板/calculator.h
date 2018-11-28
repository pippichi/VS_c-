#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include"stack.h"


class Calculator {
	Stack<double> s;
	void enter(double num);//将num压入栈
	bool getTwoOperands(double &oper1, double &oper2);//连续将两个操作数弹出栈，存放在oper1和oper2中
	void compute(char op);//执行操作符op进行计算
public:
	void run();
	void clear();
};

#endif