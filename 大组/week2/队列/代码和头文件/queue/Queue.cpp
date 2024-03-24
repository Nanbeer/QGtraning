#include"Queue.h"

int main() {
    Queue myQueue;

    while (true) {
       string input;
       cout << "请输入数据(输入exit退出): ";
       getline(cin, input);//读取输入的input

        if (input == "exit") {  // 如果输入是"exit"，退出循环
            break;
        }

        string* newData = new string(input);  // 创建新的字符串数据，并存入队列
        myQueue.enqueue(newData);
    }

    while (!myQueue.isEmpty()) {  // 循环直到队列为空
        string* dequeuedData = static_cast<string*>(myQueue.dequeue());  // 从队列中取出数据
        cout << "队列中的数据是: " << *dequeuedData << endl;  // 输出取出的数据
        delete dequeuedData;  // 释放数据的内存
    }

    return 0;
}