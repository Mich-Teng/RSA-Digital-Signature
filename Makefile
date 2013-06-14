RSA : main.o md5.o Number.o RSAKeyProducer.o RSASignature.o
	g++ -o RSA main.o md5.o Number.o RSAKeyProducer.o RSASignature.o

main.o : main.cpp md5.h RSAKeyProducer.h Number.h RSASignature.h
	g++ -c main.cpp

md5.o : md5.cpp
	g++ -c md5.cpp

Number.o : Number.cpp Number.h
	g++ -c Number.cpp

RSAKeyProducer.o : RSAKeyProducer.cpp
	g++ -c RSAKeyProducer.cpp

RSASignature.o : RSASignature.cpp md5.h
	g++ -c RSASignature.cpp

clean :
	rm RSA main.o md5.o Number.o RSAKeyProducer.o RSASignature.o
