#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000000

vector<ll > b,c;
ll k;
vector<vector<ll > > multiply(vector<vector<ll > > A,vector<vector<ll > > B){
    vector<vector<ll > > C(k+1,vector<ll > (k+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){
                C[i][j]=(C[i][j]+(A[i][x]*B[x][j])%m)%m;
            }
        }
    }
    /*for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return C;
}
vector<vector<ll > > pow(vector<vector<ll > > T,ll n){//matrix exponentiation
    if(n==1){
        return T;
    }
    //check for both even and odd cases
    if(n&1){//odd
        return multiply(T,pow(T,n-1));
    }
    else{//even 
        vector<vector<ll > > A=pow(T,n/2);
        return multiply(A,A);
    }
}
ll compute(ll n){//answer what is the Nth term
    if(n==0){
        return 0;
    }
    if(n<=k){
        return b[n-1];
    }
    vector<ll > F1(k+1);//make F1 vector of K*1 STEP:1
    for(int i=1;i<=k;i++){
        F1[i]=b[i-1];
    }
    //else you want to make the T matrix indexing from 1  STEP:2
    vector<vector<ll> > T(k+1,vector<ll > (k+1));
    //filling of matrix T
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<k){
                if(j==i+1){//element next to diagonal is 1
                    T[i][j]=1;
                }
                else{
                    T[i][j]=0;
                }
            }
            else{
                T[i][j]=c[k-j];//last row is to be filled in opposite direction
            }
        }
    }
    vector<vector<ll > > M(k+1,vector<ll > (k+1));
    M=pow(T,n-1);                  //STEP:3

    ll res = 0;
    for(int i=1;i<=k;i++){         //STEP:4
        res = (res + (M[1][i]*F1[i])%m)%m;

    }
    return res;
}
int main() {
    ll t,n,x;
    cin>>t;
    while(t--){
        cin>>k;
        for(int i=0;i<k;i++){
            cin>>x;
            b.push_back(x);
        }
        for(int i=0;i<k;i++){
            cin>>x;
            c.push_back(x);
        }
        cin>>n;
        cout<<compute(n)<<endl;
        b.clear();
        c.clear();
    }

}
