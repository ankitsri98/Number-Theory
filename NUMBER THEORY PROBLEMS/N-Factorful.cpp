#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//FIND PRIMES IN [1,N]  USING EXTRA SPACE WITH TIME COMPLEXITY O(N LOG (LOG (N)))
ll  a[1000006];
ll arr[14][1000006];
void seive(ll n)
{
    
    for(ll i=0;i<=n+1;i++){
    a[i]=0;
    }
   
    for(ll j=2;j<=n;j+=2)
    {
        a[j]+=1;
    }
    for(ll i=3;i<=n;i+=2)
    {
        if(a[i]==0)
        {
            for(ll j=i;j<=n;j+=i)// MAKE count ALL THE MULTIPLES OF NUMBERS WHOSE POSITION IS INITIALLY 0            {
                a[j]+=1;
            
        }
    }
   /* for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<i<<endl;
    }
   cout<<endl;*/
        for(ll i=1;i<=12;i++)
    	{
    		for(ll j=1;j<=1000003;j++)
    		{
    			arr[i][j]=0;
    		}
    	}
    	for(ll i=1;i<=12;i++)
    	{
    		for(ll j=1;j<=1000003;j++)
    		{
                ll k=a[j];
    			if(k==i)
                {
                    arr[i][j]=arr[i][j-1]+1;
                }
                else
                    arr[i][j]=arr[i][j-1];
    		}
    	}
    	/*for(int i=1;i<=10;i++)
    	{
    		for(int j=1;j<=10;j++)
    		{
    			cout<<arr[i][j]<<" ";
    		}
            cout<<endl;
    	}*/
}
int main()
{
    ll t,c,n,i,j,k,x,d,a,b;
    c=0;
    seive(1000004);
   
    cin>>t;
    while(t--)
    {
    	cin>>a>>b>>d;
    	

        // ALL CALCULATIONS ARE DONE TILL NOW VALUE IS COMPUTED FURTHER
        if(d==0 && a==1)
        {
            cout<<1<<endl;
        }
        else
        {
            x=arr[d][b]-arr[d][a-1]; //A-1 IS DONE COZ THEN ONLY WE'LL GET FROM A TO B 
            cout<<x<<endl;            
        }
        
    }
    
}



