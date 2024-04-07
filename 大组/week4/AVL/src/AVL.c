#include"AVL.h"

//����
void destroy(AVLTREE* root) {
	if (root == NULL) {
		return;
	}

	root->leftChlid = NULL;
	root->rightChild = NULL;
	root = NULL;
}

//��ȡ��С
AVLTREE* getMinNum(AVLTREE* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->leftChlid != NULL) {
		root = root->leftChlid;
	}
	return root;
}

//��ȡ���
AVLTREE* getMaxNum(AVLTREE* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->rightChild != NULL) {
		root = root->rightChild;
	}
	return root;
}

//��������:ȡ���
int Max(int data1, int data2) {
	return ((data1 > data2) ? data1 : data2);
}

//��������:��ȡ�߶�
int getHeight(AVLTREE* root) {
	if (root == NULL)
		return -1;
	else
		return root->height;
}

//ɾ��
AVLTREE* deletePoint(int data, AVLTREE* root) {
	// ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL
	if (root == NULL || data == NULL) {
		printf("δ�ҵ����ݻ�AVL��Ϊ��\n");
		return NULL;
	}

	// ��ɾ���Ľڵ���root��������
	if (data < root->data) {
		root->leftChlid = deletePoint(data, root->leftChlid);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
		if (abs(getHeight(root->rightChild) - getHeight(root->leftChlid)) == 2) {
			AVLTREE* p = root->rightChild;

			if (getHeight(p->leftChlid) > getHeight(p->rightChild)) {
				root = right_Left_Rotation(root);
			}
			else {
				root = right_Right_Rotation(root);
			}
		}
		// ��ɾ���Ľڵ���root��������
	}
	else if (data > root->data) {
		root->rightChild = deletePoint(data, root->rightChild);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
		if (abs(getHeight(root->leftChlid) - getHeight(root->rightChild)) == 2) {
			AVLTREE* p = root->leftChlid;
			if (getHeight(p->rightChild) > getHeight(p->leftChlid)) {
				root = left_Right_Rotation(root);
			}
			else {
				root = left_Left_Rotation(root);
			}
		}
		// root����Ҫɾ���Ľڵ�
	}
	else if (data == root->data) {
		//���Һ��ӷǿ�
		if (root->leftChlid && root->rightChild) {

			if (getHeight(root->leftChlid) > getHeight(root->rightChild)) {
				// ���root�����������������ߣ�
				// ���ҳ�root���������е����ڵ�
				//   �������ڵ��ֵ��ֵ��root
				//   ɾ�������ڵ�
				// ����������root�������������ڵ���root������
				// ɾ��root�������������ڵ�֮��AVL����Ȼ��ƽ���
				AVLTREE* max = getMaxNum(root->leftChlid);
				root->data = max->data;
				root->leftChlid = deletePoint(max->data, root->leftChlid);
			}
			else {
				// ���root�����������������ͣ�
				// ���ҳ�root���������е���С�ڵ�
				//   ������С�ڵ��ֵ��ֵ��root
				//   ɾ������С�ڵ�
				// ����������root������������С�ڵ���root������
				// ɾ��root������������С�ڵ�֮��AVL����Ȼ��ƽ���
				AVLTREE* min = getMinNum(root->rightChild);
				root->data = min->data;
				root->rightChild = deletePoint(min->data, root->rightChild);
			}
		}

		else {
			//�������Ϊ����Ϊ���Һ��Ӳ�Ϊ�ա������Һ���Ϊ�����Ӳ�Ϊ�ա����Һ��Ӷ�Ϊ��ʱ�Ĵ�����
			//ֱ��ͨ��һ����Ŀ���㣬�����������
			AVLTREE* temp = root;

			root = root->leftChlid ? root->leftChlid : root->rightChild;

			destroy(temp);
		}
	}

	return root;
}

//����
AVLTREE* insertPoint(int data, AVLTREE* root) {

	if (root == NULL) {
		root = (AVLTREE*)malloc(sizeof(AVLTREE));
		root->data = data;
		root->height = 0;
		root->leftChlid = root->rightChild = NULL;
		printf("����ɹ�\n"); // �����½ڵ㣬�������ɹ�
	}
	else if (data < root->data) {
		root->leftChlid = insertPoint(data, root->leftChlid);

		if (getHeight(root->leftChlid) - getHeight(root->rightChild) == 2) {
			if (data < root->leftChlid->data)
				root = left_Left_Rotation(root);
			else
				root = left_Right_Rotation(root);
		}
	}
	else if (data > root->data) {
		root->rightChild = insertPoint(data, root->rightChild);
		if (getHeight(root->rightChild) - getHeight(root->leftChlid) == 2) {
			if (data > root->rightChild->data)
				root = right_Right_Rotation(root);
			else
				root = right_Left_Rotation(root);
		}
	}
	else if (data == root->data) {
		printf("�����Ѵ��ڣ�����ʧ��\n");
		return NULL;
	}

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	return root;
}

//RL��
AVLTREE* right_Left_Rotation(AVLTREE* root) {
	root->rightChild = left_Left_Rotation(root->rightChild);

	return right_Right_Rotation(root);
}

//LR��
AVLTREE* left_Right_Rotation(AVLTREE* root) {
	root->leftChlid = right_Right_Rotation(root->leftChlid);

	return left_Left_Rotation(root);
}

//RR��
AVLTREE* right_Right_Rotation(AVLTREE* root) {
	AVLTREE* newRoot = NULL;

	newRoot = root->rightChild;
	root->rightChild = newRoot->leftChlid;
	newRoot->leftChlid = root;

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	newRoot->height = max(getHeight(newRoot->rightChild), root->height) + 1;

	return newRoot;
}

//LL��
AVLTREE* left_Left_Rotation(AVLTREE* root) {
	AVLTREE* newRoot = NULL;

	newRoot = root->leftChlid;
	root->leftChlid = newRoot->rightChild;
	newRoot->rightChild = root;

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	newRoot->height = max(getHeight(newRoot->leftChlid), root->height) + 1;

	return newRoot;
}

//�������
void showTreeByMid(AVLTREE* head) {
	if (head == NULL) {
		return;
	}
	showTreeByMid(head->leftChlid);
	printf("%d ", head->data);
	showTreeByMid(head->rightChild);
}

//�������
void showTreeByLeft(AVLTREE* head) {
	if (head == NULL) {
		return;
	}

	printf("%d ", head->data);
	showTreeByLeft(head->leftChlid);
	showTreeByLeft(head->rightChild);
}

//�������
void showTreeByRight(AVLTREE* head) {
	if (head == NULL) {
		return;
	}

	showTreeByRight(head->rightChild);
	showTreeByRight(head->leftChlid);
	printf("%d ", head->data);
}