#include<iostream>
using namespace std;
#define m 1000000007
int main(){
	long int t,n,k,j,l,x,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long int a[n+2];
        long int b[750005]={0};
        long int s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]=1;
        }
        for(i=1;i<=750003;i++)
        {
            if(b[i]>0)
            {
                for(j=2*i;j<=750003;j+=i)
                {
                    if(b[j]>0)
                    {
                        b[j]=(b[j]%m+b[i]%m)%m;
                    }
                }
            }
        }
        for(i=1;i<=750002;i++)
        {
            if(b[i]>0)
            {
                s=(s%m+b[i]%m)%m;
            }
        }
        cout<<s<<endl;
    }
	return 0;
}