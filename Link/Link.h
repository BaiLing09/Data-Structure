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

    /**
     * @param i 插入位置
     * @param data 插入的书的编号
     */
    bool listInsert(int i, int data);//数据插入

    void creatList_R(int data);//尾插法


private:
    Node *L;//头节点，地址固定不动
};