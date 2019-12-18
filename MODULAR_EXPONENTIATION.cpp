#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int


ll modExpo(ll a, ll b,ll c)
{
    if(a==0)
    return 0;

    if(b==0)
    return 1;

    ll ans;
    if(b%2==0)
    {
        ll smallans=modExpo(a,b/2,c);//FOR EVEN POWER
        ans = (smallans * smallans)%c;
    }
    else
    {
        ll smallans=modExpo(a,b-1,c);//FOR ODD POWER CALL FOR 1 LESS THEN TS CALC. FROM EVEN ..IN END * WITH A
        ans = (smallans* a%c)%c;
    }
    return (ans+c)%c;
}

int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<modExpo(a,b,c)<<endl;
	return 0;
}
