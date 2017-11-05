/*
 * Author : Sharique Eliyas
 * 
 * HomePage : https://shaeli1996.github.io
 * 
 * Date : Nov 6,2017
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int modular_exponentiation(int base,int expo,int mod)
{
	int result = 1;
	while(expo>0)
	{
		if(expo&1)result = (result*base)%mod;
		base = (base*base)%mod;
		expo = expo>>1;
	}
	return result;
}

int getPrimitive(int p)
{
	for(int i=2;i<p;i++)
	{
		bool isPrimitive = true;
		for(int j=p-2;j>0;j--)
		{
			if(modular_exponentiation(i,j,p)==1)
			{
				isPrimitive = false;
				break;
			}
		}
		if(isPrimitive)return i;
	}
	return -1;
}

int main ()
{
	int p,e,a,b,ea,eb;
	cout << "Enter large prime number p : " << endl;
	cin >> p;
	
	e = getPrimitive(p);
	
	cout << "primitive element = " << e << endl;
	
	cout << "Enter private keys of Alice and Bob " << endl;
	cin >> a >> b;
	
	cout << "Enter two private keys of Eve : " << endl;
	cin >> ea >> eb;
	
	int Xa,Xb,Xea,Xeb;
	Xa = modular_exponentiation(e,a,p);
	Xb = modular_exponentiation(e,b,p);
	Xea = modular_exponentiation(e,ea,p);
	Xeb = modular_exponentiation(e,eb,p);
	
	int Kae,Kea,Kbe,Keb;
	
	Kae = modular_exponentiation(Xea,a,p);
	Kea = modular_exponentiation(Xa,ea,p);
	
	cout << "Kae = " << Kae << " Kea = " << Kea << endl;
	int K1 = Kae;
	cout << "Common Key exchanged between Alice and Eve = Kae = Kea = K1 = " << K1 << endl;
	
	Kbe = modular_exponentiation(Xeb,b,p);
	Keb = modular_exponentiation(Xb,eb,p);
	
	cout << "Kbe = " << Kbe << " Keb = " << Keb << endl;
	int K2 = Kbe;
	cout << "Common Key exchanged between Eve and Bob = Kbe = Keb = K2 = " << K2 << endl;
	
	return 0;
}

/*

------OUTPUT------

Enter large prime number p : 
37
primitive element = 2
Enter private keys of Alice and Bob 
3 11
Enter two private keys of Eve : 
7 7
Kae = 29 Kea = 29
Common Key exchanged between Alice and Eve = Kae = Kea = K1 = 29
Kbe = 32 Keb = 32
Common Key exchanged between Eve and Bob = Kbe = Keb = K2 = 32


------------------

------------------
*/
