#include<bits/stdc++.h>
using namespace std;

//extended euclid algorithm which is application of DIOPHANTINE equation

class triplet{
	public:
			int x;
			int y;
			int gcd;
};

triplet extendedEuclid(int a, int b)
{
	if(b==0)
	{
		triplet ans;
		ans.gcd=a;
		ans.x=1;
		ans.y=0;
		return ans;
	}
	triplet smallans=extendedEuclid(b,a%b);
	triplet ans;
	ans.gcd=smallans.gcd;
	ans.x=smallans.y;
	ans.y=smallans.x-smallans.y*(a/b);//used formula derived from eq'
	return ans;
}
int mminverse(int a,int m)//FINDING INVERSE
{
	triplet ans=extendedEuclid(a,m);
	return ans.x;
}
int main()
{
	int a,m;
	cin>>a>>m;
	int x=mminverse(a,m);
	cout<<"MULTIPLICATIVE MODULAO INVERSE "<<x<<endl;
}
