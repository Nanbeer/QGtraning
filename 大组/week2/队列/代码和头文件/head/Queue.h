#include <iostream>
#include <string>
using namespace std;

struct Node {
    void* data;
    Node* next;
    Node(void* d) : data(d), next(nullptr) {}  // ����ڵ�ṹ�壬����ʼ�����ݺ���һ���ڵ�ָ��

};

class Queue {

private:
    Node* front;
    Node* rear;



public:
    Queue() : front(nullptr), rear(nullptr) {}  // ��������࣬����ʼ�����׺Ͷ�βָ��Ϊ��

    ~Queue() {
        while (front != nullptr) {  // �ڶ������������У�ѭ��ɾ�������е����нڵ�
            Node* temp = front;
            front = front->next;
            delete temp;

        }
    }


    void enqueue(void* data) {  // ���������

        Node* newNode = new Node(data);  // ����һ���½ڵ�
        if (rear == nullptr) {  // �������Ϊ��
            front = newNode;  // �½ڵ�ͬʱ��Ϊ���׺Ͷ�β
            rear = newNode;

        }
        else {
            rear->next = newNode;  // �½ڵ���뵽��β�������¶�βָ��
            rear = newNode;

        }
    }

    void* dequeue() {  // �����ݳ���

        if (front == nullptr) {  // �������Ϊ��
            return nullptr;
        }

        Node* temp = front;  // ������׽ڵ�
        void* data = temp->data;  // ��ȡ���׽ڵ������
        front = front->next;  // ���¶���ָ��

        if (front == nullptr) {  // ������б��
            rear = nullptr;
        }

        delete temp;  // ɾ��ԭ���Ķ��׽ڵ�
        return data;  // ���ض�������
    }

    bool isEmpty() {
        return front == nullptr;  // �ж϶����Ƿ�Ϊ��
    }
};




