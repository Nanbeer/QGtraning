#include"doublelinked_list.h"

void showMenu() {
	printf("+---------------------------+\n");
	printf("|                           |\n");
	printf("|    1.录入链表数据         |\n");
	printf("|    2.展示录入数组         |\n");
	printf("|    3.找到双向链表中点     |\n");
	printf("|    4.反转链表             |\n");
	printf("|    0.退出                 |\n");
	printf("|                           |\n");
	printf("+---------------------------+\n");
}

//创建节点
struct Node* creatNode(int num) {
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = num;
	newNode->right = newNode->left=NULL;
	return newNode;
}

//创建节点
struct List* creatList() {
	struct List* list = (List*)malloc(sizeof(List));
	list->size=0;
	list->firstNode = list->lastNode = NULL;
	return list;
}

//添加数据
void insertNode(List* list) {//头插法
	int data;
	printf("请输入数据：");
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

//中间节点
void getMidpoint(List* list) {
	Node* fast = list->firstNode, *slow = list->firstNode;
	while (fast != NULL && fast->right != NULL)
	{
		slow = slow->right;
		fast = fast->right->right;
	}
	printf("链表的中间节点是：%d\n", slow->number);
	system("pause");
	system("cls");
}

//打印
void printList(List* list) {
	if (list->size == 0)
		printf("链表为空，无法打印\n");
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

//反转
void reverseList(List* list) {
	if (list->size <= 1) {
		return;
	}
	
	//创建三个工具节点
	Node* curNode = list->firstNode;
	Node* frontNode = NULL;
	Node* nextNode = NULL;

	while (curNode != NULL) {
		nextNode = curNode->right;//nextNode指针指向当前节点的下一个节点，以便在改变指针方向后能继续遍历链表
		curNode->right = frontNode;//反转操作 改变指针方向
		curNode->left = nextNode;//反转左指针
		frontNode = curNode;//更新节点
		curNode = nextNode;//移动到下一个节点
	}

	// 交换头尾节点并更新firstNode和lastNode
	Node* temp = list->firstNode;
	list->firstNode = list->lastNode;
	list->lastNode = temp;
}

int main() {
	List* list = creatList();

	int choice = 0;
	while (true) {
		showMenu();
		printf("请输入要实现的功能：");
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
			printf("加纳\n");
			return 0;
		default:
			printf("输入有误，请重新输入");
			system("pause");
			system("cls");
			break;
		}
	}
}

/*双向循环链表
创建节点的时候，头指针的前指针指向最后一个节点，最后一个节点的后指针指向头节点
struct List* creatList() {
	struct List* list = (List*)malloc(sizeof(List));
	list->size=0;
	list->firstNode = list->lastNode;
	list->firstNode->left=list->firstNode;//初始指向自己
	list->lastNode->next=list->lastNode;//初始指向自己
	return list;
*/