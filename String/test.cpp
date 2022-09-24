#include "test.h"

void test1()
{
    char str[6] = "Hello";
    char t[8] = "Hello";
    String tm(t);
    String s(str);
    std::cout << s << std::endl;
    std::cout << s.capacity() << std::endl;
    std::cout << s.compare(tm) << std::endl;
    String tmp(s.subStr(2, 3));
    std::cout << tmp << std::endl;
    std::cout << s.insert(4,tmp) << std::endl;
    std::cout << s.erase(3, 3) << std::endl;
    std::cout << (s == tmp) << std::endl;
    String p(s + tmp);
    std::cout << p << std::endl;

}

void test2()
{
    char a[12] = "Hello World";
    char b[5] = "orld";
    String t(a);
    String tm(b);
    std::cout << t.bfFind(tm) << std::endl;
    std::cout << t.kmpFind(tm) << std::endl;
}