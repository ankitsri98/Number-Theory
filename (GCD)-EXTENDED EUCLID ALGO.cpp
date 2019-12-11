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

int main()
{
	int a,b;
	cin>>a>>b;
	triplet ans=extendedEuclid(a,b);
	cout<<ans.gcd<<endl;
	cout<<ans.x<<endl;
	cout<<ans.y<<endl;
}
