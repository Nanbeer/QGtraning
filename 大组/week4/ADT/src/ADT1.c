#include"Tree.h"

// ����һ���򵥴�ӡ�ڵ�ֵ�Ļص�����
void printNodeValue(NodePtr node) {
    printf("%d ", node->value);
}

// ��ʼ������������
Status BST_init(BinarySortTreePtr bst) {
        if (bst == NULL) {
            return failed;
        }
        bst->root = NULL;
        return succeed;
    }

// �����½ڵ�ĸ�����������������parentΪNULL��
NodePtr createNode(ElemType value, NodePtr parent) {
        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        if (newNode != NULL) {//��ʼ��
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = parent; // �����½ڵ�ĸ��ڵ�
        }
        return newNode;
    }

//-----------------------------------------------------

// ���뺯��
Status BST_insert(BinarySortTreePtr bst, ElemType value) {
        if (bst == NULL) {
            return failed; // ����������������
        }

        return BST_insert_recursive(&(bst->root), value, NULL);
    }

// �ڲ��ݹ���뺯��
static Status BST_insert_recursive(NodePtr* node, ElemType value, NodePtr parent) {
        if (*node == NULL) {
            *node = createNode(value, parent); // �����½ڵ�ĸ��ڵ�
            if (*node == NULL) {
                return failed; // �ڴ����ʧ��
            }
            printf("����ɹ�\n");
            return succeed;
        }

        if (value < (*node)->value) {// ����value�뵱ǰ�ڵ�ֵ�Ĺ�ϵ�������������������������ݹ�
            return BST_insert_recursive(&((*node)->left), value, *node); // ���ݵ�ǰ�ڵ���Ϊ���ڵ�
        }
        else if (value > (*node)->value) {
            return BST_insert_recursive(&((*node)->right), value, *node); // ���ݵ�ǰ�ڵ���Ϊ���ڵ�
        }
        else {
            return failed; // �����Ѿ�������ͬ��ֵ
        }
    }

//-----------------------------------------------------

// ���Һ���
Status BST_search(BinarySortTreePtr bst, ElemType value) {
        if (bst == NULL || bst->root == NULL) {
            return failed; // ���������������ڻ�Ϊ����
        }

        if (BST_search_recursive(bst->root, value)) {
            printf("���ݴ���\n");
            return succeed;
        }
        else {
            printf("���ݲ�����\n");
            return failed;
        }
    }

// �ڲ��ݹ���Һ���
static Status BST_search_recursive(NodePtr node, ElemType value) {
        if (node == NULL) {
            return false; // ��Ϊ�գ�����ʧ��
        }

        if (value == node->value) {
            return true; // �ҵ��˶�Ӧ��ֵ
        }
        else if (value < node->value) {
            return BST_search_recursive(node->left, value); // ���������в���
        }
        else {
            return BST_search_recursive(node->right, value); // ���������в���
        }
    }

//-----------------------------------------------------

//ɾ������(����һֱ�����ڴ����⣬����û�в��õݹ�)
Status BST_delete(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL || bst->root == NULL) {// �ж�BST�Ƿ�Ϊ�ջ��߸��ڵ�Ϊ�գ������򷵻�ʧ��
        return failed;
    }

    NodePtr p = bst->root, fp = NULL;// ��ʼ��ָ��ǰ�ڵ��ָ��p��ָ��p���ڵ��ָ��fp
    while (p != NULL) {// ��������������������Ҫɾ���Ľڵ�
        fp = p;// ��¼��ǰ�������Ľڵ�Ϊ�丸�ڵ�
        if (p->value > value) {// ����ǰ�ڵ�ֵ����Ҫɾ����ֵ������������������
            p = p->left;
        }
        else if (p->value < value) {  // ����ǰ�ڵ�ֵС��Ҫɾ����ֵ������������������
            p = p->right;
        }
        else { // �ҵ���ȵĽڵ㣬����ѭ��
            break;
        }
    }

    if (p == NULL) {
        return succeed; // û���ҵ�Ҫɾ���Ľڵ㣬��Ϊ�ɹ������ı����ṹ��
    }

    if (p->left && p->right) {// �ڵ�p�������ӽڵ�����
        NodePtr q = p, minNode = p->right; // ��ʼ������ָ��q���ҵ�p�������е���С�ڵ�minNode
        while (minNode->left) {// Ѱ��p�������е���С�ڵ�
            fp = minNode;
            minNode = minNode->left;
        }
        p->value = minNode->value;  // ���ҵ�����С�ڵ��ֵ�滻��ɾ���ڵ�p��ֵ

        if (fp->left == minNode) {  // ���¸��ڵ�fp����С�ڵ�minNode���ӽڵ������
            fp->left = minNode->right;
        }
        else {
            fp->right = minNode->right;
        }
        free(minNode);
    }
    else if (!p->left && !p->right) {// �ڵ�pû���ӽڵ�����
        if (p == bst->root) { // ���p�Ǹ��ڵ㣬����BST�ĸ��ڵ�ΪNULL���ͷ�p
            bst->root = NULL;
            free(p);
        }
        else if (fp->left == p) {  // ���򣬸��¸��ڵ�fp��p������ΪNULL���ͷ�p
            fp->left = NULL;
            free(p);
        }
        else if (fp->right == p) {
            fp->right = NULL;
            free(p);
        }
    }
    else if (p->left && !p->right) { // �ڵ�pֻ�����ӽڵ�����
        if (p == bst->root) {// ���p�Ǹ��ڵ㣬����BST�ĸ��ڵ�Ϊp�����ӽڵ㣬���ͷ�p
            bst->root = p->left;
            p->left = NULL;
            free(p);
        }
        else if (fp->left == p) {  // ������¸��ڵ�fp��p������Ϊp�����ӽڵ㣬���ͷ�p
            fp->left = p->left;
            p->left = NULL;
            free(p);
        }
        else if (fp->right == p) {
            fp->right = p->left;
            p->left = NULL;
            free(p);
        }
    }
    else if (!p->left && p->right) { // �ڵ�pֻ�����ӽڵ��������������һ��
        if (p == bst->root) {
            bst->root = p->right;
            p->right = NULL;
            free(p);
        }
        else if (fp->left == p) {
            fp->left = p->right;
            p->right = NULL;
            free(p);
        }
        else if (fp->right == p) {
            fp->right = p->right;
            p->right = NULL;
            free(p);
        }
    }

    return succeed; // ����Ĭ�Ϸ��سɹ�
}

//ɾ���ɹ���ʾ
void BST_deleteReport(BinarySortTreePtr bst, ElemType value) {
    Status deletionStatus = BST_delete(bst, value);

    if (deletionStatus == succeed) {
        printf("ɾ���ɹ�.\n");
    }
    else {
        printf("ɾ��ʧ�ܣ����в����ڸ���ֵ.\n");
    }
}

//-----------------------------------------------------

// �ǵݹ�ǰ������ĸ�������
void preorderI(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr stack[100]; // ����һ����СΪ100�Ľڵ�ָ��������Ϊջ�������ݴ����·���ϵĽڵ�
    int top = -1;    // ��ʼ��ջ������Ϊ-1����ʾջΪ��
    stack[++top] = root; // �����ڵ�ѹ��ջ�У���ʼ����
    while (top >= 0) {
        NodePtr node = stack[top--];  // ����ջ��Ԫ�أ�����һ����Ҫ���ʵĽڵ㣩
        visit(node);//��ӡ
        if (node->right != NULL) { // ����ǰ�ڵ�����ӽڵ�ѹ��ջ�У��Ա��������
            stack[++top] = node->right;
        }
        if (node->left != NULL) {// ����ǰ�ڵ�����ӽڵ�ѹ��ջ�У�����ջ���ص㣬���ӽڵ�������ӽڵ�֮�󱻷���
            stack[++top] = node->left;
        }
    }
}

// �ǵݹ�ǰ���������������
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    preorderI(bst->root, visit); // ���÷ǵݹ�ǰ��������������������������б��� ������������ͬ��
    return succeed;
}

//-----------------------------------------------------

// �ǵݹ���������ĸ�������
void inorderI(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr stack[100];
    int top = -1;
    NodePtr curr = root;
    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        visit(curr);
        curr = curr->right;
    }
}

// �ǵݹ������������������
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    inorderI(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// �ǵݹ��������ĸ�������
void postorderI(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr stack1[100];
    NodePtr stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        NodePtr node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }
    while (top2 >= 0) {
        visit(stack2[top2--]);
    }
}

// �ǵݹ�����������������
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    postorderI(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// ��������ĸ�������
void levelOrder(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr queue[100];
    int front = 0, rear = -1; // ��ʼ�����е�ǰ��front���ͺ�rear��ָ�룬��ʼʱ����Ϊ��
    queue[++rear] = root;// �����ڵ�������β������ʼ����
    while (front <= rear) {
        NodePtr node = queue[front++];// ��������ͷ��Ԫ�أ�����ǰ��ĵ�һ���ڵ㣩
        visit(node);//��ӡ
        if (node->left != NULL) { // ����ǰ�ڵ�����ӽڵ�������β�����Ա���һ�����ʱ����
            queue[++rear] = node->left;
        }
        if (node->right != NULL) { // ����ǰ�ڵ�����ӽڵ�������β�����Ա���һ�����ʱ����
            queue[++rear] = node->right;
        }
    }
}

// �������
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    levelOrder(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// �ݹ�ǰ�����
void preorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    visit(root); // �ȴ�ӡ���ڵ�
    preorderR(root->left, visit); // �ٵݹ����������
    preorderR(root->right, visit); // ���ݹ����������
}

// �ݹ�ǰ���������������
Status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    preorderR(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// �ݹ��������
void inorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    inorderR(root->left, visit); // �ȵݹ����������
    visit(root); // Ȼ����ʸ��ڵ�
    inorderR(root->right, visit); // ���ݹ����������
}

// �ݹ������������������
Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    inorderR(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// �ݹ�������
void postorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    postorderR(root->left, visit); // �ȵݹ����������
    postorderR(root->right, visit); // Ȼ��ݹ����������
    visit(root); // �����ʸ��ڵ�
}

// �ݹ�����������������
Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    postorderR(bst->root, visit);
    return succeed;
}



/*
// �ɹ�ɾ������succeed��ʧ�ܷ���failed
    Status BST_delete(BinarySortTreePtr* bst, ElemType value) {
        if (*bst == NULL || (*bst)->root == NULL) {
            return failed; // ���������������ڻ�Ϊ����
        }

        Status deletionStatus = BST_delete_recursive(&((*bst)->root), value);

        if (deletionStatus == succeed) {
            printf("ɾ���ɹ�\n");
        }
        else {
            printf("ɾ��ʧ��\n");
        }

        return deletionStatus;
    }

    // �ҵ���Сֵ�ڵ㼰�丸�ڵ�
    struct NodeAndParent {
        NodePtr node;
        NodePtr parent;
    };
    struct NodeAndParent find_min_with_parent(NodePtr root) {
        if (root == NULL || root->left == NULL) {
            struct NodeAndParent result = { root, NULL }; // ���û�����ӣ��򷵻ص�ǰ�ڵ�
            return result;
        }
        return find_min_with_parent(root->left);
    }

    // �ݹ�ɾ������ֵ�Ľڵ�
    static Status BST_delete_recursive(NodePtr* root, ElemType value) {
        if (*root == NULL)
            return failed; // ��ǰ�ڵ�Ϊ�գ�δ�ҵ���ɾ���ڵ�

        if (value < (*root)->value) {
            if ((*root)->left == NULL) {
                // ������Ϊ�գ�δ�ҵ���ɾ���ڵ�
                return failed;
            }
            Status deletionStatus = BST_delete_recursive(&((*root)->left), value);
            if (deletionStatus == succeed) { // ������������гɹ�ɾ���˽ڵ�
                printf("ɾ���ɹ�\n");
                return succeed;
            }
        }
        else if (value > (*root)->value) {
            if ((*root)->right == NULL) {
                // ������Ϊ�գ�δ�ҵ���ɾ���ڵ�
                return failed;
            }
            Status deletionStatus = BST_delete_recursive(&((*root)->right), value);
            if (deletionStatus == succeed) { // ������������гɹ�ɾ���˽ڵ�
                printf("ɾ���ɹ�\n");
                return succeed;
            }
        }
        else {
            // �ڵ����������ӣ���ȡ��������ĺ�̽ڵ㣨�������е���С�ڵ㣩
            struct NodeAndParent successorInfo = find_min_with_parent((*root)->right);
            NodePtr temp = successorInfo.node;
            NodePtr successorParent = successorInfo.parent;

            // ����̽ڵ�����ݸ��Ƶ���ǰ�ڵ�
            (*root)->value = temp->value;

            // ɾ����̽ڵ�
            if (temp->left == NULL) {
                // ��̽ڵ�û������
                if (successorParent->right == temp) {
                    successorParent->right = temp->right;
                }
                else {
                    // �����̽ڵ㲻���丸�ڵ�����ӽڵ㣬��Ӧ���׳�����
                    fprintf(stderr, "Internal error in BST_delete_recursive!\n");
                    exit(EXIT_FAILURE);
                }
                temp->right->parent = successorParent;
            }
            else {
                // ��̽ڵ������ӣ������Ը��ߣ��˴��򻯴���ʵ���������ת���滻�Ȳ���
                fprintf(stderr, "Deletion of nodes with two children not fully implemented!\n");
                exit(EXIT_FAILURE);
            }

            free(temp);

            return succeed; // �Ѿ��ڵ�ǰ�ڵ��ҵ��˲�ɾ����Ŀ��ڵ�
        }

        return failed; // �����������ж�û���ҵ���ɾ��Ŀ��ڵ�
    }*/