#include <bits/stdc++.h>
using namespace std;

string s[500009];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    long long int n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    
    for(i=n-2;i>=0;i--)
    {
        string s1;
        for(j=0;j<min(s[i].length(),s[i+1].length());j++)
        {
            if(s[i][j]==s[i+1][j])
            {
                //cout<<s[i][j];
                s1=s1+s[i][j];
            }
            else
            {
                if(s[i][j]<s[i+1][j])
                {
                    for(k=j;k<s[i].length();k++)
                    {
                        s1=s1+s[i][k];
                        //cout<<s[i][k];
                    }
                        
                    break;    
                }
                else
                {
                    break;
                }
            }
        }
        //cout<<"\n";
        s[i]=s1;
    }
    for(i=0;i<n;i++)
    {
        cout<<s[i]<<"\n";
    }
    return 0;
}