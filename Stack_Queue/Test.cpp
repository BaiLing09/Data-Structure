#include "head.h"
#include "Caluculator.h"
#include "Link_Stack.hpp"
#include "Order_Stack.hpp"

void test_1()
{
    seqStack<int> stack(12);
    while (true)
    {
        int num;
        std::cin >> num;
        if (num == -1)
        {
            break;
        }
        else
        {
            stack.push(num);
        }
    }
    std::cout << "----------------------" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << stack.pop() << std::endl;
    }
}

void test_2()
{
    linkStack<int> stack;
    while(true)
    {
        int num;
        std::cin >> num;
        if(num == -1)
        {
            break;
        }
        else
        {
            stack.push(num);
        }
    }

    std::cout << stack.getTop() << std::endl;
    std::cout << "*******************" << std::endl;
    int t = stack.size();//要先保存总的数据量,否则下面的for循环里每执行一次出栈就会执行一遍stack.size()导致总数会改变
    for (int i = 0; i < t; i++)
    {
        std::cout << stack.pop() << std::endl;
    }
}


/**
 * @brief 十进制数N转换为d进制的公式
 * @brief N = (N/d) * d + N % d 
*/
void test_3()
{
    //10进制转化为16进制
    linkStack<int> stack;
    int N, e;
    std::cin >> N;//读入十进制数
    while(N != 0)
    {
        stack.push(N % 16);
        N /= 16;
    }
    while (!stack.empty())
    {
        e = stack.pop();
        if(e > 9)
        {
            std::cout << char(e - 10 + 'A');
        }
        else
        {
            std::cout << e;
        }
    }
    std::cout << std::endl;
}

void test_4()
{
    char s[] = "12*(6-3.5)=";
    Calculator calculator(s);

    calculator.printInfix();

    // calculator.infixToPostfix();
    // calculator.printPostfix();

    double result_1, result_2;
    result_1 = calculator.caluculateInfix();
    // result_2 = calculator.caluculatePostfix();

    std::cout << result_1 << std::endl;
    // std::cout << result_2 << std::endl;
}