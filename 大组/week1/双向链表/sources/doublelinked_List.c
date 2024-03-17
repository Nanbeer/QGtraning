#include"doublelinked_list.h"

void showMenu() {
	printf("+---------------------------+\n");
	printf("|                           |\n");
	printf("|    1.¼����������         |\n");
	printf("|    2.չʾ¼������         |\n");
	printf("|    3.�ҵ�˫�������е�     |\n");
	printf("|    4.��ת����             |\n");
	printf("|    0.�˳�                 |\n");
	printf("|                           |\n");
	printf("+---------------------------+\n");
}

//�����ڵ�
struct Node* creatNode(int num) {
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = num;
	newNode->right = newNode->left=NULL;
	return newNode;
}

//�����ڵ�
struct List* creatList() {
	struct List* list = (List*)malloc(sizeof(List));
	list->size=0;
	list->firstNode = list->lastNode = NULL;
	return list;
}

//�������
void insertNode(List* list) {//ͷ�巨
	int data;
	printf("���������ݣ�");
	scanf("%d", &data);
	Node* newNode = creatNode(data);
	if (list->firstNode == NULL) {
		list->lastNode = newNode;
	}
	else {
		list->firstNode->left = newNode;
		newNode->right = list->firstNode;
	}
	list->firstNode = newNode;
	list->size++;
	system("pause");
	system("cls");
}

//�м�ڵ�
void getMidpoint(List* list) {
	Node* fast = list->firstNode, *slow = list->firstNode;
	while (fast != NULL && fast->right != NULL)
	{
		slow = slow->right;
		fast = fast->right->right;
	}
	printf("������м�ڵ��ǣ�%d\n", slow->number);
	system("pause");
	system("cls");
}

//��ӡ
void printList(List* list) {
	if (list->size == 0)
		printf("����Ϊ�գ��޷���ӡ\n");
	else
	{
		Node* move = list->firstNode;
		while (move!=NULL) {
			printf("%d ", move->number);
			move = move->right;
		}
		printf("\n");
	}
}

//��ת
void reverseList(List* list) {
	if (list->size <= 1) {
		return;
	}
	
	//�����������߽ڵ�
	Node* curNode = list->firstNode;
	Node* frontNode = NULL;
	Node* nextNode = NULL;

	while (curNode != NULL) {
		nextNode = curNode->right;//nextNodeָ��ָ��ǰ�ڵ����һ���ڵ㣬�Ա��ڸı�ָ�뷽����ܼ�����������
		curNode->right = frontNode;//��ת���� �ı�ָ�뷽��
		curNode->left = nextNode;//��ת��ָ��
		frontNode = curNode;//���½ڵ�
		curNode = nextNode;//�ƶ�����һ���ڵ�
	}

	// ����ͷβ�ڵ㲢����firstNode��lastNode
	Node* temp = list->firstNode;
	list->firstNode = list->lastNode;
	list->lastNode = temp;
}

int main() {
	List* list = creatList();

	int choice = 0;
	while (true) {
		showMenu();
		printf("������Ҫʵ�ֵĹ��ܣ�");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insertNode(list);
			break;
		case 2:
			printList(list);
			system("pause");
			system("cls");
			break;
		case 3:
			getMidpoint(list);
			system("pause");
			system("cls");
			break;
		case 4:
			reverseList(list);
			printList(list);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("����\n");
			return 0;
		default:
			printf("������������������");
			system("pause");
			system("cls");
			break;
		}
	}
}

/*˫��ѭ������
�����ڵ��ʱ��ͷָ���ǰָ��ָ�����һ���ڵ㣬���һ���ڵ�ĺ�ָ��ָ��ͷ�ڵ�
struct List* creatList() {
	struct List* list = (List*)malloc(sizeof(List));
	list->size=0;
	list->firstNode = list->lastNode;
	list->firstNode->left=list->firstNode;//��ʼָ���Լ�
	list->lastNode->next=list->lastNode;//��ʼָ���Լ�
	return list;
*/