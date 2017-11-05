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
	int p,e,a,b;
	cout << "Enter large prime number p : " << endl;
	cin >> p;
	
	e = getPrimitive(p);
	
	cout << "primitive element = " << e << endl;
	
	cout << "Enter private keys of Alice and Bob " << endl;
	cin >> a >> b;
	
	int Xa,Xb;
	Xa = modular_exponentiation(e,a,p);
	Xb = modular_exponentiation(e,b,p);
	
	int Ka,Kb;
	
	Ka = modular_exponentiation(Xb,a,p);
	Kb = modular_exponentiation(Xa,b,p);
	
	cout << "Ka = " << Ka << " Kb = " << Kb << endl;
	int K = Ka;
	cout << "Common Key exchanged = Ka = Kb = K = " << K << endl;
	
	
	return 0;
}

/*

------OUTPUT------

Enter large prime number p : 
31
primitive element = 3
Enter private keys of Alice and Bob 
7
11
Ka = 22 Kb = 22
Common Key exchanged = Ka = Kb = K = 22
------------------
*/
