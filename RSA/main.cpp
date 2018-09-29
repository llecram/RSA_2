#include <iostream>
#include "rsa.h"
int main()
{
    //string mns;
    //getline(cin,mns);
    rsa objeto(8);
    vector<ZZ> a={ZZ(10507),ZZ(17864),ZZ(29411),ZZ(0)};
    objeto.descifrado(a);
    //cout<<endl<<objeto.gete()<<" "<<objeto.getn()<<" "<<objeto.getd()<<endl;
    //rsa emisor(ZZ(241),ZZ(52500));
    //emisor.cifrado("HOLA");
}
