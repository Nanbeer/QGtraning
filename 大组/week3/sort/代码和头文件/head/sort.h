#pragma once
#include<iostream>
#include <string>
#include<limits>
#include <cassert>
#include<stack>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
using namespace std::chrono;

int mainMenu();

void sonMenu1();

void sonMenu2();

void startTest1();

void startTest2();


void Insert_sort(int arr[], int n);//插入排序

void Quick_sort(int arr[], int start, int end);//快排

void Merge_sort(int arr[], int n);//归并排序

void Count_sort(int arr[], int n);//计数排序

void RadixCount_sort(int arr[], int n);//基数排序

void Bubble_sort(int arr[], int n);//冒泡排序（优化）

void Quick_sort2(int arr[], int start, int end);//快排（非递归）

void Quick_sortPro(int arr[], int start, int end);//快排（优化）

int* createArray(int& size, int& inputCount);//辅助输入数组函数

int* startRead();//读取文件

int calculateArrayLength(int* arr);//计算数组长度

void startWrite();//随机生成数组

void printarr(int arr[], int n);//打印函数
