#include "String.h"


String::String()
{
    this->maxSize = 10;
    this->data = new char[1];
    this->data[0] = '\0';
    this->curLength = 0;
}

String::String(const char* str)
{
    this->maxSize = 2 * strlen(str);
    this->data = new char[this->maxSize + 1];
    strcpy(this->data, str);
    this->curLength = strlen(this->data);
}

String::String(const String &str)
{
    this->maxSize = str.maxSize;
    this->data = new char[this->maxSize + 1];
    strcpy(this->data, str.data);
    this->curLength = strlen(str.data);
}

String::~String()
{
    delete[] this->data;
}

int String::capacity() const
{
    return this->maxSize;
}

int String::size() const
{
    return this->curLength;
}

bool String::empty() const
{
    return this->curLength == 0;
}

int String::compare(String &s) const
{
    int i = 0;
    while (this->data[i] !='\0' || s.data[i] != '\0')//'\0'比其它字符都小，该判断先遇到空字符的认为是小的字符
    {
        if(this->data[i] > s.data[i])//this > s
            return 1;
        else if(this->data[i] < s.data[i])//this < s
            return -1;
        i++;
    }
    if(this->data[i] == '\0' && s.data[i] != '\0')//s没有元素
        return -1;
    else if(this->data[i] != '\0' && s.data[i] == '\0')//this没有元素
        return 1;
    return 0;
}

int String::bfFind(const String &s, int pos) const
{
    int i = 0, j = 0;//主串和子串的指针
    if(this->curLength < s.curLength)//子串长度大于主串，直接无法匹配
    {
        return -1;
    }

    while( i < this->curLength && j < s.curLength)
    {
        if(this->data[i] == s.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;//主串回溯
            j = 0;//子串从头开始
        }
    }

    if(j >= s.curLength)//要保证全部遍历子串才能确定全部完成匹配
    {
        return (i - s.curLength);//此时i指向与子串最后一个字符，所以要减去子串的长度
    }
    else
    {
        return -1;
    }
}

String String::subStr(int pos, int num) const
{
    int i = 0;
    String tmp("");
    if(pos < 0 || pos >this->curLength)
    {
        throw outOfRange();
    }
    if(num < 0)
    {
        throw badSize();
    }
    if(num > this->curLength - pos)//若数量大于pos到串尾的字符数量则修改数量
    {
        num = this->curLength - pos;
    }
    delete[] tmp.data;
    tmp.maxSize = tmp.curLength = num;
    tmp.data = new char[num + 1];
    for (i = 0; i < num; i++)
    {
        tmp.data[i] = data[pos + i];
    }
    tmp.data[i] = '\0';
    return tmp;
}

String &String::insert(int pos, const String &s)
{
    if(pos > this->curLength || pos < 0)
    {
        throw outOfRange();
    }
    if (this->curLength + s.curLength > maxSize)
    {
        this->resize(2 * (this->curLength + s.curLength));
    }
    for (int i = this->curLength ; i >= pos; i--)//先将插入位置后面的内容放到元素组的最后面（也将s最后的'\0'写入了）
    {
        this->data[i + s.curLength] = this->data[i];
    }
    for (int j = 0; j < s.curLength; j++)//用插入的内容覆盖原来的内容
    {
        this->data[pos + j] = s.data[j];
    }
    this->curLength += s.curLength;
    return *this;
}

String & String::erase(int pos,int num)
{
    if(pos < 0 || pos > this->curLength - 1 )
    {
        throw outOfRange();
    }
    if(num < 0)
    {
        throw badSize();
    }
    if(num > this->curLength - pos)
    {
        num = this->curLength - pos;
    }
    for (int i = pos + num; i <= this->curLength; i++)//将数据前移覆盖删除数据
    {
        this->data[i - num] = this->data[i];
    }
    this->curLength -= num;
    return *this;
}

const char* String::toCharStr()const
{
    return this->data;
}

int String::kmpFind(const String &t, int pos)
{
    if(t.curLength == 0)
        return 0;
    if(this->curLength < t.curLength)//主串比子串短，直接失配
        return -1;
    int i = 0, j = 0;
    int *next = new int[t.curLength];
    // this->getNext(t, next);
    this->getNextVal(t, next);
    while (i < this->curLength && j < t.curLength)
    {
        if(j==-1 || this->data[i] == t.data[j])//子串在0处及最大头尾相同数（情况1，2）
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    delete[] next;
    if(j >= t.curLength)
        return (i - t.curLength);
    else
    {
        return -1;
    }
}

void String::getNext(const String &t, int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < t.curLength - 1)
    {
        if((j == -1) || (t[i] == t[j]))
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void String::getNextVal(const String &t, int *nextVal)
{
    int i = 0, j = -1;
    nextVal[0] = -1;
    while(i < t.curLength - 1)
    {
        if((j == -1) || (t[j] == t[i]))
        {
            i++;
            j++;
            if(t[i] != t[j])
            {
                nextVal[i] = j;
            }
            else
            {
                nextVal[i] = nextVal[j];
            }
        }
        else
        {
            j = nextVal[j];
        }
    }
}

void String::resize(int len)
{
    this->maxSize = len;
    char *temp = new char[this->maxSize + 1];
    strcpy(temp, this->data);
    delete[] this->data;
    this->data = temp;
}

String &String::operator+(const String &str)//str是常对象，只能调用它的常函数
{
    if(this->maxSize < this->curLength + str.size())
    {
        this->resize(2 * (this->curLength + str.size()));
    }
    strcat(this->data, str.data);
    this->curLength += str.curLength;
    return *this;
}

String &String::operator=(const String &str)
{
    if(this == &str)//当前串三相同的串
        return *this;
    delete[] this->data;//删除原空间
    this->data = new char[this->maxSize + 1];
    strcpy(this->data, str.toCharStr());
    this->curLength = str.size();
    return *this;
}

bool String::operator==(const String &str)const
{
    if(this->size() != str.size())
        return false;
    return strcmp(this->toCharStr(), this->toCharStr()) ? false : true;//调用cstring库
}

inline char& String::operator[](int n)const  //内联函数
{
    if( n < 0 || n >= this->curLength)
        throw outOfRange();
    else
        return this->data[n];
}


std::istream& operator>>(std::istream &cin,String &str)
{
    char *temp = new char[10000];
    std::cin >> temp;
    str.maxSize = 2 * strlen(temp);
    str.data = new char[str.maxSize + 1];
    strcpy(str.data, temp);
    str.curLength = strlen(temp);
    delete[] temp;
    return std::cin;
}

std::ostream& operator<<(std::ostream &cout,String &str)
{
    std::cout << str.data;
    return std::cout;
}