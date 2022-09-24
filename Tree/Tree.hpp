#include <iostream>
#include <stack>
#include <queue>

/**
 * @brief 二叉树基类
 */
template <class elemType>
class binaryTree
{
public:
    virtual void clear() = 0;//清空
    virtual bool empty() const = 0;//判空
    virtual int height() const = 0;//二叉树的高度
    virtual void size() const = 0;//二叉树的结点总数
    virtual void preOrderTraverse() const = 0;//前序遍历
    virtual void inOrderTraverse() const = 0;//中序遍历
    virtual void postOrderTraverse() const = 0;//后序遍历
    virtual void levelOrderTraverse() const = 0;//层序遍历
    virtual ~binaryTree() {};
};


/**
 * @brief 二叉树链表
 */
template <class elemType>
class BinaryLinkList:public binaryTree<elemType>
{
private:
    struct Node//二叉链表结点
    {
        Node *left , *right;//指向左右孩子的指针
        elemType data;//结点的数据域
        Node(): left(NULL),right(NULL){}//无参构造函数
        Node(elemType value, Node *l = NULL, Node *r = NULL)//有参构造函数
        {
            this->data = value;
            this->left = l;
            this->right = r;
        }
        ~Node(){}
    };
    
    Node *root;//指向二叉树的根结点
    void clear(Node *t);//清空
    int size(Node *t) const;//二叉树的结点总数
    int height(Node *t) const;//二叉树的高度
    int leafNum(Node *t) const;//二叉树叶结点个数
    void perOrder(Node *t) const;//递归前序遍历
    void inOrder(Node *t) const;//递归中序遍历
    void postOrder(Node *t) const;//递归后序遍历
    void preOrderCreate(elemType flag, Node *& t);//创建二叉树

public:
    BinaryLinkList(): root(NULL){}//构造二叉树
    ~BinaryLinkList(){ this->clear(); }//析构
    bool empty() const {return root == NULL; }//判空
    void clear() { if(root) this->clear(root); root = NULL;}//清空
    int size() const {return this->size(this->root);}//求结点总数
    int height() const {return this->height(this->root);}//求二叉树高度
    int leafNum() const {return this->leafNum(this->root);}//求叶结点个数
    void preOrderTraverse() const {if(root) this->perOrder(root);}//前序遍历
    void inOrderTraverse() const {if(root) this->inOrder(root);}//中序遍历
    void postOrderTraverse() const {if(root) this->postOrder(root);}//后序遍历
    void levelOrderTraverse() const;//层次遍历
    void preOrderWithStack() const;//非递归前序遍历
    void inOrderWithStack() const;//非递归中序遍历
    void postOrderWithStack() const;//非递归后序遍历
    void levelOrderCreate(elemType flag);//利用带外部结点的层次序列创建二叉树
    void preOrderCreate(elemType flag)//利用带外部结点的前序序列创建二叉树
    {
        this->preOrderCreate(flag,root);
    }

};

/**
 * @brief 二叉树前序递归遍历
*/
template <class elemType>
void BinaryLinkList<elemType>::perOrder(Node *t) const
{
    if(t)
    {
        std::cout << t->data << "  ";//访问当前结点
        this->perOrder(t->left);//前序遍历左子树
        this->perOrder(t->right);//前序遍历右子树
    }
}

/**
 * @brief 二叉树中序递归遍历
*/
template <class elemType>
void BinaryLinkList<elemType>::inOrder(Node *t) const
{
    if(t)
    {
        this->inOrder(t->left);//中序遍历左子树
        std::cout << t->data << "  ";
        this->inOrder(t->right);//中序遍历右子树
    }
}

/**
 * @brief 二叉树后序递归遍历
*/
template <class elemType>
void BinaryLinkList<elemType>::postOrder(Node *t) const
{
    if(t)
    {
        this->postOrder(t->left);//后序遍历左子树
        this->postOrder(t->right);//后序遍历右子树
        std::cout << t->data << "  ";
    }
}

/**
 * @brief 非递归前序遍历
 */
template <class elemType>
void BinaryLinkList<elemType>::preOrderWithStack() const
{
    std::stack<Node*> s;
    Node* p = root;//工作指针
    while(!s.empty() || p)
    {
        if(p)
        {
            std::cout << p->data << "  ";
            s.push(p);
            p = p->left;//工作指针指向左子树
        }
        else//左子树访问完毕，开始访问右子树
        {
            p = s.top();//获取栈顶元素
            s.pop();//退栈
            p = p->right;
        }
    }
}

/**
 * @brief 非递归中序遍历
 */
template <class elemType>
void BinaryLinkList<elemType>::inOrderWithStack() const
{
    std::stack<Node *> s;
    Node *p = root;//工作指针
    while(!s.empty() || p)
    {
        if(p)
        {
            s.push(p);
            p = p->left;//工作指针指向左子树
        }
        else
        {
            p = s.top();
            s.pop();
            std::cout << p->data << "  ";
            p = p->right;//工作指针指向右子树
        }
        
    }
}

/**
 * @brief 非递归后序遍历
 */
template <class elemType>
void BinaryLinkList<elemType>::postOrderWithStack() const
{
    enum ChildType{Left,Right};//特征位定义
    struct StackElem
    {
        Node *pointer;
        ChildType flag;
    };
    StackElem elem;
    std::stack<StackElem> S;//工作指针
    Node *p = root;
    while(!S.empty() || p)
    {
        while (p != NULL)
        {
            elem.pointer = p;
            elem.flag = Left;
            S.push(elem);
            p = p->left;//沿左子树方向向下周游
        }
        elem = S.top();
        S.pop();
        p = elem.pointer;

        if(elem.flag == Left)//从左边返回，已经遍历完左子树
        {
            elem.flag = Right;
            S.push(elem);
            p = p->right;
        }
        else//从右边返回，已遍历完右子树
        {
            std::cout << p->data << "  ";
            p = NULL;
        }
        
    }
    
}

/**
 * @brief 广度优先遍历（层次遍历）
 */
template <class elemType>
void BinaryLinkList<elemType>::levelOrderTraverse() const
{
    std::queue<Node *> que;
    Node *p = root;
    if(p)
    que.push(p);
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        std::cout << p->data << "  ";
        if(p->left != NULL) que.push(p->left);//左孩子入队
        if(p->right != NULL) que.push(p->right);//右孩子入队
    }
    
}

/**
 * @brief 带外部结点的前序序列建立二叉树
 */
template <class elemType>
void BinaryLinkList<elemType>::preOrderCreate(elemType flag,Node *&t)//由于需要修改t指针，所以要使用引用
{
    elemType value;
    std::cin >> value;
    if(value != flag)
    {
        t = new Node(value);
        this->preOrderCreate(flag,t->left);//递归创建左子树
        this->preOrderCreate(flag,t->right);//递归创建右子树
    }
}


/**
 * @brief 求结点总数
 */
template <class elemType>
int BinaryLinkList<elemType>::size(Node *t) const
{
    if(t == NULL) return 0;
    return 1 + this->size(t->left) + this->size(t->right);
}

/**
 * @brief 求二叉树高度
 */
template <class elemType>
int BinaryLinkList<elemType>::height(Node *t) const
{
    if(t == NULL) return 0;
    else
    {
        int lh = this->height(t->left) , rh = this->height(t->right);
        return 1 + ((lh > rh) ? lh : rh);//树的高度为左右子树高度加1
    }
    
}

/**
 * @brief 求二叉树结点个数
 */
template <class elemType>
int BinaryLinkList<elemType>::leafNum(Node *t) const
{
    if(t == NULL) return 0;//空子树
    else if((t->left == NULL) && (t->right == NULL)) return 1;//叶结点
    else return this->leafNum(t->left) + this->leafNum(t->right);//求左右子树叶结点个数之和
}

/**
 * @brief 删除该结点的左右子树后再删除结点自身
 */
template <class elemType>
void BinaryLinkList<elemType>::clear(Node *t)
{
    if(t->left) this->clear(t->left);
    if(t->right) this->clear(t->right);
    delete t;
}
