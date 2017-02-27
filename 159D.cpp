#include <iostream>
using namespace std;
int main()
{
        string s;
        bool tt[2005][2005]={};
        long long int dp[2005][2005]={},i,j,k,sum=0;
    
        cin>>s;
        for(i=0;i<s.length();i++)
        {
            for(j=0;j<s.length();j++)
            {
                dp[i][j]=1;
                if(i==j)
                    tt[i][j]=true;
            }
        }
        sum=(s.length())*(s.length()-1)/2;
        //cout<<sum<<"\n";
        for(i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]+=dp[i][i]+1;
                tt[i][i+1]=true;
                //sum+=4;
                //cout<<sum<<" ";
            }
            else
            {
                dp[i][i+1]+=dp[i][i];
                tt[i][i+1]=false;
            }
        }
        //cout<<"\n";
        for(i=2;i<s.length();i++)
        {
            for(j=0,k=i;k<s.length();j++,k++)
            {
                if(tt[j+1][k-1]==true && s[j]==s[k])
                {
                    dp[j][k]+=dp[j][k-1]+dp[j+1][k]-dp[j+1][k-1];
                    tt[j][k]=true;
                }
                else
                {
                    dp[j][k]+=dp[j][k-1]+dp[j+1][k]-dp[j+1][k-1]-1;
                }
            }
            
        }
            //cout<<"\n";
        /*for(i=0;i<s.length();i++)
        {
            for(j=0;j<s.length();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        for(i=0;i<s.length()-1;i++)
        {
            for(j=i+1;j<s.length();j++)
            {
                if(tt[i][j]==true)
                {
                    //sum+=dp[0][i-1]+dp[j+1][s.length()-1];
                    sum+=i+dp[j+1][s.length()-1];
                    
                }
            }
  
        }
        
    cout<<sum;
    
    
    return 0;
}