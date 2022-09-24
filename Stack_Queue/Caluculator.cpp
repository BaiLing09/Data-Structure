#include "Caluculator.h"

Calculator::Calculator()
{}

Calculator::Calculator(char *s)
{
    this->size = strlen(s);
    this->infix = new char[this->size + 1];   //创建中缀表达式数组
    this->postfix = new char[2 * this->size]; //创建后缀表达式数组
    std::strcpy(this->infix, s);              //将中缀表达式写入中缀表达式数组
}

Calculator::~Calculator()
{
    delete[] this->infix;
    delete[] this->postfix;
}

double Calculator::spellNum(char *fix, int &i)
{
    double num1 = 0, num2 = 0, num;
    int j = 0;
    while (fix[i] >= '0' && fix[i] < '9') //处理小数点前的部分
    {
        num1 = num1 * 10 + fix[i++] - '0';
    }
    if (fix[i] == '.')
    {
        i++;
        while (fix[i] >= '0' && fix[i] <= '9')
        {
            num2 += (fix[i++] - '0') * 1.0 / pow(10.0, ++j);
        }
    }
    return num = num1 + num2;
}

int Calculator::priorInStack(char item)
{
    int in;
    switch (item)
    {
    case '=':
        in = 0;
        break;
    case '(':
        in = 1;
        break;
    case '*':
        in = 5;
        break;
    case '/':
        in = 5;
        break;
    case '+':
        in = 3;
        break;
    case '-':
        in = 3;
        break;
    case ')':
        in = 6;
        break;
    default:
        break;
    }
    return in;
}

int Calculator::priorOutStack(char ch)
{
    int out;
    switch (ch)
    {
    case '=':
        out = 0;
        break;
    case '(':
        out = 6;
        break;
    case '*':
        out = 4;
        break;
    case '/':
        out = 4;
        break;
    case '+':
        out = 2;
        break;
    case '-':
        out = 2;
        break;
    case ')':
        out = 1;
        break;
    default:
        throw wrongExpression();
        break;
    }
    return out;
}

int Calculator::precede(char item, char ch)
{
    if (this->priorInStack(item) < this->priorOutStack(ch))
        return -1;
    else if (this->priorInStack(item) == this->priorOutStack(ch))
        return 0;
    else
        return 1;
}

double Calculator::operate(double a, char theta, double b)
{
    double result;
    switch (theta)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (fabs(b) < 1e-6)
            throw divideByZero();
        else
        {
            result = a / b;
            break;
        }
    default:
        break;
    }
    return result;
}

double Calculator::caluculateInfix()
{
    optr.clear();
    opnd.clear();
    int i = 0;
    char item, theta;
    double num, a, b;
    optr.push('='); //将‘=’放在栈底，保证其在级别最低
    while (!optr.empty())
    {
        if ((this->infix[i] >= '0' && this->infix[i] <= '9') || this->infix[i] == '.')
        {
            num = this->spellNum(this->infix, i);
            this->opnd.push(num); //将数字字符如栈
        }
        else
        {
            item = this->optr.getTop();
            switch (this->precede(item, this->infix[i]))
            {
            case -1:
                this->optr.push(this->infix[i]);
                i++;
                break;
            case 0:
                item = this->optr.pop();
                if (item != '=')
                    i++;
                break;
            case 1:
                theta = this->optr.pop();
                b = this->opnd.pop();
                a = this->opnd.pop();
                this->opnd.push(this->operate(a, theta, b));
                break;
            default:
                break;
            }
        }
    }
    num = this->opnd.pop();
    if (!this->opnd.empty())
        throw wrongExpression();

    return num;
}

void Calculator::printInfix()
{
    int i = 0;
    while (this->infix[i] != '\0')
    {
        std::cout << this->infix[i++];
    }
    std::cout << std::endl;
}

void Calculator::infixToPostfix()
{
    int i = 0, j = 0;
    char item;
    this->optr.clear();
    this->optr.push('=');

    while (!this->optr.empty())
    {
        if ((this->infix[i] >= '0' && this->infix[i] <= '9') || this->infix[i] == '.')
        {
            this->postfix[j++] = this->infix[i++];
        }
        else
        {
            this->postfix[j++] = ' ';
            item = this->optr.getTop();
            switch (this->precede(item, this->infix[i]))
            {
            case -1:
                this->optr.push(this->infix[i]);
                i++;
                break;
            case 0:
                item = this->optr.pop();
                if (item != '=')
                    i++;
                break;
            case 1:
                item = this->optr.pop();
                this->postfix[j++] = item;
                break;
            default:
                break;
            }
        }
    }
    this->postfix[j] = '\0';
}

double Calculator::caluculatePostfix()
{
    this->opnd.clear();
    int i = 0;
    double num, a, b;
    while (this->postfix[i] != '\0')
    {
        if ((this->postfix[i] >= '\0' && this->postfix[i] <= '9') || this->postfix[i] == '.')
        {
            num = spellNum(this->postfix, i);
            this->opnd.push(num);
        }
        else if (this->postfix[i] == ' ')
        {
            i++;
        }
        else
        {
            b = this->opnd.pop();
            a = this->opnd.pop();
            if (this->postfix[i] == '+')
                num = a + b;
            if (this->postfix[i] == '-')
                num = a - b;
            if (this->postfix[i] == '*')
                num = a * b;
            if (this->postfix[i] == '/')
            {
                if (fabs(b) <= 1e-6)
                    throw divideByZero();
                else
                {
                    num = a / b;
                }
            }
            this->opnd.push(num);
            i++;
        }
    }

    num = this->opnd.pop();
    if (!this->opnd.empty())
        throw wrongExpression();
    return num;
}

void Calculator::printPostfix()
{
    int i = 0;
    while (this->postfix[i] != '\0')
    {
        std::cout << this->postfix[i++];
    }
    std::cout << std::endl;
    ;
}