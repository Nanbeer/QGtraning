#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node {
	int number;
	struct Node* right;//��
	struct Node* left;//ǰ
}Node;

//�����ṹ�ص�
typedef struct List {
	int size;
	struct Node* firstNode;//ָ��ͷ
	struct Node* lastNode;//ָ��β
}List;

