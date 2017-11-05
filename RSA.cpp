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

int extended_euclid(int a,int b,int& A,int& B)
{
	int q,r,r_,s,s_,t,t_;
	
	s = 1,s_=0,t=0,t_=1;
	r=a,r_ = b;
	
	while(r_!=0)
	{
		q = r/r_;
		int tp = r_;
		r_ = r%r_;
		r = tp;
		
		tp = s_;
		s_ = s-(s_*q);
		s = tp;
		
		tp = t_;
		t_ = t-(q*t_);
		t = tp;
	}
	
	A = s;
	B = t;
	return r;
}

int modular_inverse(int a,int n)
{
	int a_,b_,A,B;
	a_ = n;
	b_ = a;
	
	int gc = extended_euclid(a_,b_,A,B);
	while(B<0)B+=n;
	if(gc==1)return B;
	
	cout << "a & n must be co prime " << endl;
	return -1;
	
}

int main ()
{
	int p,q,n,phi,d,e;
	cout << "Enter large prime numbers p & q " << endl;
	cin >> p >> q;
	n = p*q;
	
	cout << "n = " << n << endl;
	
	phi = (p-1)*(q-1);
	
	cout << "Enter public key(e) " << endl;
	cin >> e;
	
	d = modular_inverse(e,phi);
	
	cout << "\n\t--Encryption--" << endl;
	
	int P;
	cout << "Enter plain text " << endl;
	cin >> P;
	
	int C;
	C = modular_exponentiation(P,e,n);
	
	cout << "Ciphertext = " << C << endl;
	
	cout << "\n\t--Decryption--" << endl;
	
	int P_ = modular_exponentiation(C,d,n);
	
	cout << "Plaintext = " << P_ << endl;
	
	
}
