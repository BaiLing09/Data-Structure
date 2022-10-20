#include<iostream>
#include<fstream>
using namespace std;

struct  StackNode
{
    int data;
    struct StackNode *next;
};

class Stack
{
public:
    Stack();//初始化栈

    void Push(int data);//入栈

    int Pop();//删除栈顶元素，并返回栈顶元素

    int getTop();//获取栈顶元素

    ~Stack();

private:
    struct StackNode *top;
};