#include "RSAKeyProducer.h"

using namespace std;

RSAKeyProducer::RSAKeyProducer()
{
	key_bit_length = 32;
}

RSAKeyProducer::RSAKeyProducer(int bit_length)
{
	key_bit_length = bit_length;
}

bool RSAKeyProducer::produceKey(Key& PK, Key& SK)
{
	Number p,q,w;
	PK.key.GetPrime(key_bit_length);
	do{
		p.GetPrime(key_bit_length/2);
		q.GetPrime(key_bit_length/2);
		if( p == q )
			continue;
		w = (p-1)*(q-1);
	}while(w%PK.key == 0);	// do the process until PK and model mutual prime
	SK.key = PK.key.Euc(w);
	PK.model = p*q;
	SK.model = p*q;
	
	return true;
}
