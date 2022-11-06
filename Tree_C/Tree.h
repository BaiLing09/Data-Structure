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

struct BiThrNode
{
    char data;
    struct BiThrNode *left, *right;
    int LTag,RTag;
};

class BiTree {
public:
    BiTree();

    ~BiTree();

    void CreateBiTree(BiNode *&T);//先序遍历创建二叉树
    void CreateBiTree(BiThrNode *&T);

    void InOrderTraverse(BiNode *T);//中序遍历二叉树

    void InitStack(LinkStack &S);//初始化栈

    bool StackEmpty(LinkStack S);

    void Push(LinkStack &S, BiNode *e);

    void Pop(LinkStack &s, BiNode *&e);

    void InOrderTraverse1(BiNode *T);

    int Depth(BiNode *T);//计算树的深度

    int NodeCount(BiNode *T);//计算节点个数

    void InThreading(BiThrNode *p);

    void InorderThreading(BiThrNode *&Thrt,BiThrNode *T);



public:
    BiNode *root;
    BiThrNode *root_Thr;
    BiThrNode *pre = new BiThrNode;

};


