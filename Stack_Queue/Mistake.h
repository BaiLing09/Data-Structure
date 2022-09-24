#ifndef _MISTAKE_H
#define _MISTAKE_H

#include <exception> //异常处理类的头文件
#include <iostream>
class outOfRange:public std::exception
{
    public:
        const char* waht() const throw()
        {
            return "ERROR! OUT OF RANGE.\n";
        }
};

class badSize:public std::exception
{
    public:
        const char* what() const throw()
        {
            return "ERROR! BAD SIZE.\n";
        }
};

class divideByZero:public std::exception
{
    public:
        const char* what()const throw()
        {
            return "ERROR! DIVIDE BY ZERO.\n";
        }
};

class wrongExpression:public std::exception
{
    public:
        const char *what() const throw()
        {
            return "ERROR! BAD EXPRESSION.\n";
        }
};

#endif
