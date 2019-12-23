#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
	ll t,n,m,x,k,i,j,p;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n>>s;
        p=0;
        if(n==0)
        {
            cout<<s<<endl;
            continue;
        }
        for(i=0;i<s.length();i++)//MAIN CONCEPT WAS TO TAKE THE LARGE NO. INPUT AS A STRING THEN USE
            //THE BASIC PROPERTY OF GCD OF gcd(A,B)=gcd(B, A%B)
        {
            x=s[i]-48;
            p=((p*10) + x%n)%n;//MODULO IS DONE STEP BY STEP USING PREVIOUS VALUE
            //cout<<k<<endl;
           // p=k;
        }
        
        cout<<__gcd(n,p)<<endl;
    }
	return 0 ;
}
