#include<bits/stdc++.h>
using namespace std;

long long int isprime(long long int n)
{
	if (n<=1)return 0;
	if(n<=3)return 1;
	if(n%2==0||n%3==0)return 0;
	for(long long int  i=5;i*i<=n;i+=6)
		if(n%(i)==0||n%(i+2)==0)
			return 0;
	return 1;
}


main()
{
	vector<long long int>v;
	long long int n,i,p,j;
	cin>>n;
	if(isprime(n))
	{
		cout<<"1\n"<<n;
		return 0;
	}
	
	for(i=n-1;i>=2;i--)
	{
		if(isprime(i))
		{
			//cout<<i<<" ";
			v.push_back(i);
			break;
		}
	}
	p=n-i;
	for(j=p;j>=2;j--)
	{
		if(isprime(j))
		{
			if(p-j==0)
			{
				//cout<<j;
				v.push_back(j);
				break;
			}
			else
			{
				if(isprime(p-j))
				{
					//cout<<j<<" "<<p-j;
					v.push_back(j);
					v.push_back(p-j);
					break;
				}
			}
		}
	}
	
	cout<<v.size()<<"\n";
	for(i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}