#include "Stack.h"

Stack::Stack() {
    this->top = nullptr;
}

void Stack::Push(int data) {
    auto *tmp = new StackNode;
    tmp->data = data;
    tmp->next = this->top;
    this->top = tmp;
}

int Stack::Pop() {
    if (!top) {
        cout << "Pop : empty!" << endl;
        return 0;
    }
    StackNode *tmp = this->top;
    this->top = this->top->next;
    tmp->next = nullptr;
    int e = tmp->data;
    delete tmp;
    return e;
}

int Stack::getTop() {
    if (!this->top) {
        cout << "getTop : empty!" << endl;
        return 0;
    }
    return this->top->data;
}

Stack::~Stack() {
    while (this->top) {
        StackNode *tmp = this->top;
        this->top = this->top->next;
        tmp->next = nullptr;
        cout << tmp->data << endl;
        delete tmp;
    }
}
