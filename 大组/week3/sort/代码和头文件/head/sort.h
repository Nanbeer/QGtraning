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


void Insert_sort(int arr[], int n);//��������

void Quick_sort(int arr[], int start, int end);//����

void Merge_sort(int arr[], int n);//�鲢����

void Count_sort(int arr[], int n);//��������

void RadixCount_sort(int arr[], int n);//��������

void Bubble_sort(int arr[], int n);//ð�������Ż���

void Quick_sort2(int arr[], int start, int end);//���ţ��ǵݹ飩

void Quick_sortPro(int arr[], int start, int end);//���ţ��Ż���

int* createArray(int& size, int& inputCount);//�����������麯��

int* startRead();//��ȡ�ļ�

int calculateArrayLength(int* arr);//�������鳤��

void startWrite();//�����������

void printarr(int arr[], int n);//��ӡ����
