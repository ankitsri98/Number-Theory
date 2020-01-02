#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll m;
ll f[100002];
void fact()
{
    ///f[100002]={0};
    f[0]=1;
    f[1]=1;f[2]=2;
    for(int i=3;i<=100000;i++)
    {
        f[i]=(i%m)*(f[i-1]%m)%m;
        //cout<<f[i]<<endl;
    }
}

int main() 
{
    ll t,n,x;
    
    cin>>t; 
    while(t--)
    {
        
        cin>>n>>m;
        fact();
        if(n<m)
        {
            cout<<f[n]<<endl;
        }
        else 
        {
            ll a=n/m;
            if(a%2==0)
            {
                x=n%m;
                //cout<<x<<endl;
                cout<<f[x]<<endl;
            }
            else
            {
                x=(m-1)*(f[n%m]);
                cout<<x%m<<endl;
            }            
        }

    }
}