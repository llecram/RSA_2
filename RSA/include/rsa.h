#ifndef RSA_H
#define RSA_H
#include "..\ops.h"
class rsa{
public:
    rsa(int);
    rsa(ZZ,ZZ);
    void cifrado(string);
    void descifrado(vector<ZZ>);
    ZZ getd();
    ZZ gete();
    ZZ getn();
private:
    ZZ p;
    ZZ q;
    ZZ phi;
    ZZ n;
    ZZ e;
    ZZ d;
};

#endif // RSA_H
