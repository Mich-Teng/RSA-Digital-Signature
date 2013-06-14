#include "RSASignature.h"
#include "md5.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

RSASignature::RSASignature()
{
	srand((int)time(0));
	key_bit_length = 10;
}
void RSASignature::encryptSign(const Key& s_SK,const Key& r_PK ,const std::string& text,std::string& signature)
{
	MD5 md5(text);
	string md5_en = md5.md5();
	string tmp;
	encrypt(s_SK.key,s_SK.model,md5_en,tmp);
	encrypt(r_PK.key,r_PK.model,tmp,signature);
}

void RSASignature::decryptSign(const Key& r_SK,const Key& s_PK,const std::string& signature,std::string& md5)
{
	string tmp;
	decrypt(r_SK.key,r_SK.model,signature,tmp);
	decrypt(s_PK.key,s_PK.model,tmp,md5);
}

void RSASignature::decrypt(const Number& SK,const Number& i_model,const std::string& signature,std::string& md5)
{
	Number temp;
	unsigned p1=0,p2=0;
	string tmpstr;
	md5="";
	Number r_SK = SK;
	Number model = i_model;
	while((p2=signature.find('g',p1))!=-1)
	{
		tmpstr=signature.substr(p1,p2-p1);
		temp.Get(tmpstr);		
		temp=temp.Trans(r_SK,model);
		temp.UncodeStr(tmpstr);
		md5+=tmpstr;
		p1=p2+1;
	}
}
void RSASignature::encrypt(const Number& SK,const Number& i_model,const std::string& md5_en,string& signature)
{
	Number s_SK = SK;
	Number model = i_model;
	signature = "";
	Number temp;
	Number r = i_model;
	unsigned int token = 0;
	while(r>255)		// the number of ascii
	{
		r = r/1000;
		token++;
	}

	if(token == 0)
	{
		cout << "Error! model is not big enough" << endl;
		exit(1);
	}
	unsigned txtlen=md5_en.length(),start=0;               
	for(start=0;start<txtlen;start+=token)
	{
		string tmp_str( md5_en.substr(start,token) );
		temp.CodeStr(tmp_str);
		temp=temp.Trans(s_SK,model);
		temp.Put(tmp_str);
		signature+=tmp_str;
		signature+='g';
	}
}
