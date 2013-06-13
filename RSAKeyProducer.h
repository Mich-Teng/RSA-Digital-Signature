#ifndef RSAKEYPRODUCER_H
#define RSAKEYPRODUCER_H

#include "Number.h"
#include "Key.h"

class RSAKeyProducer
{
public:
	bool produceKey(Key& PK,Key& SK);		// PKI : public key  SK: secret key
	RSAKeyProducer(int);					// input the bits of key
	RSAKeyProducer();						// default constructor

private:
	unsigned int key_bit_length;
};
#endif