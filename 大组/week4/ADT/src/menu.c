#include"Tree.h"

int getValidInput() {
	double input;
	int validInput;

	// ��������Ƿ�ɹ�
	while (scanf("%lf%*c", &input) != 1 || input != (int)input) {
		// ���ж������Ƿ�ɹ����������Ĳ������ֻ����޷���int���ͱ�ʾ������������
		printf("������Ч����������������ѡ�\n");
		// ������뻺����
		while (getchar() != '\n');
	}

	validInput = (int)input;
	return validInput;
}

//�Ӳ˵������ĸ���
void sonMenu1(BinarySortTreePtr bst) {
	while (1) {
		printf("+----------------------------------+\n");
		printf("|            ADTʵ��               |\n");
		printf("|            1.����                |\n");
		printf("|            2.����                |\n");
		printf("|            3.ɾ��                |\n");
		printf("|            4.����                |\n");
		printf("|            5.�������(�ݹ�)      |\n");
		printf("|            6.�������(�ݹ�)      |\n");
		printf("|            7.�������(�ݹ�)      |\n");
		printf("|            8.�������(�ǵݹ�)    |\n");
		printf("|            9.�������(�ǵݹ�)    |\n");
		printf("|            10.�������(�ǵݹ�)   |\n");
		printf("|            11.�������           |\n");
		printf("|            0.�������˵�          |\n");
		printf("+----------------------------------+\n");

		printf("��ѡ��Ҫ���õĹ���>");
		// ���ú�����ȡ��Ч����
		int op = getValidInput();
		int value;

		switch (op) {
		case 1://����
			printf("������Ҫ���ҵ����֣�\n");
			value = getValidInput();
			BST_search(bst, value);
			break;
		case 2://����
			printf("������Ҫ��������֣�\n");
			value = getValidInput();
			BST_insert(bst, value);
			break;
		case 3://ɾ��
			printf("������Ҫɾ�������֣�\n");
			value = getValidInput();
			BST_delete(bst, value);
			BST_deleteReport(bst, value);
			break;
		case 4://����

			break;
		case 5://���򣨵ݹ飩
			BST_preorderR(bst,printNodeValue);
			printf("\n");
			break;
		case 6://���򣨵ݹ飩
			BST_inorderR(bst, printNodeValue);
			printf("\n");
			break;
		case 7://���򣨵ݹ飩
			BST_postorderR(bst, printNodeValue);
			printf("\n");
			break;
		case 8://���򣨷ǵݹ飩
			BST_preorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 9://���򣨷ǵݹ飩
			BST_inorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 10://���򣨷ǵݹ飩
			BST_postorderI(bst, printNodeValue);
			printf("\n");
			break;
		case 11://��α���
			BST_levelOrder(bst, printNodeValue);
			printf("\n");
			break;
		case 0:
			return;
			break;
		default:
			printf("������������������");
			break;
		}
	}
}

