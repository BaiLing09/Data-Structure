#include "Link_Stack.hpp"
#include "Mistake.h"
//***********************************���ʽ��ֵ********************************//
class Calculator
{
private:
    linkStack<char> optr;   //�����ջ
    linkStack<double> opnd; //������ջ
    char *infix;            //��׺���ʽ���ַ�����
    char *postfix;          //��׺���ʽ���ַ�������
    int size;               //��׺���ʽ�ַ�������

public:
    Calculator();
    Calculator(char *s);                            //���캯��
    ~Calculator();                                  //��������
    double spellNum(char *fix, int &i);             //�������ַ�ת��Ϊdouble����ֵ
    int priorInStack(char item);                    //����ջ����������ȼ�
    int priorOutStack(char ch);                     //����ջ����������ȼ�
    int precede(char item, char ch);                //�Ƚ�ջ������������ȼ�
    double operate(double a, char theta, double b); //a��b����theta���������������
    double caluculateInfix();                       //��׺���ʽ��ֵ
    double caluculatePostfix();                     //��׺���ʽ��ֵ
    void infixToPostfix();                          //��׺���ʽת��Ϊ��׺���ʽ
    void printInfix();                              //�����׺���ʽ
    void printPostfix();                            //�����׺���ʽ
};