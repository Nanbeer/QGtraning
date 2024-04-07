#include"Tree.h"

int getValidInput() {
	double input;
	int validInput;

	// 检查输入是否成功
	while (scanf("%lf%*c", &input) != 1 || input != (int)input) {
		// 先判断输入是否成功，如果输入的不是数字或者无法用int类型表示，则重新输入
		printf("输入无效，请重新输入整数选项：\n");
		// 清除输入缓冲区
		while (getchar() != '\n');
	}

	validInput = (int)input;
	return validInput;
}

//子菜单（有四个）
void sonMenu1(BinarySortTreePtr bst) {
	while (1) {
		printf("+----------------------------------+\n");
		printf("|            ADT实现               |\n");
		printf("|            1.查找                |\n");
		printf("|            2.插入                |\n");
		printf("|            3.删除                |\n");
		printf("|            4.销毁                |\n");
		printf("|            5.先序遍历(递归)      |\n");
		printf("|            6.中序遍历(递归)      |\n");
		printf("|            7.后序遍历(递归)      |\n");
		printf("|            8.先序遍历(非递归)    |\n");
		printf("|            9.中序遍历(非递归)    |\n");
		printf("|            10.后序遍历(非递归)   |\n");
		printf("|            11.层序遍历           |\n");
		printf("|            0.返回主菜单          |\n");
		printf("+----------------------------------+\n");

		printf("请选择要调用的功能>");
		// 调用函数获取有效输入
		int op = getValidInput();
		int value;

		switch (op) {
		case 1://查找
			printf("请输入要查找的数字：\n");
			value = getValidInput();
			BST_search(bst, value);
			break;
		case 2://插入
			printf("请输入要插入的数字：\n");
			value = getValidInput();
			BST_insert(bst, value);
			break;
		case 3://删除
			printf("请输入要删除的数字：\n");
			value = getValidInput();
			BST_delete(bst, value);
			BST_deleteReport(bst, value);
			break;
		case 4://销毁

			break;
		case 5://先序（递归）
			BST_preorderR(bst,printNodeValue);
			printf("\n");
			break;
		case 6://中序（递归）
			BST_inorderR(bst, printNodeValue);
			printf("\n");
			break;
		case 7://后序（递归）
			BST_postorderR(bst, printNodeValue);
			printf("\n");
			break;
		case 8://先序（非递归）
			BST_preorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 9://中序（非递归）
			BST_inorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 10://后序（非递归）
			BST_postorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 11://层次遍历
			BST_levelOrder(bst, printNodeValue);
			printf("\n");
			break;
		case 0:
			return;
			break;
		default:
			printf("输入有误，请重新输入");
			break;
		}
	}
}

