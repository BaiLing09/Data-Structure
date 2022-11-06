#include "Tree.h"

void BiTree::CreateBiTree(BiNode *&T) {
    char ch;
    cin >> ch;

    if (ch == '#') T = nullptr; //结束递归
    else {
        T = new BiNode;
        T->data = ch;
        this->CreateBiTree(T->left);
        this->CreateBiTree(T->right);
    }
}

void BiTree::InOrderTraverse(BiNode *T) {
    if (T) {
        this->InOrderTraverse(T->left);
        cout << T->data << "  ";
        this->InOrderTraverse(T->right);
    }
}

BiTree::BiTree() {
    this->root = nullptr;
}

BiTree::~BiTree() {

}

void BiTree::InitStack(LinkStack &S) {
    S = nullptr;
}

bool BiTree::StackEmpty(LinkStack S) {
    if (!S) return true;
    return false;
}

void BiTree::Push(LinkStack &S, BiNode *e) {
    StackNode *p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
}

void BiTree::Pop(LinkStack &s, BiNode *&e) {
    if (s != nullptr) {
        e = s->data;
        StackNode *p = s;
        s = s->next;
        delete p;
    }
}

void BiTree::InOrderTraverse1(BiNode *T) {
    LinkStack S;
    BiNode *p;
    auto *q = new BiNode;
    InitStack(S);
    p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            this->Push(S, p);
            p = p->left;
        } else {
            this->Pop(S, q);
            cout << q->data << "  ";
            p = q->right;
        }

    }
}
