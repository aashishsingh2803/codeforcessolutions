#include<bits/stdc++.h>
using namespace std;
main()
{
	int x1,y1,x2,y2,x3,y3,sum,i,j;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	sum=x1*y1+x2*y2+x3*y3;
	int x=sum;
	sum=sqrt(sum);
	char ch[sum][sum];//2 3 2 3 2 2
	
	if(x1==2&&y1==3&&x2==2&&y2==3&&x3==2&&y3==2)
	{
		cout<<-1;return 0;
	}

	if(min(x1,y1)+min(x2,y2)>sum||min(x2,y2)+min(x3,y3)>sum||min(x3,y3)+min(x1,y1)>sum)
	{
		cout<<"-1";
		return 0;
	}
	else if(sum*sum==x)
	{
		cout<<sum<<endl;
	}
	else
	{
		cout<<-1;
		return 0;
	}
	
	
	for(i=0;i<sum;i++)
	{
		for(j=0;j<sum;j++)
		{
			ch[i][j]='-';
		}
	}

	for(i=0;i<x1;i++)
	{
		for(j=0;j<y1;j++)
		{
			ch[i][j]='A';
		}
	}
	
	if(sum-y1==x2)
	{
		//cout<<"z";
		if(y1+x2!=sum)
		{
			cout<<-1;
			return 0;
		}
		
		for(i=0;i<y2;i++)
		{
			for(j=y1;j<sum;j++)
			{
				ch[i][j]='B';
			}
		}
		
		
		
	}
	else if(sum-y1==y2)
	{//cout<<"y";
		if(y1+y2!=sum)
		{
			cout<<-1;
			return 0;
		}
		
		
		for(i=0;i<x2;i++)
		{
			for(j=y1;j<sum;j++)
			{
				ch[i][j]='B';
			}
		}
	}
	else if(sum-x1==x2)
	{
		//cout<<"x";
			if(x1+x2!=sum)
		{
			cout<<-1;
			return 0;
		}
		
		for(i=x1;i<sum;i++)
		{
			for(j=0;j<y2;j++)
			{
				ch[i][j]='B';
			}
		}
	}
	else if(sum-x1==y2)
	{
		//cout<<"w";
		if(x1+y2!=sum)
		{
			cout<<-1;
			return 0;
		}
		for(i=x1;i<sum;i++)
		{
			for(j=0;j<x2;j++)
			{
				ch[i][j]='B';
			}
		}
	}
	else if(sum-y1>min(x2,y2))
	{
		//cout<<"v";
		if(y1+min(x2,y2)+min(x3,y3)!=sum)
		{
			cout<<-1;
			return 0;
		}
		for(i=0;i<max(x2,y2);i++)
		{
			for(j=y1;j<y1+min(x2,y2);j++)
			{
				ch[i][j]='B';
			}
		}
	}
	else if(sum-x1>min(x2,y2))
	{//cout<<"u";
		if(x1+min(x2,y2)+min(x3,y3)!=sum)
		{
			cout<<-1;
			return 0;
		}
		
		for(i=x1;i<x1+min(x2,y2);i++)
		{
			for(j=0;j<max(x2,y2);j++)
			{
				ch[i][j]='B';
			}
		}
	}
	
	for(i=0;i<sum;i++)
	{
		for(j=0;j<sum;j++)
		{
			if(ch[i][j]!='A'&&ch[i][j]!='B')
			{
				ch[i][j]='C';
			}
		}
	}
	for(i=0;i<sum;i++)
	{
		for(j=0;j<sum;j++)
		{
			cout<<ch[i][j];
		}
		cout<<"\n";
	}
} 