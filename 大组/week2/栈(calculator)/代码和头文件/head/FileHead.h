#pragma once
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



	char peek() {//用来获取栈顶元素
		if (isEmpty()) {
			return '\0'; // 返回栈中的空字符
		}
		return top->data;//返回栈顶元素
	}

	bool isEmpty() {//判断栈中是否为空
		return top == nullptr;
	}

};
