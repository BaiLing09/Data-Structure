#include "Tree.h"

void change(int a) {
    a = 10;
}

void change(int *a) {
    *a = 10;
}

//void CreateBiTree(BiNode *T) {
//    T->data = 'p';
//}


int main() {
    BiTree tree;
    tree.CreateBiTree(tree.root);
    tree.InOrderTraverse1(tree.root);
//    BiNode t;
//    BiNode *a = &t;
//    BiNode &b = a;
//    a->data='a';
//    cout<<a->data<<endl;
//    CreateBiTree(a);
//    cout<<a->data<<endl;


//    BiNode p1;
//    p1.data = '1';
//    p1.left = nullptr;
//    p1.right = nullptr;
//
//    cout << p1.data << endl;
//
//    BiNode *p2 = &p1;
//    p2->data = 'a';
//    cout << p1.data << endl;


    return 0;
}