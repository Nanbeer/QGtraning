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

string infix(const string& infix) {//����׺���ʽת��Ϊ��׺���ʽ
	string pos;//�����׺���ʽ
	Stack operStack;


	for (char c : infix) {//������׺���ʽ
		if (isdigit(c)) {//�ж��ǲ���0-9������  ʹ��isdigit����
			pos += c;
		}
		else if (c == '(') {//�жϷ��ţ���:���ŵ����ȼ���� 
			operStack.push(c);//��ջ
		}
		else if (c == ')') {
			while (!operStack.isEmpty() && operStack.peek() != '(') {//��ջ��Ϊ����ջ��Ԫ�ز���'('ʱ
				pos += operStack.pop();//�������еĳ�ջ
			}
			operStack.pop(); //��'('��ջ
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!operStack.isEmpty() && precedence(operStack.peek()) >= precedence(c)) {//�Ƚ�ջ��Ԫ�غ͵�ǰ�����������ȼ�
				pos += operStack.pop();
			}
			operStack.push(c);
		}
		else {
			cout << "������������������" << endl;
			return "";
		}
	}
	


	while (!operStack.isEmpty()) {//��ղ�����ջ������ջ��ʣ��Ĳ���������ȷ��˳��׷�ӵ���׺���ʽ�ַ���postfix��
		pos += operStack.pop();
	}



	return pos;//���غ�׺���ʽ


}

int evaluate(const string& pos) {//ʹ�ú�׺���ʽ��������
	Stack operStack;

	for (char c : pos) {
		if (isdigit(c)) {
			operStack.push(c - '0');//��0-9���ַ�ת��Ϊint
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			int oper2 = operStack.pop();//�����������Ԫ�س�ջ
			int oper1 = operStack.pop();
			int result;
			switch (c) {
			case '+':
				result = oper1 + oper2;
				break;
			case '-':
				result = oper1 - oper2;
				break;
			case '*':
				result = oper1 * oper2;
				break;
			case '/':
				result = oper1 / oper2;
				break;
			}
			operStack.push(result);//ÿһ�μ�������ջ
		}
		else {
			cout << "������������������" << endl;
			return 0;
		}
	}



	return operStack.pop();//�����ջ


}

int main() {
	string infixExpression;//��������
	char choice;

	do {
		cout << "��������׺���ʽ������ 3+4*2��: ";
		cin >> infixExpression;

		string postfixExpression = infix(infixExpression);

		if (!postfixExpression.empty()) {
			cout << "��׺���ʽΪ: " << postfixExpression << endl;

			int result = evaluate(postfixExpression);
			cout << "������Ϊ: " << result << endl;
		}

		do {
			cout << "�Ƿ�������㣿(y/n): ";
			cin >> choice;
		} while (choice != 'y' && choice != 'n');

	} while (choice == 'y');

	return 0;
}