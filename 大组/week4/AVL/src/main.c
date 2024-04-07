#include"AVL.h"

int main() {
	AVLTREE* root = NULL;

    // 插入一些初始数据
    root = insertPoint(5, root);
    root = insertPoint(3, root);
    root = insertPoint(7, root);
    root = insertPoint(1, root);
    root = insertPoint(9, root);

    system("cls");

	menu(root);

	destroy(root);//使用后销毁
}