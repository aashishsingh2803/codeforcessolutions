#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,m,k,sum[5005],dp[5005][5005],i,j,a[5005];
	cin>>n>>m>>k;
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
	    cin>>a[i];
	    sum[i]=sum[i-1]+a[i];
	}
	for(i=0;i<=n;i++)
	{
	    dp[i][0]=0;dp[0][i]=0;
	}
	for(i=1;i+m<=n+1;i++)
	{
	    for(j=1;j<=k;j++)
	    {
	        if(i-1+j*m<=n)
	        {
	            dp[i][j]=max(dp[i][j-1]+sum[(i-1)+j*m]-sum[(i-1)+(j-1)*m],dp[i-1][j]);
	           /* if(dp[i-1][j]==118)
	                cout<<i<<" "<<j<<" ";*/
	        }
	        else
	        {
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	        //cout<<dp[i][j]<<" ";
	    }
	    //cout<<endl;
	}
	cout<<dp[n-m+1][k];
	
	
	
	return 0;
}