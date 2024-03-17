#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node {
	int number;
	struct Node* right;//后
	struct Node* left;//前
}Node;

//描述结构特点
typedef struct List {
	int size;
	struct Node* firstNode;//指向头
	struct Node* lastNode;//指向尾
}List;

