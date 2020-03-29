void sieve()
{
for(int i = 0;i<=1000000;i++)
p[i] = 1;
for(int i = 2;i<=1000000;i++)
{
if(p[i])
{
for(int j = 2*i;j<=1000000;j+=i)
p[j] = 0;
}
}
// for(int i=2;i<=20;i++)cout<<i<<“ “<<p[i]<<endl;
}
int segmented_sieve(long long a,long long b)
{
sieve();
bool pp[b-a+1];
memset(pp,1,sizeof(pp));
for(long long i = 2;i*i<=b;i++)
{
for(long long j = a;j<=b;j++)
{
if(p[i])
{
if(j == i)
continue;
if(j % i == 0)
pp[j-a] = 0;
}
}
}
int res = 1;
for(long long i = a;i<b;i++)
res += pp[i-a];
return res;
}
