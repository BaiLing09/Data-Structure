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
//    tree.CreateBiTree(tree.root);

    tree.pre->RTag=1;
    tree.pre->right= nullptr;
    tree.CreateBiTree(tree.root);
    tree.InThreading(tree.root_Thr);



    return 0;
}