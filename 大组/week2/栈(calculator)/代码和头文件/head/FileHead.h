#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node {//����
	char data;
	Node* next;
	Node(char c) : data(c), next(nullptr) {}
};

class Stack {//ջ


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


	void push(char c) {//��ջ
		Node* newNode = new Node(c);
		newNode->next = top;
		top = newNode;
	}

	char pop() {//��ջ
		if (isEmpty()) {
			return '\0'; // ����ջ�еĿ��ַ�
		}
		char c = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		return c;
	}



	char peek() {//������ȡջ��Ԫ��
		if (isEmpty()) {
			return '\0'; // ����ջ�еĿ��ַ�
		}
		return top->data;//����ջ��Ԫ��
	}

	bool isEmpty() {//�ж�ջ���Ƿ�Ϊ��
		return top == nullptr;
	}

};
