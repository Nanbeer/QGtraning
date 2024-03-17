#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct List {
	int number;
	struct List* next;
}List;