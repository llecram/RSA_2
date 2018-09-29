#include "rsa.h"
rsa::rsa(int a){
    //p=GenPrime_ZZ(a);
    //q=GenPrime_ZZ(a);
    //n=p*q;
    n=ZZ(52500);
    //phi=((p-ZZ(1))*(q-ZZ(1)));
    //e=generare(phi,a);
    //d=inversa(modulo(phi,n),e);
    d=ZZ(19);
}
rsa::rsa(ZZ e1,ZZ n1){
    e=e1;
    n=n1;
}
void rsa::cifrado(string mensaje){
    ZZ aux;
	for (int i = 0; i < mensaje.size(); i++) {
        aux=bynexpo(ZZ(alfabeto.find(mensaje[i])),e,n);
        cout<<aux<<" ";
	}
}
void rsa::descifrado(vector<ZZ> a){
    string aux;
	int tmp_1;
	ZZ tmp_2;
	for (int i = 0; i < a.size(); i++) {
        tmp_2=bynexpo(a[i],d,n);
        cout<<tmp_2<<endl;
        conv(tmp_1,tmp_2);
        aux+=alfabeto[tmp_1];
	}
	//cout<<aux;
}
ZZ rsa::getd(){
    return d;
}
ZZ rsa::gete(){
    return e;
}
ZZ rsa::getn(){
    return phi;
}
