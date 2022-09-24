#ifndef _LINK_H
#define _LINK_H

//顺序栈的实现
#include "Mistake.h"
#include <iostream>
#include <string>
// #include <string.h>
#include <cstring>
#include <math.h>

template <class T>
struct Node
{
    T data;        //数据
    Node<T> *next; //指向下一个节点的指针
    //连种构造函数
    Node()
    {
        this->next = NULL;
    }

    Node(const T &value, Node *p = NULL)
    {
        this->data = value;
        this->next = p;
    }
};

template <class T>
class linkStack
{
    private:
        
        Node<T> *top;//栈顶指针

    public:
        linkStack();//构造函数
        ~linkStack();//析构函数
        void clear();//清空栈
        bool empty();//判空
        int size();//获取栈中数据量
        void push(const T &value);//压栈
        T pop();//弹栈
        T getTop();//获取栈顶数据
};


template <class T>
linkStack<T>::linkStack()
{
    this->top = NULL;
}

template <class T>
linkStack<T>::~linkStack()
{
    this->clear();
}

template <class T>
void linkStack<T>::clear()
{
    Node<T> *tmp;//临时指针
    while(this->top != NULL)
    {
        tmp = this->top;
        this->top = this->top->next;
        delete tmp;
    }
}

template <class T>
bool linkStack<T>::empty()
{
    return this->top == NULL;
}

template <class T>
int linkStack<T>::size()
{
    Node<T> *tmp = this->top;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

template <class T>
void linkStack<T>::push(const T &value)
{
    Node<T> *p = new Node<T>(value, this->top);
    this->top = p;
}

template <class T>
T linkStack<T>::pop()
{
    if(this->empty())
    {
        std::cout << "该栈为空" << std::endl;
        return -1;
    }
    Node<T> *tmp = this->top;
    this->top = this->top->next;
    T value = tmp->data;
    delete tmp;
    return value;
}

template <class T>
T linkStack<T>::getTop()
{
    if (this->empty())
    {
        std::cout << "该栈为空" << std::endl;
        return -1;
    }
    return this->top->data;
}


#endif