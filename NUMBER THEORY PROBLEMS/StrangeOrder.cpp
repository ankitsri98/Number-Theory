#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n,x,z,y;
    cin>>n;
    int prime[n+1]={0};
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(prime[j]==0)
                    prime[j]=i;
            }
        }
    }
    /*for(int i=1;i<=20;i++)
        cout<<prime[i]<<" ";
    cout<<endl;*/
    vector<int > v;
    int a[n+2]={0};
    for(int i=n;i>=1;i--)
    {
        if(a[i]!=0)
            continue;
        if(i==1)
        {
            cout<<1<<" ";
            continue;
        }
        //FOR THIS I FIND ITS PRIME FACTORS INSERT ITS MULTIPLES IN A vector
        x=prime[i];  //least prime factor
        v.clear();
       
        y=i;
        while(y!=1)
        {

            for(int j=i;j>=1;j=j-x)
            {
                if(a[j]!=1)
                {
                    a[j]=1; v.push_back(j);    
                }
                else
                    continue;
            }
            //cout<<y<<" "<<x<<endl;
            while(y%x==0)
            {
                y=y/x;
            }
            x=prime[y];
        }
        sort(v.rbegin(),v.rend());
        for(auto it:v)
        {
            cout<< it <<" ";
        }
        v.clear();
        
    }
    
}

/*
//----SEIVE--------
    for(int i=2;i*i<=2000001;i++)
    { 
        for(int j=i*i;j<=2000001;j+=i)
        { 
            if(sieve[j]>i)
            { 
                sieve[j]=i; 
                          
            } 
        } 
    }
*/