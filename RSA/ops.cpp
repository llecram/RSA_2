#include "ops.h"
ZZ gcd(ZZ x, ZZ y){
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    while(x != ZZ(0)){
        while(ZZ(x&1)==ZZ(0)){
            x>>=1;
        }
        while(ZZ(y&1)==ZZ(0)){
            y>>=1;
        }
        ZZ t=ZZ(abs(x-y))<<1;
        if(x>=y){
            x=t;
        }
        else{
            y=t;
        }
    }
    return ZZ(g*y);
}
ZZ gcdext(ZZ x, ZZ y){
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    ZZ u(x);
    ZZ v(y);
    ZZ A(1);
    ZZ B(0);
    ZZ C(0);
    ZZ D(1);
    while(true){
        while(ZZ(u&1)==ZZ(0)){
            u>>=1;
            if(ZZ((A|B)&1)==ZZ(0)){
                A>>=1;
                B>>=1;
            }
            else{
                A=(A+y)>>1;
                B=(B-x)>>1;
            }
        }
        while(ZZ(v&1)==ZZ(0)){
            v>>=1;
            if(ZZ((C|D)&1)==ZZ(0)){
                C>>=1;
                D>>=1;
            }
            else{
                C=(C+y)>>1;
                D=(D-x)>>1;
            }
        }
        if (u>=v){
            u=u-v;
            A-=C;
            B-=D;
        }
        else{
            v=v-u;
            C-=A;
            D-=B;
        }
        if(u == ZZ(0)){
            ZZ a(C);
            ZZ b(D);
            return a;
        }
    }
}
ZZ inversa(ZZ x, ZZ y){
    ZZ c=gcdext(x,y);
	while(c<ZZ(0)){
        c+=y;
	}
	return c;
}
ZZ modulo(ZZ x, ZZ y){
    if (y == 0) {
		return ZZ(0);
	}
	ZZ r = x - (x / y)*y;
	while (r < 0) {
		r +=y;
	}
	return r;
}
ZZ generare(ZZ phi,int g){
    ZZ a;
    a=RandomLen_ZZ(g);
    while(true){
        if(a>1 && a<phi && gcd(phi,a)==1){
            return a;
        }
        else{
            a=RandomLen_ZZ(g);
        }
    }
}
string rev(string b){
    string temp;
    for(int i=0;i<b.size();i++){
        temp+=b[b.size()-1-i];
    }
    return temp;
}
string ZZ_to_string(ZZ s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
string binario(ZZ a){
    string tmp;
    while(a!=ZZ(0)){
        tmp+=ZZ_to_string(ZZ(a%2));
        a/=ZZ(2);
   }
   tmp=rev(tmp);
   return tmp;
}
ZZ bynexpo(ZZ b, ZZ n, ZZ m){
    ZZ x(1);
    ZZ power=ZZ(modulo(b,m));
    string aux_0=binario(n);
    for(int i=aux_0.size()-1;i>=0;i--){
        if(aux_0[i]=='1'){
            x=modulo(ZZ(x*power),m);
        }
        power=modulo(ZZ(power*power),m);
    }
    return x;
}