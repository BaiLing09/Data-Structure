#include "Link.h"

LinkList::LinkList() {
    this->L = new Node;
    this->L->next = nullptr;
    this->R = this->L;//将头和尾节点指向相同地址
    this->length = 0;
    cout << "Creat Successfully" << endl;
}

LinkList::~LinkList() {
    cout << "Delete" << endl;
}

bool LinkList::listInsert(int i, int data) {
    if (i < 1 || i > length + 1) {
        cout << "without position" << endl;
        return false;
    }
    Node *pre = this->L;
    for (int j = 1; j < i; j++) {
        pre = pre->next;
    }
    Node *p = new Node;
    p->next = pre->next;
    pre->next = p;
    p->data.id = data;
    this->length++;
    return true;
}

void LinkList::creatList_R(int data) {
    Node *p = new Node;//创建一个新节点
    p->data.id = data;
    p->next = nullptr;
    this->R->next = p;//使尾节点指向新节点
    this->R = p;
    this->length++;
}

void LinkList::getElement() {
    Node *p = this->L->next;

    int i = 0;
    while (p) {
        cout << "第" << ++i << "个元素：" << p->data.id << endl;
        p = p->next;
    }
}

void LinkList::getLength() {
    cout << "当前链表长度为：" << this->length << endl;
}

bool LinkList::listDelete(int i) {
    if (i < 1 || i > this->length) {
        cout << "without position" << endl;
        return false;
    }
    Node *pre = this->L;
    for (int j = 1; j < i; j++) {
        pre = pre->next;
    }
    Node *p = pre->next;//保存待删除的节点
    pre->next = p->next;
    delete p;
    this->length--;
}

bool LinkList::listReplace(int i, int data) {
    if (i < 1 || i > this->length) {
        cout << "without position" << endl;
        return false;
    }
    Node *pre = this->L;
    for (int j = 0; j < i; j++) {
        pre = pre->next;
    }
    pre->data.id = data;
    return true;
}

Node *LinkList::listLocate(int data) {
    Node *pre = this->L->next;
    while (pre && pre->data.id != data) {
        pre = pre->next;
    }
    return pre;
}
