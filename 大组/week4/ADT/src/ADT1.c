#include"Tree.h"

// 定义一个简单打印节点值的回调函数
void printNodeValue(NodePtr node) {
    printf("%d ", node->value);
}

// 初始化二叉排序树
Status BST_init(BinarySortTreePtr bst) {
        if (bst == NULL) {
            return failed;
        }
        bst->root = NULL;
        return succeed;
    }

// 创建新节点的辅助函数（新增设置parent为NULL）
NodePtr createNode(ElemType value, NodePtr parent) {
        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        if (newNode != NULL) {//初始化
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = parent; // 设置新节点的父节点
        }
        return newNode;
    }

//-----------------------------------------------------

// 插入函数
Status BST_insert(BinarySortTreePtr bst, ElemType value) {
        if (bst == NULL) {
            return failed; // 二叉排序树不存在
        }

        return BST_insert_recursive(&(bst->root), value, NULL);
    }

// 内部递归插入函数
static Status BST_insert_recursive(NodePtr* node, ElemType value, NodePtr parent) {
        if (*node == NULL) {
            *node = createNode(value, parent); // 设置新节点的父节点
            if (*node == NULL) {
                return failed; // 内存分配失败
            }
            printf("插入成功\n");
            return succeed;
        }

        if (value < (*node)->value) {// 根据value与当前节点值的关系，决定向左子树还是右子树递归
            return BST_insert_recursive(&((*node)->left), value, *node); // 传递当前节点作为父节点
        }
        else if (value > (*node)->value) {
            return BST_insert_recursive(&((*node)->right), value, *node); // 传递当前节点作为父节点
        }
        else {
            return failed; // 树中已经存在相同的值
        }
    }

//-----------------------------------------------------

// 查找函数
Status BST_search(BinarySortTreePtr bst, ElemType value) {
        if (bst == NULL || bst->root == NULL) {
            return failed; // 二叉排序树不存在或为空树
        }

        if (BST_search_recursive(bst->root, value)) {
            printf("数据存在\n");
            return succeed;
        }
        else {
            printf("数据不存在\n");
            return failed;
        }
    }

// 内部递归查找函数
static Status BST_search_recursive(NodePtr node, ElemType value) {
        if (node == NULL) {
            return false; // 树为空，查找失败
        }

        if (value == node->value) {
            return true; // 找到了对应的值
        }
        else if (value < node->value) {
            return BST_search_recursive(node->left, value); // 在左子树中查找
        }
        else {
            return BST_search_recursive(node->right, value); // 在右子树中查找
        }
    }

//-----------------------------------------------------

//删除函数(这里一直出现内存问题，所以没有采用递归)
Status BST_delete(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL || bst->root == NULL) {// 判断BST是否为空或者根节点为空，若是则返回失败
        return failed;
    }

    NodePtr p = bst->root, fp = NULL;// 初始化指向当前节点的指针p和指向p父节点的指针fp
    while (p != NULL) {// 遍历二叉搜索树，查找要删除的节点
        fp = p;// 记录当前遍历到的节点为其父节点
        if (p->value > value) {// 若当前节点值大于要删除的值，向左子树继续查找
            p = p->left;
        }
        else if (p->value < value) {  // 若当前节点值小于要删除的值，向右子树继续查找
            p = p->right;
        }
        else { // 找到相等的节点，跳出循环
            break;
        }
    }

    if (p == NULL) {
        return succeed; // 没有找到要删除的节点，视为成功（不改变树结构）
    }

    if (p->left && p->right) {// 节点p有两个子节点的情况
        NodePtr q = p, minNode = p->right; // 初始化辅助指针q和找到p右子树中的最小节点minNode
        while (minNode->left) {// 寻找p右子树中的最小节点
            fp = minNode;
            minNode = minNode->left;
        }
        p->value = minNode->value;  // 用找到的最小节点的值替换待删除节点p的值

        if (fp->left == minNode) {  // 更新父节点fp对最小节点minNode右子节点的引用
            fp->left = minNode->right;
        }
        else {
            fp->right = minNode->right;
        }
        free(minNode);
    }
    else if (!p->left && !p->right) {// 节点p没有子节点的情况
        if (p == bst->root) { // 如果p是根节点，更新BST的根节点为NULL并释放p
            bst->root = NULL;
            free(p);
        }
        else if (fp->left == p) {  // 否则，更新父节点fp对p的引用为NULL并释放p
            fp->left = NULL;
            free(p);
        }
        else if (fp->right == p) {
            fp->right = NULL;
            free(p);
        }
    }
    else if (p->left && !p->right) { // 节点p只有左子节点的情况
        if (p == bst->root) {// 如果p是根节点，更新BST的根节点为p的左子节点，并释放p
            bst->root = p->left;
            p->left = NULL;
            free(p);
        }
        else if (fp->left == p) {  // 否则更新父节点fp对p的引用为p的左子节点，并释放p
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
    else if (!p->left && p->right) { // 节点p只有右子节点的情况，与上面的一致
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

    return succeed; // 函数默认返回成功
}

//删除成功提示
void BST_deleteReport(BinarySortTreePtr bst, ElemType value) {
    Status deletionStatus = BST_delete(bst, value);

    if (deletionStatus == succeed) {
        printf("删除成功.\n");
    }
    else {
        printf("删除失败，树中不存在该数值.\n");
    }
}

//-----------------------------------------------------

// 非递归前序遍历的辅助函数
void preorderI(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr stack[100]; // 定义一个大小为100的节点指针数组作为栈，用来暂存遍历路径上的节点
    int top = -1;    // 初始化栈顶索引为-1，表示栈为空
    stack[++top] = root; // 将根节点压入栈中，开始遍历
    while (top >= 0) {
        NodePtr node = stack[top--];  // 弹出栈顶元素（即下一个需要访问的节点）
        visit(node);//打印
        if (node->right != NULL) { // 将当前节点的右子节点压入栈中，以便后续遍历
            stack[++top] = node->right;
        }
        if (node->left != NULL) {// 将当前节点的左子节点压入栈中，由于栈的特点，左子节点会在右子节点之后被访问
            stack[++top] = node->left;
        }
    }
}

// 非递归前序遍历二叉排序树
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    preorderI(bst->root, visit); // 调用非递归前序遍历辅助函数，对整棵树进行遍历 下面的中序后序同理
    return succeed;
}

//-----------------------------------------------------

// 非递归中序遍历的辅助函数
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

// 非递归中序遍历二叉排序树
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    inorderI(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// 非递归后序遍历的辅助函数
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

// 非递归后序遍历二叉排序树
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    postorderI(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// 层序遍历的辅助函数
void levelOrder(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    NodePtr queue[100];
    int front = 0, rear = -1; // 初始化队列的前（front）和后（rear）指针，初始时队列为空
    queue[++rear] = root;// 将根节点加入队列尾部，开始遍历
    while (front <= rear) {
        NodePtr node = queue[front++];// 弹出队列头部元素（即当前层的第一个节点）
        visit(node);//打印
        if (node->left != NULL) { // 将当前节点的左子节点加入队列尾部，以便下一层遍历时访问
            queue[++rear] = node->left;
        }
        if (node->right != NULL) { // 将当前节点的右子节点加入队列尾部，以便下一层遍历时访问
            queue[++rear] = node->right;
        }
    }
}

// 层序遍历
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    levelOrder(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// 递归前序遍历
void preorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    visit(root); // 先打印根节点
    preorderR(root->left, visit); // 再递归遍历左子树
    preorderR(root->right, visit); // 最后递归遍历右子树
}

// 递归前序遍历二叉排序树
Status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    preorderR(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// 递归中序遍历
void inorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    inorderR(root->left, visit); // 先递归遍历左子树
    visit(root); // 然后访问根节点
    inorderR(root->right, visit); // 最后递归遍历右子树
}

// 递归中序遍历二叉排序树
Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    inorderR(bst->root, visit);
    return succeed;
}

//-----------------------------------------------------

// 递归后序遍历
void postorderR(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL) {
        return;
    }
    postorderR(root->left, visit); // 先递归遍历左子树
    postorderR(root->right, visit); // 然后递归遍历右子树
    visit(root); // 最后访问根节点
}

// 递归后序遍历二叉排序树
Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst == NULL) {
        return failed;
    }
    postorderR(bst->root, visit);
    return succeed;
}



/*
// 成功删除返回succeed，失败返回failed
    Status BST_delete(BinarySortTreePtr* bst, ElemType value) {
        if (*bst == NULL || (*bst)->root == NULL) {
            return failed; // 二叉排序树不存在或为空树
        }

        Status deletionStatus = BST_delete_recursive(&((*bst)->root), value);

        if (deletionStatus == succeed) {
            printf("删除成功\n");
        }
        else {
            printf("删除失败\n");
        }

        return deletionStatus;
    }

    // 找到最小值节点及其父节点
    struct NodeAndParent {
        NodePtr node;
        NodePtr parent;
    };
    struct NodeAndParent find_min_with_parent(NodePtr root) {
        if (root == NULL || root->left == NULL) {
            struct NodeAndParent result = { root, NULL }; // 如果没有左孩子，则返回当前节点
            return result;
        }
        return find_min_with_parent(root->left);
    }

    // 递归删除给定值的节点
    static Status BST_delete_recursive(NodePtr* root, ElemType value) {
        if (*root == NULL)
            return failed; // 当前节点为空，未找到待删除节点

        if (value < (*root)->value) {
            if ((*root)->left == NULL) {
                // 左子树为空，未找到待删除节点
                return failed;
            }
            Status deletionStatus = BST_delete_recursive(&((*root)->left), value);
            if (deletionStatus == succeed) { // 如果在左子树中成功删除了节点
                printf("删除成功\n");
                return succeed;
            }
        }
        else if (value > (*root)->value) {
            if ((*root)->right == NULL) {
                // 右子树为空，未找到待删除节点
                return failed;
            }
            Status deletionStatus = BST_delete_recursive(&((*root)->right), value);
            if (deletionStatus == succeed) { // 如果在右子树中成功删除了节点
                printf("删除成功\n");
                return succeed;
            }
        }
        else {
            // 节点有两个孩子：获取中序遍历的后继节点（右子树中的最小节点）
            struct NodeAndParent successorInfo = find_min_with_parent((*root)->right);
            NodePtr temp = successorInfo.node;
            NodePtr successorParent = successorInfo.parent;

            // 将后继节点的内容复制到当前节点
            (*root)->value = temp->value;

            // 删除后继节点
            if (temp->left == NULL) {
                // 后继节点没有左孩子
                if (successorParent->right == temp) {
                    successorParent->right = temp->right;
                }
                else {
                    // 如果后继节点不是其父节点的右子节点，则应该抛出错误
                    fprintf(stderr, "Internal error in BST_delete_recursive!\n");
                    exit(EXIT_FAILURE);
                }
                temp->right->parent = successorParent;
            }
            else {
                // 后继节点有左孩子，复杂性更高，此处简化处理，实际情况需旋转或替换等操作
                fprintf(stderr, "Deletion of nodes with two children not fully implemented!\n");
                exit(EXIT_FAILURE);
            }

            free(temp);

            return succeed; // 已经在当前节点找到了并删除了目标节点
        }

        return failed; // 在左右子树中都没有找到并删除目标节点
    }*/