#include<bits/stdc++.h>
using namespace std;

//FIND PRIMES IN [1,N]  USING EXTRA SPACE WITH TIME COMPLEXITY O(N LOG (LOG (N)))
int seive(int n)
{
    int c=0;
    bool a[n+1];
    for(int i=0;i<=n+1;i++){
    a[i]=true;
    }
    a[0]=a[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(a[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)// MAKE FALSE ALL THE MULTIPLES OF NUMBERS WHOSE POSITION IS INITIALLY TRUES
            {
                a[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]==true)
        c++;
    }
    return c;
}
int main()
{
    int c,n,i,j,k,x;
    c=0;
    cin>>n;
    if(seive(n))
    cout<<seive(n)<<endl;
    else
    cout<<c<<endl;
}
