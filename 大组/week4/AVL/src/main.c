#include"AVL.h"

int main() {
	AVLTREE* root = NULL;

    // ����һЩ��ʼ����
    root = insertPoint(5, root);
    root = insertPoint(3, root);
    root = insertPoint(7, root);
    root = insertPoint(1, root);
    root = insertPoint(9, root);

    system("cls");

	menu(root);

	destroy(root);//ʹ�ú�����
}