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
    Stack();
    ~Stack();

private:
    struct StackNode *top;
};