#include <iostream>
#include <string>
using namespace std;

struct Node {
    void* data;
    Node* next;
    Node(void* d) : data(d), next(nullptr) {}  // 定义节点结构体，并初始化数据和下一个节点指针

};

class Queue {

private:
    Node* front;
    Node* rear;



public:
    Queue() : front(nullptr), rear(nullptr) {}  // 定义队列类，并初始化队首和队尾指针为空

    ~Queue() {
        while (front != nullptr) {  // 在队列析构函数中，循环删除队列中的所有节点
            Node* temp = front;
            front = front->next;
            delete temp;

        }
    }


    void enqueue(void* data) {  // 将数据入队

        Node* newNode = new Node(data);  // 创建一个新节点
        if (rear == nullptr) {  // 如果队列为空
            front = newNode;  // 新节点同时作为队首和队尾
            rear = newNode;

        }
        else {
            rear->next = newNode;  // 新节点加入到队尾，并更新队尾指针
            rear = newNode;

        }
    }

    void* dequeue() {  // 将数据出队

        if (front == nullptr) {  // 如果队列为空
            return nullptr;
        }

        Node* temp = front;  // 保存队首节点
        void* data = temp->data;  // 获取队首节点的数据
        front = front->next;  // 更新队首指针

        if (front == nullptr) {  // 如果队列变空
            rear = nullptr;
        }

        delete temp;  // 删除原来的队首节点
        return data;  // 返回队首数据
    }

    bool isEmpty() {
        return front == nullptr;  // 判断队列是否为空
    }
};




