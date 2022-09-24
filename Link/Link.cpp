#include "Link.h"

LinkList::LinkList() {
    this->L = new Node;
    this->L->next = nullptr;
    cout << "Creat Successfully" << endl;
}

LinkList::~LinkList() {
    cout << "Delete" << endl;
}

bool LinkList::listInsert(int i, int data) {

}

void LinkList::creatList_R(int data) {

}
