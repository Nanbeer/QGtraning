#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node {//链表
	char data;
	Node* next;
	Node(char c) : data(c), next(nullptr) {}
};

class Stack {//栈
private:
	Node* top;

public:
	Stack() : top(nullptr) {}
	~Stack() {
		while (top != nullptr) {
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	void push(char c) {//入栈
		Node* newNode = new Node(c);
		newNode->next = top;
		top = newNode;
	}

	char pop() {//出栈
		if (isEmpty()) {
			return '\0'; // 返回栈中的空字符
		}
		char c = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		return c;
	}

	char peek() {
		if (isEmpty()) {
			return '\0'; // 返回栈中的空字符
		}
		return top->data;//返回栈顶元素
	}

	bool isEmpty() {//判断栈中是否为空
		return top == nullptr;
	}
};

int precedence(char op) {//四则运算优先级判断
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

string infixToPostfix(const string& infix) {//将中缀表达式转换为后缀表达式
	string postfix;//储存后缀表达式
	Stack opStack;

	for (char c : infix) {//遍历中缀表达式
		if (isdigit(c)) {//判断是不是0-9的数字
			postfix += c;
		}
		else if (c == '(') {//判断符号（）:括号的优先级最高
			opStack.push(c);
		}
		else if (c == ')') {
			while (!opStack.isEmpty() && opStack.peek() != '(') {//当栈不为空且栈顶元素不是'('时
				postfix += opStack.pop();
			}
			opStack.pop(); // 把')'出栈
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(c)) {//比较栈顶元素和当前操作符的优先级
				postfix += opStack.pop();
			}
			opStack.push(c);
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			return "";
		}
	}

	while (!opStack.isEmpty()) {//清空操作符栈，并将栈中剩余的操作符按正确的顺序追加到后缀表达式字符串postfix中
		postfix += opStack.pop();
	}

	return postfix;//返回后缀表达式
}

int evaluatePostfix(const string& postfix) {//使用后缀表达式进行运算
	Stack operandStack;

	for (char c : postfix) {
		if (isdigit(c)) {
			operandStack.push(c - '0');//将0-9的字符转换为int
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			int operand2 = operandStack.pop();//最上面的两个元素出栈
			int operand1 = operandStack.pop();
			int result;
			switch (c) {
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				result = operand1 / operand2;
				break;
			}
			operandStack.push(result);//计算结果入栈
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			return 0;
		}
	}

	return operandStack.pop();//结果出栈
}

int main() {
	string infixExpression;
	char choice;

	do {
		cout << "请输入中缀表达式（例如 3+4*2）: ";
		cin >> infixExpression;

		string postfixExpression = infixToPostfix(infixExpression);

		if (!postfixExpression.empty()) {
			cout << "后缀表达式为: " << postfixExpression << endl;

			int result = evaluatePostfix(postfixExpression);
			cout << "计算结果为: " << result << endl;
		}

		do {
			cout << "是否继续计算？(y/n): ";
			cin >> choice;
		} while (choice != 'y' && choice != 'n');

	} while (choice == 'y');

	return 0;
}