#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    int c=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)//for the case of perfect square
            c+=1;
            else
            c+=2;
        }
    }
    if(c==2){  //in this case for 1 and that number is included i.e prime
    //cout<<n<<endl;
    return true;}
    else
    return false;
}
int main()
{
    int c,n,i,j,k,x;
    c=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(isprime(i))
        {
            c++;
        }
    }
    cout<<c<<endl;
}
