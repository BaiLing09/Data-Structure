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

void BiTree::CreateBiTree(BiThrNode *&T){
    char ch;
    cin >> ch;

    if (ch == '#') T = nullptr; //结束递归
    else {
        T = new BiThrNode;
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

int BiTree::Depth(BiNode *T) {
    int m, n;
    if (T == nullptr) return 0;
    m = this->Depth(T->left);//计算左子树
    n = this->Depth(T->right);//计算右子树
    return (m > n) ? (m + 1) : (n + 1);

}

int BiTree::NodeCount(BiNode *T) {
    return (T == nullptr) ? 0 : (this->NodeCount(T->left) + this->NodeCount(T->right) + 1);
}

void BiTree::InThreading(BiThrNode *p) {
    if (p) {
        this->InThreading(p->left);
        if (!p->left) {
            p->LTag = 1;
            p->left = pre;
        } else {
            p->LTag = 0;
        }

        if (!pre->right) {
            pre->RTag = 1;
            pre->right = p;
        } else {
            pre->RTag = 0;
        }
        pre = p;
        this->InThreading(p->right);
    }
}

void BiTree::InorderThreading(BiThrNode *&Thrt, BiThrNode *T) {
    Thrt = new BiThrNode;
    Thrt->LTag = 0;
    Thrt->RTag = 1;
    Thrt->right = Thrt;
    if (!T) Thrt->left = Thrt;
    else {
        Thrt->left = T;
        pre = Thrt;
        this->InThreading(T);
        pre->right = Thrt;
        pre->RTag = 1;
        Thrt->right = pre;
    }
}
