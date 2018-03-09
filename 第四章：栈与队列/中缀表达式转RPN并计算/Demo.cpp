#include <iostream>
#include <string>
#include "LinkStack.h"
using namespace std;

/************************
*栈的应用：逆波兰表达式（后缀表达式计算）
*Author:@Mer
*功能：利用栈结构-->
*	1.将用户输入的表达式转化为逆波兰表达式
*	2.计算后缀表达式的值并输出结果

注1：仅支持带括号的四则运算

注2：中缀表达式转后缀表达式方法：
1.遇到操作数：直接输出（添加到后缀表达式中）
2.栈为空时，遇到运算符，直接入栈
3.遇到左括号：将其入栈
4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
6.最终将栈中的元素依次出栈，输出。
**************************/

/********
*符号优先级表：
*0~3 :+~-~*~/
*顺序:3~3~4~4
********/
int symbolPrecedence(char k) {
	int precendence;
	switch (k)
	{
	case '+':
		precendence = 3;
		break;
	case '-':
		precendence = 3;
		break;
	case '*':
		precendence = 4;
		break;
	case '/':
		precendence = 4;
		break;
	default:
		break;
	}
	return precendence;
}

int main(void) {
	//LinkStack定义在LinkStack.h中
	LinkStack<char> mystack;
	//RPN中保存转换后的逆波兰表达式
	std::string RPN="";

	/*---------------中缀表达式转换为后缀表达式-----------------*/
	std::string expression;
	cout << "Please input a expression :";
	cin >> expression;
	char k;
	bool lbracket = false;

	for (int i = 0; i < expression.length(); i++) {
		k = expression[i];
		/*如果遇到数字则输出*/
		if (k >= '0'&&k <= '9') {
			RPN += k;
			k = expression[++i];
			while (k >= '0'&&k <= '9' || k == '.') {
				RPN += k;
				k = expression[++i];
			}
			RPN += ' ';
			i--;
		}
		/*遇到右括号则出栈直至左括号*/
		else if (k == ')') {
			int j = i;
			char kk;
			mystack.pop(&kk);
			while (kk != '(') {
				RPN+= kk;
				RPN += ' ';
				mystack.pop(&kk);
			}
			lbracket = false;
		}
		/*遇到左括号直接压栈*/
		else if (k == '(') {
			lbracket = true;
			mystack.push(k);
		}
		/*遇到运算符则按照优先级进行压栈和出栈操作*/
		else {
			//栈为空直接将符号压入栈中
			if (mystack.isEmpty()) {
				mystack.push(k);
			}
			else {
				char ktop, kk;
				mystack.getTop(&ktop);
				while (!mystack.isEmpty() && ktop != '('&&symbolPrecedence(k) <= symbolPrecedence(ktop)) {
					mystack.pop(&ktop);
					RPN += ktop;
					RPN += ' ';
					mystack.getTop(&ktop);
				}
				mystack.push(k);
			}
		}

	}
	/*全部出栈*/
	while (!mystack.isEmpty()) {
		mystack.pop(&k);
		RPN += k;
		RPN += ' ';
	}
	
	std::cout << RPN << endl;

	/*-------------计算后缀表达式--------------*/
	LinkStack<double> mystack1;

	for (int i = 0; i != RPN.length(); i++) {
		k = RPN[i];
		if (k == ' ')continue;
		/*将数字压入栈中*/
		else if (k >= '0'&&k <= '9') {
			bool dpoint=false;
			int times = 1;
			double number=k-'0';
			k = RPN[++i];
			while (k != ' ') {
				if (k == '.') dpoint = true;
				else {
					if (dpoint) {
						times *= 10;
					}
					number *= 10;
					number += k - '0';
				}
				k = RPN[++i];
			}

			number /= times;
			mystack1.push(number);
		}
		/*遇到运算符则从栈中取出数字运算  将结果压入栈中*/
		else {
			double aNum, bNum;
			mystack1.pop(&aNum);
			mystack1.pop(&bNum);
			switch (k) {
			case '+':
				mystack1.push(aNum + bNum);
				break;
			case '-':
				mystack1.push(bNum - aNum);
				break;
			case '*':
				mystack1.push(aNum * bNum);
				break;
			case '/':
				mystack1.push(bNum / aNum);
				break;
			default:
				std::cout << "ERROR!" << endl;
				system("pause");
				break;
			}
		}
	}

	/*将结果保存在result*/
	double result;
	mystack1.pop(&result);
	std::cout << "result :" << result << endl;
	
	system("pause");
	return 0;
}