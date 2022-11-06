#include <iostream>

using namespace std;

struct BiNode {
    char data;
    struct BiNode *left, *right;
};

typedef struct StackNode {
    BiNode *data;
    struct StackNode *next;
} StackNode, *LinkStack;

class BiTree {
public:
    BiTree();

    ~BiTree();

    void CreateBiTree(BiNode *&T);//先序遍历创建二叉树

    void InOrderTraverse(BiNode *T);//中序遍历二叉树

    void InitStack(LinkStack &S);//初始化栈

    bool StackEmpty(LinkStack S);

    void Push(LinkStack &S, BiNode *e);

    void Pop(LinkStack &s, BiNode *&e);

    void InOrderTraverse1(BiNode *T);

public:
    BiNode *root;

};


