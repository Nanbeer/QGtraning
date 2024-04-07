#include"Tree.h"

int main() {
	
	// 创建二叉排序树
	BinarySortTreePtr bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (BST_init(bst) == failed) {
		printf("初始化二叉排序树失败\n");
		return 1;
	}

	sonMenu1(bst);
	return 0;
}