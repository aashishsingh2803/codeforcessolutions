#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>v[100009];
    int n,m,i,j,a,b,color[100009];
    map<int,int >present;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        //cin>>color[i];
        scanf("%d",&color[i]);
        present[color[i]]++;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        //cin>>a>>b;
        v[color[a]].push_back(color[b]);
        v[color[b]].push_back(color[a]);
    }
    int pai[100009]={};
    for(i=1;i<=100009;i++)
    {
        if(present[i]>0)
        {
            map<int,int>hash;
            int cnt=1;
            hash[i]=1;
            for(j=0;j<v[i].size();j++)
            {
                if(hash[v[i][j]]==0)
                {
                    cnt++;
                    hash[v[i][j]]++;
                }
            }
            pai[i]=cnt;
        }
    }
    //cout<<v[1].size()<<" ";
    int ma=0;
    for(i=1;i<=100007;i++)
    {
        ma=max(ma,pai[i]);
    }
    for(i=1;i<=100007;i++)
    {
        if(ma==pai[i])
        {
            cout<<i;//<<" "<<pai[i];
            return 0;
            
        }
    }
    //cout<<" "<<pai[1]<<" ";
	return 0;
}