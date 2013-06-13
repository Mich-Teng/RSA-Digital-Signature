#ifndef NUMBER_H
#define NUMBER_H
#include <string>

#define DEC 10
#define MAX_BIT_LENGTH 3000
#define MAX_DIGIT_LENGTH MAX_BIT_LENGTH/4

class Number   // encapsulate the operator
{
public:
// length of number of radix 2    
    unsigned length;
// record the value of digit
    unsigned long num[MAX_DIGIT_LENGTH];

    Number();
    Number(unsigned long n);
    Number(const Number &);
    ~Number();

/*****************************************************************
 *  basic calculation
*****************************************************************/
    void operator = (unsigned long A);
    void operator = (const Number& A);

    friend bool operator <(const Number& A,const Number& B);
    friend bool operator <(unsigned long A,const Number& B);
    friend bool operator <(const Number& A,unsigned long B);

    friend bool operator >(const Number& A,const Number& B);
    friend bool operator >(unsigned long A,const Number& B);
    friend bool operator >(const Number& A,unsigned long B);

    friend bool operator ==(const Number& A,const Number& B);
    friend bool operator ==(unsigned long A,const Number& B);
    friend bool operator ==(const Number& A,unsigned long B);

    friend bool operator <=(const Number& A,const Number& B);
    friend bool operator <=(unsigned long A,const Number& B);
    friend bool operator <=(const Number& A,unsigned long B);

    friend bool operator >=(const Number& A,const Number& B);
    friend bool operator >=(unsigned long A,const Number& B);
    friend bool operator >=(const Number& A,unsigned long B);

    friend bool operator !=(const Number& A,const Number& B);
    friend bool operator !=(unsigned long A,const Number& B);
    friend bool operator !=(const Number& A,unsigned long B);

    friend Number operator +(const Number& A,const Number& B);
    friend Number operator +(unsigned long A,const Number& B);
    friend Number operator +(const Number& A,unsigned long B);

    friend Number operator -(const Number& A,const Number& B);
    friend Number operator -(unsigned long A,const Number& B);
    friend Number operator -(const Number& A,unsigned long B);

    friend Number operator *(const Number& A,const Number& B);
    friend Number operator *(unsigned long A,const Number& B);
    friend Number operator *(const Number& A,unsigned long B);

    friend Number operator /(const Number& A,const Number& B);
    friend Number operator /(unsigned long A,const Number& B);
    friend Number operator /(const Number& A,unsigned long B);

    friend Number operator %(const Number& A,const Number& B);
    friend unsigned long operator %(unsigned long A,const Number& B);
    friend unsigned long operator %(const Number& A,unsigned long B);

/*****************************************************************
输入输出
Get，从字符串按10进制或16进制格式输入到大数
Put，将大数按10进制或16进制格式输出到字符串
*****************************************************************/
	void Get(std::string &str, unsigned int system=DEC);//加入读取数组的方向
    void Put(std::string &str, unsigned int system=DEC);

	void CodeStr(std::string &str);
	void UncodeStr(std::string &str);
/*****************************************************************
RSA相关运算
Rab，拉宾米勒算法进行素数测试
Euc，大衍求一术求模逆
Trans，蒙哥利亚算法进行幂模运算
GetPrime，产生指定长度的随机大素数
*****************************************************************/
    int Rab();
    Number Euc(Number& A);
    Number Trans(Number& P, Number& M);
    void GetPrime(int bits);
	void GetNum(int bits);
};


#endif
