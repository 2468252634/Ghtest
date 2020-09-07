
#include"D1119508_mystring.h"

MyString::MyString()            //无参构造函数
{
    last = -1;
    maxsize = n;
    str[0] = '\0';
}
MyString::MyString(const char* s)     //当C字符串过长，初始化时采用截尾处理
{
    last = -1;
    maxsize = n;
    do {
        last++;
        str[last] = s[last];
    } while (s[last] != '\0' && last < maxsize - 1);
    str[last] = '\0'; //截尾处理时，必须加串结束符  
}
char* MyString::getStr()
{
    return this->str;
}
//重载<运算符
bool MyString::operator<(const MyString& ms) const
{
    int i = 0, k;
    do {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last && i < ms.last);

    if (k < 0) return true;
    else if (i == last && i != ms.last) return true;
    return false;
}
//重载>运算符
bool MyString::operator>(const MyString& ms)const
{
    int i = 0, k;
    do
    {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < this->last && i < ms.last);
    if (k < 0)return false;
    else if (i == this->last && i != ms.last)return false;
    return true;
}

//重载==运算符
bool MyString::operator==(const MyString& ms) const
{
    int i = 0, k;
    if (last != ms.last) return false;
    do {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last);

    if (k != 0) return false;
    else return true;
}
//重载!=运算符
bool MyString::operator!=(const MyString& ms)const
{
    int i = 0, k;
    if (this->last == ms.last)return false;
    else
    {
        do
        {
            k = this->str[i] - ms.str[i];
            i++;
        } while (k == 0 && i < this->last);
        if (k != 0)return true;
        else return false;
    }
}
//这里重载的=是把C风格字符串赋给MyString  
//这里返回值为引用，不调用复制构造函数 
MyString& MyString::operator=(const char* ms)
{
    last = -1;
    do {
        last++;
        str[last] = ms[last];
    } while (ms[last] != '\0' && last < maxsize - 1);
    str[last] = '\0';    //截尾处理时，必须加串结束符 
    return *this;
}
MyString::MyString(const MyString& ms)
{
    this->last = -1;
    this->maxsize = n;
    do
    {
        this->last++;
        this->str[this->last] = ms.str[this->last];
    } while (ms.str[this->last] != '\0' && this->last < this->maxsize - 1);
    this->str[this->last] = '\0';
}
//重载[]运算符
char& MyString::operator[](int m)
{
    return this->str[m];
}
//重载=运算符（MyString）
MyString MyString::operator=(const MyString& ms)
{
    this->last = -1;
    do
    {
        last++;
        this->str[last] = ms.str[last];
    } while (this->last < ms.last);               //回头检查结束标志\0
    return *this;
}
//重载+运算符
MyString MyString::operator+(const MyString& ms)
{
    int i = -1;
    this->maxsize = n;
    MyString temp(*this);

    do
    {
        i++;
        temp.str[temp.last] = ms.str[i];
        temp.last++;
    } while (i < ms.last && temp.last < temp.maxsize - 1);
    temp.str[temp.last] = '\0';
    return temp;
}
//重载+=运算符
MyString MyString::operator+=(const MyString& ms)
{
    int i = -1;
    this->maxsize = n;

    do
    {
        i++;
        this->str[this->last] = ms.str[i];
        this->last++;
    } while (i < ms.last && this->last < this->maxsize - 1);
    this->str[this->last] = '\0';
    return *this;
}
//重载流运算符
istream& operator>>(istream& in, MyString& ms)
{
    in >> ms.str;
    return in;
}
ostream& operator<<(ostream& out, const MyString& ms)
{
    return out << ms.str;
}
//5.12的成员函数
char* MyString::strcat(char* s, const char* ct)
{
    int len = strlen(s);
    int i = -1;
    this->maxsize = n;
    do
    {
        i++;
        s[len] = ct[i];
        len++;
    } while (len < this->maxsize - 1 && ct[i] != '\0');
    s[len] = '\0';
    return s;
}
int MyString::strlen(const char* s)
{
    int i = 0, count = 0;
    for (; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
char* MyString::reverse(char* s)
{
    MyString temp(s);
    int i = strlen(s) - 1;
    int n = 0;
    for (; n < strlen(s); n++)
    {
        s[n] = temp.str[i];
        i--;
    }
    return s;

}
const char* MyString::strchr(const char* cs, char c)
{
    //    int len = strlen(cs);
    int i;
    for (i = 0; *cs != c && *cs != '\0'; cs++) {}

    if (cs[i] == '\0')return NULL;
    else return cs;
}
const char* MyString::strstr(const char* cs1, const char* cs2)
{
    int len = strlen(cs2);
    do
    {
        int count = 0;
        for (; *cs1 != *cs2 && *cs1 != '\0'; cs1++) { count++; }
        if ((count == 1 && *cs2 != cs2[0]) || (*cs2 == cs2[0] && *cs1 != '\0'))cs2++;
    } while (*cs2 != cs2[len - 1] && *cs1 != '\0' && *cs2 != '\0');
    if (*cs2 == '\0')return cs1 - len + 1;
    else return NULL;

}
/*
mystring::mystring()            //无参构造函数
{
    last = -1;
    maxsize = 0;
    str = NULL;
}
mystring::mystring(const char* s)     //当C字符串过长，初始化时采用截尾处理
{
    last = -1;
    maxsize = strlen(s) + 1;
    if (s)
    {
        if (str = new char[maxsize])
        {
            strcpy_s(str, maxsize, s);
            last = strlen(s);
        }
    }
    str = NULL;

}
mystring::mystring(const mystring& mystr)
{
    last = -1;
    maxsize = strlen(mystr.str) + 1;
    if (mystr.str)
    {
        if (this->str = new char[maxsize])
        {
            strcpy_s(this->str, maxsize, mystr.str);
            last = strlen(mystr.str);

        }
    }
    else this->str = NULL;
}
mystring::~mystring()
{
    if (str)
    {
        delete[]str;
    }
}
void mystring::show()const
{
    cout << str;
}
mystring& mystring::operator=(const char* ms)
{
    last = -1;
    maxsize = strlen(ms) + 1;
    if (ms)
    {
        if (this->str = new char[maxsize])
        {
            strcpy_s(this->str, maxsize, ms);
            last = strlen(ms);
        }
    }
    else this->str = NULL;
    return *this;
}
//重载=运算符（MyString）
mystring& mystring::operator=(const mystring& ms)
{
    last = -1;
    maxsize = strlen(ms.str) + 1;
    if (ms.str)
    {
        if (this->str = new char[maxsize])
        {
            strcpy_s(this->str, maxsize, ms.str);
            last = strlen(ms.str);
        }
    }
    else this->str = NULL;
    return *this;
}
mystring& mystring::operator+=(const mystring& ms)
{
    int i;
    this->maxsize = strlen(this->str) + strlen(ms.str) + 1;
    char* temp=NULL;
    if (this->str)temp = new char[strlen(this->str) + 1];
    strcpy_s(temp, strlen(this->str) + 1, str);
    if (ms.str && this->str)
    {
        delete[]this->str;                                                      //delete了str
        this->str = new char[maxsize];
        for (i = 0; i <= this->last; i++)
        {
            this->str[i] = temp[i];
        }
        last++;
        for (i = 0; i <= ms.last; i++, last++)
        {
            this->str[last] = ms.str[i];
        }
    }
    this->str[this->last] = '\0';
    return *this;
}
char& mystring::operator[](int m)
{
    return this->str[m];
}

bool operator> (const mystring& s1, const mystring& s2)
{
    int i = 0, k;
    do
    {
        k = s1.str[i] - s2.str[i];
        i++;
    } while (k == 0 && i < s1.last && i < s2.last);
    if (k < 0)return false;
    if (i == s1.last && i != s2.last)return false;
    return true;
}
bool operator< (const mystring& s1, const mystring& s2)
{
    int i = 0, k;
    do
    {
        k = s1.str[i] - s2.str[i];
        i++;
    } while (k == 0 && i < s1.last && i < s2.last);
    if (k > 0)return false;
    if (i == s1.last && i != s2.last)return false;
    return true;
}
bool operator==(const mystring& s1, const mystring& s2)
{
        int i = 0, k;
        if (s1.last != s2.last) return false;
        do {
            k = s1.str[i] - s2.str[i];
            i++;
        } while (k == 0 && i < s1.last);

        if (k != 0) return false;
        else return true;
}
mystring operator+ (const mystring& s1, const mystring& s2)
{

}
//*********************************************************
int main()
{
    mystring s1("yang");
    s1.show();
    return 0;

}
*/