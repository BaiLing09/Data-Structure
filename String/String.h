#ifndef __STRING_H
#define __STRING_H

#include "math.h"
#include <cstring>
#include <exception> //异常处理类的头文件
#include <iostream>
#include <string>

class String
{
    private:
        char *data;//存储串
        int maxSize;//最大存储容量
        int curLength;//串长度
        void resize(int len);//扩大数组长度

    public:
        String();
        String(const char *str = NULL);
        String(const String &str);
        ~String();
        int capacity() const; //最大存储容量
        int size() const;//获取串长度
        bool empty() const;//判空
        int compare(String &s) const;    //比较与s串的大小，1：this的大；-1：s的大
        String subStr(int pos, int num) const;   //从pos位置取num个字符
        int bfFind(const String &s, int pos = 0) const; //朴素模式匹配
        String &insert(int pos, const String &s);//在pos位置插入串s
        String &erase(int pos, int num);//删除pos位置后的num个字符
        const char *toCharStr() const;  //获取字符数组data
        int kmpFind(const String &t, int pos = 0);//改进模式匹配算法  返回-1：失配 ； 0：子串为空串
        void getNext(const String &t, int *next);//获取next数组
        void getNextVal(const String &t, int *nextVal);//获取nextval数组
        bool operator==(const String &str) const;      //重载判断串是否相等
        String &operator+(const String &str);//重载连接串
        String &operator=(const String &str);//重载串赋值
        char &operator[](int n) const;       //重载通过[]下标取字符
        friend std::istream &operator>>(std::istream &cin, String &str);//重载输入串
        friend std::ostream &operator<<(std::ostream &cout, String &str);//重载输出串

};

class outOfRange:public std::exception
{
    public:
        const char *waht() const throw()
        {
            return "ERROR! OUT OF RANGE.\n";
        }
};

class badSize : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "ERROR! BAD SIZE.\n";
        }
};

#endif