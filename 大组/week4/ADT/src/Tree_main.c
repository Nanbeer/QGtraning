#include"Tree.h"

int main() {
	
	// ��������������
	BinarySortTreePtr bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (BST_init(bst) == failed) {
		printf("��ʼ������������ʧ��\n");
		return 1;
	}

	sonMenu1(bst);
	return 0;
}