#include"Queue.h"

int main() {
    Queue myQueue;

    while (true) {
       string input;
       cout << "����������(����exit�˳�): ";
       getline(cin, input);//��ȡ�����input

        if (input == "exit") {  // ���������"exit"���˳�ѭ��
            break;
        }

        string* newData = new string(input);  // �����µ��ַ������ݣ����������
        myQueue.enqueue(newData);
    }

    while (!myQueue.isEmpty()) {  // ѭ��ֱ������Ϊ��
        string* dequeuedData = static_cast<string*>(myQueue.dequeue());  // �Ӷ�����ȡ������
        cout << "�����е�������: " << *dequeuedData << endl;  // ���ȡ��������
        delete dequeuedData;  // �ͷ����ݵ��ڴ�
    }

    return 0;
}