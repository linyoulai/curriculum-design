#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
    bool isEmpty() {
        return top == nullptr;
    }

    // ½øÕ»
    void push(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        std::cout << value << " pushed into stack." << std::endl;
    }

    // ³öÕ»
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << std::endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout << temp->data << " popped from stack." << std::endl;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); // ÊÔÍ¼´Ó¿ÕÕ»ÖÐ³öÕ»

    return 0;
}
