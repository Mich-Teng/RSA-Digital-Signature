#ifndef RSASIGNATURE_H
#define RSASIGNATURE_H
#include "Number.h"
#include "Key.h"
#include <string>
class RSASignature
{
public:
	RSASignature();
	void encryptSign(const Key& s_SK,const Key& ,const std::string& text,std::string& signature);
	void decryptSign(const Key& r_SK,const Key& ,const std::string& signature,std::string& md5);
	bool verify(const std::string& text,const std::string& md5);
private:
	unsigned int key_bit_length;
	void encrypt(const Number& s_SK,const Number& ,const std::string& text,std::string& signature);
	void decrypt(const Number& r_SK,const Number& ,const std::string& signature,std::string& md5);
};

#endif