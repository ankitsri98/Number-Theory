#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

ll sumphi[1000002]={0};
ll x;
void eulerSeive(ll n)
{
    ll a[n+2];
    for(ll i=0;i<=n+1;i++)
    {
        a[i]=i;
    }
    for(ll i=2;i<=n;i++)
    {
        if(a[i]==i)
        {
            a[i]=i-1;
            for(ll j=2*i;j<=n;j+=i)
            {
                a[j]=(a[j]*(i-1))/i;
            }
        }
        else
        {
            continue;
        }
    }
    /*for(ll i=1;i<=n;i++)
    cout<<"EULER TOTIENT PHI VALUE FOR "<<i<<" IS "<<a[i]<<endl;
    cout<<endl;*/
    x=0;
    for(ll i=1;i<n;i++)
    {
        for(ll j=2*i;j<=n;j+=i)
        {
            sumphi[j]+=(i*a[j/i]); //coz i sabka divisor hain na  toh saari pos par i as a divisor add hoga
        }
    }
        for(int i=1;i<=n;i++)
            sumphi[i]+=sumphi[i-1];
}

int main() {
ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,n,m;
    eulerSeive(1000001);
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        

        cout<<sumphi[n]<<endl;
    }
}