#include "Mistake.h"
#include <iostream>
#include <string>

template <class T>
class seqStack
{
private:
    T *data;       //存放元素的数组
    int top;       //栈顶指针
    int maxSize;   //栈的大小
    void resize(); //扩大栈的空间

public:
    seqStack(int initSize = 100);      //构造函数，默认初始化为100个空间
    ~seqStack() { delete[] data; }     //清除栈
    void clear() { top = -1; }         //清除栈
    bool empty() { return top == -1; } //判定栈是否为空
    int size() { return top + 1; }     //获得栈的元素个数
    void push(const T &value);         //进栈
    T pop();                           //出栈
    T getTop();                        //读取栈顶元素
};

template <class T>
seqStack<T>::seqStack(int initSize)
{
    if (initSize <= 0)
    {
        throw badSize();
    }
    else
    {
        this->data = new T[initSize];
        this->maxSize = initSize;
        top = -1;
    }
}

template <class T>
void seqStack<T>::push(const T &value)
{
    if(top == this->maxSize - 1) 
    {
        this->resize();
        std::cout << "该栈已扩容" << std::endl;
    }
    this->data[++this->top] = value;//先修改栈顶指针再将新元素入栈
}

template <class T>
T seqStack<T>::pop()
{
    if(this->empty()) 
    {
        throw outOfRange();
        // return -1;
    }
    return this->data[this->top--];//先将元素出栈再下移栈顶指针
}

template <class T>
T seqStack<T>::getTop()
{
    if(empty()) throw outOfRange();
    return this->data[this->top];
}

template <class T>
void seqStack<T>::resize()
{
    T *tem = this->data;
    this->data = new T[this->maxSize + 10];
    for(int i = 0 ; i < this->maxSize ; i++)
    {
        this->data[i] = tem[i];
    }
    this->maxSize += 10;
    delete [] tem;
}