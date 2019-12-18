#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

void multiply(ll a[2][2],ll m[2][2])
{
    ll firstvalue=a[0][0]*m[0][0] + a[0][1]*m[1][0];
    ll secondvalue=a[0][0]*m[1][0] + a[0][1]*m[1][1];
    ll thirdvalue=a[1][0]*m[0][0] + a[1][1]*m[1][0];
    ll fourthvalue=a[1][0]*m[0][1] + a[1][1]*m[1][1];

    a[0][0]=firstvalue;
    a[0][1]=secondvalue;
    a[1][0]=thirdvalue;
    a[1][1]=fourthvalue;
}
void power(ll a[2][2], ll n)
{
    if(n==0 || n==1)
    return ;

    power(a,n/2);

    //multiplying a^n/2 * a^n/2
    multiply(a,a);

    if(n%2!=0)
    {
        ll m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }
}

ll febo(ll n)
{
    ll a[2][2]={{1,1},{1,0}};//find using recurrence  relation
    if(n==0)
    return 0;

    power(a,n-1);
    return a[0][0];
}

int main()
{
	ll a,b,c,n;
//	cin>>n;
	cout<<febo(0)<<endl;
	return 0;
}
