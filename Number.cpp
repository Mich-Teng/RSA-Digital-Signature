// Number.cpp: implementation of the Number class.
//
//////////////////////////////////////////////////////////////////////

#include "Number.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

const static int PrimeTable[551]=
{   2, 3,    5,    7,    11,   13,   17,   19,   23,   29,   31,
    37,   41,   43,   47,   53,   59,   61,   67,   71,   73,
    79,   83,   89,   97,   101,  103,  107,  109,  113,  127, 
    131,  137,  139,  149,  151,  157,  163,  167,  173,  179, 
    181,  191,  193,  197,  199,  211,  223,  227,  229,  233, 
    239,  241,  251,  257,  263,  269,  271,  277,  281,  283, 
    293,  307,  311,  313,  317,  331,  337,  347,  349,  353, 
    359,  367,  373,  379,  383,  389,  397,  401,  409,  419, 
    421,  431,  433,  439,  443,  449,  457,  461,  463,  467, 
    479,  487,  491,  499,  503,  509,  521,  523,  541,  547, 
    557,  563,  569,  571,  577,  587,  593,  599,  601,  607, 
    613,  617,  619,  631,  641,  643,  647,  653,  659,  661, 
    673,  677,  683,  691,  701,  709,  719,  727,  733,  739, 
    743,  751,  757,  761,  769,  773,  787,  797,  809,  811, 
    821,  823,  827,  829,  839,  853,  857,  859,  863,  877,
    881,  883,  887,  907,  911,  919,  929,  937,  941,  947, 
    953,  967,  971,  977,  983,  991,  997,  1009, 1013, 1019, 
    1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087,
    1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 
    1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 
    1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 
    1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381,
    1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 
    1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523,
    1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 
    1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 
    1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 
    1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 
    1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 
    1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 
    1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063,
    2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 
    2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 
    2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293,
    2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371,
    2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 
    2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 
    2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 
    2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 
    2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 
    2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 
    2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909,
    2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001,
    3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083,
    3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 
    3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 
    3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343,
    3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 
    3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 
    3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581,
    3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 
    3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 
    3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 
    3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 
    3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001
};

Number::Number()
{
	for(int i=0;i<MAX_DIGIT_LENGTH;i++)
		num[i]=0;
	length=1;
}


Number::Number(unsigned long n)
{
	*this=n;
}

Number::Number(const Number &A)
{
	*this=A;
}

Number::~Number()
{
}
/**************************************************************
 * assignment
**************************************************************/
void Number::operator = (unsigned long A)
{
	num[0] = A;
	length = 1;
	for(int i=length;i<MAX_DIGIT_LENGTH;i++)
		num[i]=0;
}

void Number::operator = (const Number& A)
{
	length=A.length;
	for(int i=0;i<MAX_DIGIT_LENGTH;i++)	// copy 0 as well
		num[i]=A.num[i];
}

/**************************************************************
比较
**************************************************************/
bool operator <(Number& A,Number& B)
{
	if(A.length>B.length)
		return false;
	if(A.length<B.length)
		return true;
	for(int i=A.length-1;i>=0;i--)
	{
		if(B.num[i]==A.num[i])
		       	continue;
		if(B.num[i]>A.num[i])
		       	return true;
		else 
			return false;
	}
	return 0;	// if A == B
}

bool operator <(unsigned long A,Number& B)
{
	if(B.length>1) 
		return true;
	return A < B.num[0];
}

bool operator <(Number& A,unsigned long B)
{
	if(A.length > 1)
	       	return false;
	return A.num[0]<B;
}

bool operator >(Number& A,Number& B)
{
	return B<A;
}

bool operator >(unsigned long A,Number& B)
{
	return B<A;
}

bool operator >(Number& A,unsigned long B)
{
	return B<A;
}

bool operator ==(Number& A,Number& B)
{
	if( A<B == false && A>B == false)
		return true;
	return false;
}
bool operator ==(unsigned long A,Number& B)
{
	if(B.length > 1)
	       	return false;
	return A==B.num[0];
}

bool operator ==(Number& A,unsigned long B)
{
	return B == A;
}

bool operator <=(Number& A,Number& B)
{
	return !(A>B);
}
bool operator <=(unsigned long A,Number& B)
{
	return !(A>B);
}

bool operator <=(Number& A,unsigned long B)
{
	return !(A>B);
}

bool operator >=(Number& A,Number& B)
{
	return !(A<B);
}

bool operator >=(unsigned long A,Number& B)
{
	return !(A<B);
}

bool operator >=(Number& A,unsigned long B)
{
	return !(A<B);
}

bool operator !=(Number& A,Number& B)
{
	return !(A==B);
}

bool operator !=(unsigned long A,Number& B)
{
	return !(A==B);
}

bool operator !=(Number& A,unsigned long B)
{
	return !(A==B);
}

/**************************************************************
 * operation add
**************************************************************/
Number operator +(Number& A,Number& B)
{
	Number X;
	X=B;
	unsigned long sum;
	unsigned flag=0;
	if(A.length>B.length) X.length=A.length;
	
	for(unsigned int i=0;i<X.length;i++)
	{
		sum=A.num[i];
		sum+=X.num[i]+flag;
		X.num[i]=(unsigned long)sum;
		if( A.num[i] > ~X.num[i])
			flag =1;
		else
			flag = 0;

	}
	if(flag)
		X.num[X.length++]=1;
	return X;
}

Number operator +(unsigned long A,Number& B)
{
	Number sum = A;
	return sum+B;
}

Number operator +(Number& A,unsigned long B)
{
	Number sum = B;
	return sum+A;
}

/**************************************************************
 * operation subtraction
**************************************************************/
Number operator -(Number& B,Number& A)
{
	Number X;
	X=B;
	if(X<=A)	// we only surport B > A
	{
		X=0;
		return X;
	}

	unsigned flag=0,i;
	unsigned long num;
	for(i=0;i<B.length;i++)
	{
		if((X.num[i]>A.num[i])
		   ||((X.num[i]==A.num[i])&&
				flag==0))
		{
			X.num[i]-=A.num[i]+flag;
			flag=0;
		}
		else
		{
			num=0x100000000+B.num[i];
			X.num[i]=(unsigned long)(num-flag-A.num[i]);
			flag=1;
		}
	}
	while(X.num[X.length-1]==0) X.length--;

	return X;
}

Number operator -(unsigned long A,Number& B)
{
	Number C = A;
	return C-B;
}

Number operator -(Number& B,unsigned long A)
{
	Number X;
	X=B;

	if(A<=X.num[0])
	{
		X.num[0]-=A;
		return X;
	}
	if(X.length==1) 
	{
		X=0;
		return X;
	}

	unsigned __int64 tmp=0x100000000+X.num[0];
	X.num[0]=(unsigned long)(tmp-A);

	unsigned i=1;
	while(X.num[i]==0) X.num[i++]=0xffffffff;
	X.num[i]--;
	if(X.num[i]==0) X.length--;

	return X;
}

/**************************************************************
 * multiplication
**************************************************************/
Number operator *(Number& A,Number& B)
{
	if(A.length==1) return B*A.num[0];

	Number X;
	X=B;
	unsigned __int64 mul,flag=0,sum;
	unsigned i,j;

	X.length=B.length+A.length-1;

	for(i=0;i<X.length;i++)
	{
		sum=flag;
		flag=0;
		for(j=0;j<A.length;j++)
		{
			if(((i-j)>=0)&&((i-j)<B.length))
			{
				mul=B.num[i-j];
				mul*=A.num[j];
				flag+=mul>>32;
				mul=mul&0xffffffff;
				sum+=mul;
			}
		}
		
		flag+=sum>>32;
		X.num[i]=(unsigned long)sum;
	}
	if(flag)
		X.num[X.length++]=(unsigned long)flag;
	
	return X;
}

Number operator *(unsigned long A,Number& B)
{
	Number X;
	X=B;
	unsigned __int64 mul;
	unsigned long flag=0;
	for(unsigned i=0;i<X.length;i++)
	{
		mul=X.num[i];
		mul=mul*A+flag;
		X.num[i]=(unsigned long)mul;
		flag=(unsigned long)(mul>>32);
	}
	if(flag)
		X.num[X.length++]=flag;

	return X;
}

Number operator *(Number& A,unsigned long B)
{
	return B*A;
}

/**************************************************************
 * division
**************************************************************/
Number operator /(Number& B,Number& A)
{
	if(A.length==1) return B/(A.num[0]);
	Number X,Y,Z;
	unsigned i,len;
	unsigned __int64 num,div;
	Y=B;
	while(Y>=A)
	{
		div=Y.num[Y.length-1];
		num=A.num[A.length-1];
		len=Y.length-A.length;
		if((div==num)&&len==0)
		{
			X=X+1;break;
		}
		if((div<=num)&&len)
		{
			len--;
			div=(div<<32)+Y.num[Y.length-2];
		}
		div=div/(num+1);
		Z=div;
		if(len)
		{
			Z.length+=len;
			for(i=Z.length-1;i>=len;i--) Z.num[i]=Z.num[i-len];
			for(i=0;i<len;i++) Z.num[i]=0;
		}
		X=X+Z;
		Y=Y-A*Z;
	}
	return X;
}

Number operator /(unsigned long A,Number& B)
{
	Number C;
	C=A;
	return C/B;
}

Number operator /(Number& B,unsigned long A)
{
	Number X;
	X=B;
	if(X.length==1)
	{
		X.num[0]/=A;
		return X;
	}
	unsigned long div,mul;
	unsigned long flag=0;
	for(int i=X.length-1;i>=0;i--)
	{
		div=flag;
		div=(div<<32)+X.num[i];
		X.num[i]=(unsigned long)(div/A);
		mul=(div/A)*A;
		flag=(unsigned long)(div-mul);
	}
	if(X.num[X.length-1]==0) X.length--;
	return X;
}

/***********************************************
 * operation mod
***********************************************/
Number operator %(Number& B,Number& A)
{
	Number X,Y;
	unsigned __int64 div,num;
    unsigned long carry=0;
	unsigned i,len;
    X=B;
    while(X>=A)
    {
		div=X.num[X.length-1];
		num=A.num[A.length-1];
		len=X.length-A.length;
		if((div==num)&&(len==0)){X=X-A;break;}
		if((div<=num)&&len){len--;div=(div<<32)+X.num[X.length-2];}
		div=div/(num+1);
		Y=div;
		Y=A*Y;
		if(len)
		{
			Y.length+=len;
			for(i=Y.length-1;i>=len;i--)Y.num[i]=Y.num[i-len];
			for(i=0;i<len;i++)Y.num[i]=0;
		}
        X=X-Y;
    }
    return X;
}

unsigned long operator %(unsigned long A,Number& B)
{
	if(B>A) return A;
	else if(B==A) return 0;
	else
		return A%B.num[0];
}

unsigned long operator %(Number& B,unsigned long A)
{
	if(B.length==1) return(B.num[0]%A);
    unsigned __int64 div;
    unsigned long carry=0;
    for(int i=B.length-1;i>=0;i--)
    {
        div=B.num[i];
		div+=carry*0x100000000;
        carry=(unsigned long)(div%A);
    }
    return carry;
}

/***********************************************
 * convert char * to number
***********************************************/
void Number::Get(string &str, unsigned int system)
{
	int len=str.length(),k,i;
	*this=0;
	
	for(i=0;i<len;i++)
	{
		*this=*this*system;//x=x*sys+k
		if((str[i]>='0')&&(str[i]<='9')) k=str[i]-48;
		else if((str[i]>='A')&&(str[i]<='F'))k=str[i]-55;
		else if((str[i]>='a')&&(str[i]<='f'))k=str[i]-87;
		else k=0;
		*this=*this+k;//+k
	}	
}

void Number::CodeStr(string &str)
{
	int len=str.length(),i;
	*this=0;
	for(i=0;i<len;i++)
	{
		*this=*this*1000;
		unsigned char ch;
		ch=str[i];
		*this=*this+ch;
	}
}

void Number::UncodeStr(string &str)
{
	str="";
	char a;
	Number X;
	X=*this;
	while(X.num[X.length-1]>0)
	{
		a=X%1000;
		str.insert(0,1,a);
		X=X/1000;
	}

}


/***********************************************
 * convert digit to char*
***********************************************/ 

void Number::Put(string &str, unsigned int system)
{
	if((length==1)&&(num[0]==0))
	{
		str="0";
		return;
	}
	str="";
	char hex_table[]="0123456789ABCDEF";
	char ch;
	int a;
	Number X;
	X=*this;
	while(X.num[X.length-1]>0)
	{
		a=X%system;
		ch=hex_table[a];
		str.insert(0,1,ch);
		X=X/system;
	}
}

/***********************************************
EX=1(mod M) 求模M逆 (算法为黄宗宪"大衍求一术")
***********************************************/
#define UP 1
#define DOWN -1

Number Number::Euc(Number& A)
{
	Number E,M,X(1),Y;
	E=*this%A;
	M=A%E;

	int order=UP;
	Y=A/E;
	while(E!=1)
	{
		if(M==1)
		{
			X=(E-M)*Y+X;
			break;
		}
		if(order==UP)//填上面
		{
			X=E/M*Y+X;
			E=E%M;
		}
		else
		{
			Y=M/E*X+Y;
			M=M%E;			
		}
		order=-order;
	}
	return X;
}

/****************************************************************************************
求乘方模 X=N^A MOD B 暂不添加对ul的支持
****************************************************************************************/
Number Number::Trans( Number& Q, Number& M)
{
	Number N(*this);
	Number P(Q);
	Number result(1);
	N=N%M;
	while(P>1)
	{
		if((P.num[0])&1) result=((result%M)*(N%M))%M;
		N=((N%M)*(N%M))%M;
		P=P/2;
	}
	return ((result%M)*(N%M))%M;
}

/****************************************************************************************
Miller-Rabin素性测试
****************************************************************************************/
int Number::Rab()
{
	int i;
    for( i=0;*this>PrimeTable[i]&&i<551;i++)
		if(*this%PrimeTable[i]==0)
			return 0;
	if(*this==PrimeTable[i]) return 1;

	Number N,K,B,Z,M;
	//K=2^s*M
	//K记录N-1,B为测试基,Z为测试用
	//Z=B^(2^r*M)%N ,相当于Z不断做平方

	unsigned s=0,r=0;
	//2的指数

	N=*this;
	K=N-1;
	M=K;//N-1
	while((M.num[0]&1)==0)
	{
		M=M/2;//用位运算可能更快一点
		s++;// M/=2
	}
//	此时K=2^s*M;

	for(int i=0;i<5;i++)
	{
		B=(rand()+1)%K;
		B=(B*(rand()+1))%K;
		B=(B*(rand()+1))%K;
		Z=B.Trans(M,N);
		if(Z==1||Z==K) continue;//继续测试

		for(r=0;r<s;r++)
		{
			Z=(Z*Z)%N;
			if(Z==K) break;//继续测试
		}
		if(r==s)
			return 0;//一次没通过,out
	}
	//5次通过
	return 1;
}

void Number::GetPrime(int bits)
{
	do
	{
		GetNum(bits);
	}while(Rab()==0);
}

void Number::GetNum(int bits)
{
	int len=bits;
	int rlen= len % 32;
	len = (len-1)/32;
	

	Number M;
	M.length=(int)len+1;
	for(int i=0;i<M.length;i++)
		M.num[i]=(rand()+1)*0x10000+rand()+1;

	M.num[0]|=3;
	M.num[M.length-1]&=0xffffffff>>(32-rlen);
	
	*this=M;
}
