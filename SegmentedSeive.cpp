#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100001

vector<int >* Seive(){

    bool isprime[MAX];
    for(int i=0;i<MAX;i++)
        isprime[i]=true;

    for(int i=2;i*i<MAX;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    vector<int >* primes =new vector<int >();
    primes->push_back(2);
    for(int i=3;i<MAX;i+=2)
    {
        if(isprime[i])
            primes->push_back(i);
    }
    return primes;

}
void printprimes(ll l,ll r, vector<int >* & primes)
{
    bool isprime[r-l+1];

    for(int i=0;i<=r-l;i++)
        isprime[i]=true;

    for(ll i=0;primes->at(i)*(long long) primes->at(i)<=r;i++)
    {
        int currprime= primes->at(i);
        //just smaller or equal to l
        ll base=(l/(currprime))*(currprime);
        if(base<l)
        {
            base+=currprime;
        }
        //mark all multiples within L to R as false
        for(ll j=base;j<=r;j+=currprime)
        {
            isprime[j-l]=false;
        }

        //there may be a case where base is itself a prime number
        if(base == currprime)
        {
            isprime[base-l]=true;
        }
    }

    for(int i=0;i<=r-l;i++)
    {
        if(isprime[i]==true)
        {
            cout<< i+l <<endl;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    vector<int >* primes=Seive();
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        printprimes(l,r,primes);
    }
    return 0;
}
