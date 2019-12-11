#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    //special case
    if(a<b)
    {
        return gcd(b,a);
    }
    if(b==0)
        return a;
    
    return gcd(b,a%b);
    /*
    or YOU CAN ALSO USE IN BUILD FUNCTION FOR GCD WHICH FOLLOW EUCLID ALGORITHM
    return __gcd(a,b);
    */
}

