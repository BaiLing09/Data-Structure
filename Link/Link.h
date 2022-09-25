#include <iostream>

using namespace std;

struct Book {
    int id;//编号
};

struct Node {
    Book data;//数据域
    struct Node *next;//指针域
};

class LinkList {
public:
    LinkList();

    ~LinkList();

    void creatList_R(int data);//尾插法

    /**
     * @param i 插入位置
     * @param data 插入的书的编号
     */
    bool listInsert(int i, int data);//数据插入

    bool listDelete(int i);//删除数据

    bool listReplace(int i, int data);//修改数据

    Node *listLocate(int data);//查找相同值

    void getElement();//遍历所有元素

    void getLength();//获取链表长度




private:
    Node *L;//头节点，地址固定不动
    Node *R;//尾节点，记录当前尾节点地址
    int length;//链表当前的长度
};