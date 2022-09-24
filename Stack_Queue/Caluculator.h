#include "Link_Stack.hpp"
#include "Mistake.h"
//***********************************表达式求值********************************//
class Calculator
{
private:
    linkStack<char> optr;   //运算符栈
    linkStack<double> opnd; //操作数栈
    char *infix;            //中缀表达式的字符数组
    char *postfix;          //后缀表达式的字符串数组
    int size;               //中缀表达式字符串长度

public:
    Calculator();
    Calculator(char *s);                            //构造函数
    ~Calculator();                                  //析构函数
    double spellNum(char *fix, int &i);             //将数字字符转化为double型数值
    int priorInStack(char item);                    //计算栈内运算符优先级
    int priorOutStack(char ch);                     //计算栈外运算符优先级
    int precede(char item, char ch);                //比较栈内外运算符优先级
    double operate(double a, char theta, double b); //a与b进行theta（运算符）的运算
    double caluculateInfix();                       //中缀表达式求值
    double caluculatePostfix();                     //后缀表达式求值
    void infixToPostfix();                          //中缀表达式转换为后缀表达式
    void printInfix();                              //输出中缀表达式
    void printPostfix();                            //输出后缀表达式
};