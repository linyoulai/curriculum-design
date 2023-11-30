#include <iostream>
using namespace std;

//节点类
class Node {
public:
    int data;//数据域
    Node* next;//指针域

    Node(int value) : data(value), next(nullptr) {}//有参默认构造函数：初始化第一个数据，其指针指向空
};

//链表类
class LinkedList {
private:
    Node* head;//指向头节点的指针

public:
    LinkedList() : head(nullptr) {}//无参默认构造函数：初始化头指针指向空

    //插入头节点
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);//创建新的节点指针，并且初始化数据
        newNode->next = head;//将头指针赋值给新节点的指针域
        head = newNode;//头指针指向新节点
    }

    void insertAtMiddle(int value, int position) {
        Node* newNode = new Node(value);
        Node* cur = head;
        int count = 0;//计数器：寻找位置position-1，初始位置为0
        while (count != position - 1) { //当计数器不等于position-1，计数器就加1，并且cur后移
            count++;
            cur = cur->next;
        }

            //找到之后，将新节点的指针指向position的节点，将position-1的指针指向新节点
        //如果cur指向空，说明插入位置是最后一个节点的下一个，只要将cur的指针指向新节点
        //if (cur == nullptr) {
        //    cur->next = newNode;
        //}
        //else {
        //    newNode->next = cur->next;
        //    cur->next = newNode;
        //}
        newNode->next = cur->next;
        cur->next = newNode;
        
    }


    //遍历
    void display() {
        Node* cur = head;//创建一个临时指针，初始化为头指针
        while (cur != nullptr) { //当临时指针不指向空时
            cout << cur->data << " ";//输出指针指向的数据域
            cur = cur->next;//指针指向当前节点的指针域
        }
        cout << endl;//换行
    }

    //删除节点
    void deleteNode(int key) {
        Node* cur = head;//创建一个临时指针，初始化为头指针
        Node* pre = nullptr;//创建一个指针，指向上一个节点，初始化指向空

        //处理当头节点就是待删除节点的情况
        if (cur != nullptr && cur->data == key) {//如果当前指针没有指向空，即头指针没有指向空，即链表不为空，并且当前节点的数据域就是key
            head = cur->next;//直接将头指针后移
            delete cur;//释放当前指针
            return;//返回
        }

        //处理待删除节点是中间节点或尾节点的情况
        while (cur != nullptr && cur->data != key) {//还没遍历完，并且当前指针数据域不是key
            pre = cur;//指向前驱节点的指针后移
            cur = cur->next;//指向当前节点的指针后移
        }

        if (cur == nullptr) return;//找不到key，返回

        pre->next = cur->next;//前驱节点的指针指向当前节点的指针，即当前节点被删除
        delete cur;//释放当前指针
    }
};


int main() {

    LinkedList list1;
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtBeginning(3);
    list1.insertAtMiddle(123, 1);
    list1.insertAtMiddle(123, 5);

    list1.insertAtMiddle(123, 6);
    list1.display();

    return 0;
}