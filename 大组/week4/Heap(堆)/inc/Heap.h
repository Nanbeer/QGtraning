#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义堆(完全二叉树)
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestory(HP* php);
void HeapPush(HP* php, int child);
void HeapPop(HP* php);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);   //堆  堆中元素个数  根节点的索引值
void Swap(int* child, int* parent);
void HeapPrint(HP* php);
bool HpEmpty(HP* pHp);
void HpTop(HP* pHp);
void HpSize(HP* pHp);
void menu(HP* hp);
