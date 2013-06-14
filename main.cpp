#include "md5.h"
#include "RSAKeyProducer.h"
#include "Number.h"
#include <string>
#include <iostream>
#include "RSASignature.h"
using namespace std;
int main() {
	Key t_PK,t_SK;
	string text = "abc" ;
	Key q_PK,q_SK;
	RSAKeyProducer t(32),q(32);
	t.produceKey(t_PK,t_SK);    // generate sender's key
	q.produceKey(q_PK,q_SK);	// generate receiver's key
	RSASignature w;
	string sign;
	string md5;
	w.encryptSign(t_SK,q_PK,text,sign);
	w.decryptSign(q_SK,t_PK,sign,md5);
	cout << md5 << endl;
	MD5 md(text);
	string md5_origin = md.md5();
	cout << md5_origin << endl;
   return 0;
}
