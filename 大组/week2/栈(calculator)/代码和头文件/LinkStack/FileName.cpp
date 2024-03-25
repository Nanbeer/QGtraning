#include"FileHead.h"

int precedence(char op) {//�����������ȼ��ж�
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

string infixToPostfix(const string& infix) {//����׺���ʽת��Ϊ��׺���ʽ
	string postfix;//�����׺���ʽ
	Stack opStack;

	for (char c : infix) {//������׺���ʽ
		if (isdigit(c)) {//�ж��ǲ���0-9������  ʹ��isdigit����
			postfix += c;
		}
		else if (c == '(') {//�жϷ��ţ���:���ŵ����ȼ���� 
			opStack.push(c);//��ջ
		}
		else if (c == ')') {
			while (!opStack.isEmpty() && opStack.peek() != '(') {//��ջ��Ϊ����ջ��Ԫ�ز���'('ʱ
				postfix += opStack.pop();//�������еĳ�ջ
			}
			opStack.pop(); //��'('��ջ
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(c)) {//�Ƚ�ջ��Ԫ�غ͵�ǰ�����������ȼ�
				postfix += opStack.pop();
			}
			opStack.push(c);
		}
		else {
			cout << "������������������" << endl;
			return "";
		}
	}
	


	while (!opStack.isEmpty()) {//��ղ�����ջ������ջ��ʣ��Ĳ���������ȷ��˳��׷�ӵ���׺���ʽ�ַ���postfix��
		postfix += opStack.pop();
	}



	return postfix;//���غ�׺���ʽ


}

int evaluatePostfix(const string& postfix) {//ʹ�ú�׺���ʽ��������
	Stack operandStack;

	for (char c : postfix) {
		if (isdigit(c)) {
			operandStack.push(c - '0');//��0-9���ַ�ת��Ϊint
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			int operand2 = operandStack.pop();//�����������Ԫ�س�ջ
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
			operandStack.push(result);//ÿһ�μ�������ջ
		}
		else {
			cout << "������������������" << endl;
			return 0;
		}
	}



	return operandStack.pop();//�����ջ


}

int main() {
	string infixExpression;//��������
	char choice;

	do {
		cout << "��������׺���ʽ������ 3+4*2��: ";
		cin >> infixExpression;

		string postfixExpression = infixToPostfix(infixExpression);

		if (!postfixExpression.empty()) {
			cout << "��׺���ʽΪ: " << postfixExpression << endl;

			int result = evaluatePostfix(postfixExpression);
			cout << "������Ϊ: " << result << endl;
		}

		do {
			cout << "�Ƿ�������㣿(y/n): ";
			cin >> choice;
		} while (choice != 'y' && choice != 'n');

	} while (choice == 'y');

	return 0;
}