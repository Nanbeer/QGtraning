#include"AVL.h"

//销毁
void destroy(AVLTREE* root) {
	if (root == NULL) {
		return;
	}

	root->leftChlid = NULL;
	root->rightChild = NULL;
	root = NULL;
}

//获取最小
AVLTREE* getMinNum(AVLTREE* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->leftChlid != NULL) {
		root = root->leftChlid;
	}
	return root;
}

//获取最大
AVLTREE* getMaxNum(AVLTREE* root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->rightChild != NULL) {
		root = root->rightChild;
	}
	return root;
}

//辅助函数:取最大
int Max(int data1, int data2) {
	return ((data1 > data2) ? data1 : data2);
}

//辅助函数:获取高度
int getHeight(AVLTREE* root) {
	if (root == NULL)
		return -1;
	else
		return root->height;
}

//删除
AVLTREE* deletePoint(int data, AVLTREE* root) {
	// 根为空 或者 没有要删除的节点，直接返回NULL
	if (root == NULL || data == NULL) {
		printf("未找到数据或AVL树为空\n");
		return NULL;
	}

	// 待删除的节点在root的左子树
	if (data < root->data) {
		root->leftChlid = deletePoint(data, root->leftChlid);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节
		if (abs(getHeight(root->rightChild) - getHeight(root->leftChlid)) == 2) {
			AVLTREE* p = root->rightChild;

			if (getHeight(p->leftChlid) > getHeight(p->rightChild)) {
				root = right_Left_Rotation(root);
			}
			else {
				root = right_Right_Rotation(root);
			}
		}
		// 待删除的节点在root的右子树
	}
	else if (data > root->data) {
		root->rightChild = deletePoint(data, root->rightChild);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节
		if (abs(getHeight(root->leftChlid) - getHeight(root->rightChild)) == 2) {
			AVLTREE* p = root->leftChlid;
			if (getHeight(p->rightChild) > getHeight(p->leftChlid)) {
				root = left_Right_Rotation(root);
			}
			else {
				root = left_Left_Rotation(root);
			}
		}
		// root就是要删除的节点
	}
	else if (data == root->data) {
		//左右孩子非空
		if (root->leftChlid && root->rightChild) {

			if (getHeight(root->leftChlid) > getHeight(root->rightChild)) {
				// 如果root的左子树比右子树高；
				// 则找出root的左子树中的最大节点
				//   将该最大节点的值赋值给root
				//   删除该最大节点
				// 这类似于用root的左子树中最大节点做root的替身
				// 删除root的左子树中最大节点之后，AVL树仍然是平衡的
				AVLTREE* max = getMaxNum(root->leftChlid);
				root->data = max->data;
				root->leftChlid = deletePoint(max->data, root->leftChlid);
			}
			else {
				// 如果root的左子树比右子树低；
				// 则找出root的左子树中的最小节点
				//   将该最小节点的值赋值给root
				//   删除该最小节点
				// 这类似于用root的右子树中最小节点做root的替身
				// 删除root的左子树中最小节点之后，AVL树仍然是平衡的
				AVLTREE* min = getMinNum(root->rightChild);
				root->data = min->data;
				root->rightChild = deletePoint(min->data, root->rightChild);
			}
		}

		else {
			//这种情况为左孩子为空右孩子不为空、或者右孩子为空左孩子不为空、左右孩子都为空时的处理方法
			//直接通过一个三目运算，即可完美解决
			AVLTREE* temp = root;

			root = root->leftChlid ? root->leftChlid : root->rightChild;

			destroy(temp);
		}
	}

	return root;
}

//插入
AVLTREE* insertPoint(int data, AVLTREE* root) {

	if (root == NULL) {
		root = (AVLTREE*)malloc(sizeof(AVLTREE));
		root->data = data;
		root->height = 0;
		root->leftChlid = root->rightChild = NULL;
		printf("插入成功\n"); // 插入新节点，输出插入成功
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
		printf("数据已存在，插入失败\n");
		return NULL;
	}

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	return root;
}

//RL型
AVLTREE* right_Left_Rotation(AVLTREE* root) {
	root->rightChild = left_Left_Rotation(root->rightChild);

	return right_Right_Rotation(root);
}

//LR型
AVLTREE* left_Right_Rotation(AVLTREE* root) {
	root->leftChlid = right_Right_Rotation(root->leftChlid);

	return left_Left_Rotation(root);
}

//RR型
AVLTREE* right_Right_Rotation(AVLTREE* root) {
	AVLTREE* newRoot = NULL;

	newRoot = root->rightChild;
	root->rightChild = newRoot->leftChlid;
	newRoot->leftChlid = root;

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	newRoot->height = max(getHeight(newRoot->rightChild), root->height) + 1;

	return newRoot;
}

//LL型
AVLTREE* left_Left_Rotation(AVLTREE* root) {
	AVLTREE* newRoot = NULL;

	newRoot = root->leftChlid;
	root->leftChlid = newRoot->rightChild;
	newRoot->rightChild = root;

	root->height = max(getHeight(root->leftChlid), getHeight(root->rightChild)) + 1;
	newRoot->height = max(getHeight(newRoot->leftChlid), root->height) + 1;

	return newRoot;
}

//中序遍历
void showTreeByMid(AVLTREE* head) {
	if (head == NULL) {
		return;
	}
	showTreeByMid(head->leftChlid);
	printf("%d ", head->data);
	showTreeByMid(head->rightChild);
}

//先序遍历
void showTreeByLeft(AVLTREE* head) {
	if (head == NULL) {
		return;
	}

	printf("%d ", head->data);
	showTreeByLeft(head->leftChlid);
	showTreeByLeft(head->rightChild);
}

//后序遍历
void showTreeByRight(AVLTREE* head) {
	if (head == NULL) {
		return;
	}

	showTreeByRight(head->rightChild);
	showTreeByRight(head->leftChlid);
	printf("%d ", head->data);
}