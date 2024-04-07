#pragma once
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef struct AVLTREE {
	int data;
	int height;
	struct AVLTREE* leftChlid;
	struct AVLTREE* rightChild;
}AVLTREE;

typedef unsigned char boolean;
#define TRUE  1  
#define FALSE 0  

static int i = 1;

void showTreeByLeft(AVLTREE* head);
void showTreeByMid(AVLTREE* head);
void showTreeByRight(AVLTREE* head);
AVLTREE* left_Left_Rotation(AVLTREE* root);
AVLTREE* right_Right_Rotation(AVLTREE* root);
AVLTREE* left_Right_Rotation(AVLTREE* root);
AVLTREE* right_Left_Rotation(AVLTREE* root);
AVLTREE* insertPoint(int data, AVLTREE* root);
AVLTREE* deletePoint(int data, AVLTREE* root);
int getHeight(AVLTREE* root);
int Max(int data1, int data2);
AVLTREE* getMaxNum(AVLTREE* root);
AVLTREE* getMinNum(AVLTREE* root);
void destroy(AVLTREE* root);
