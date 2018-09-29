#ifndef OPS_H_INCLUDED
#define OPS_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
static string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
ZZ gcd(ZZ,ZZ);
ZZ gcdext(ZZ,ZZ);
ZZ modulo(ZZ,ZZ);
ZZ bynexpo(ZZ,ZZ,ZZ);
ZZ inversa(ZZ,ZZ);
ZZ generare(ZZ,int);
string ZZ_to_string(ZZ);
string rev(string);
string binario(ZZ);
#endif // OPS_H_INCLUDED
