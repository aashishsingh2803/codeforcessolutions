#include<bits/stdc++.h>
#define MAX 1000007
#define MIN -1000007
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long int ll;
typedef long double ld;
ll visit[3009]={},parent[3009]={};
vector<ll>v[3009];
set<ll>v1;
void dfs(int x)
{
	visit[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!visit[v[x][i]])
		{
			parent[v[x][i]]=x;
			dfs(v[x][i]);
		}	
		else
		{
			if(v[x][i]!=parent[x])
				v1.insert(v[x][i]);
		}
	}
}


int main()
{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 ll n,m,i,j,l,a,b;
 
 cin>>n;
 for(i=0;i<n;i++)
 {
 	cin>>a>>b;
 	v[a].push_back(b);
 	v[b].push_back(a);
 }
 

 for(i=1;i<=n;i++)
 {
 	 parent[1]=i;
 	memset(visit,0,sizeof(visit));
 	 dfs(i);
 }
 /*for(set<ll>::iterator itr=v1.begin();itr!=v1.end();itr++)
 {
 	cout<<*itr<<" ";
 }*/
 ll dis[3009];
 for(i=1;i<=n;i++)
 	dis[i]=4000;
 queue<ll>q;
for(set<ll>::iterator itr=v1.begin();itr!=v1.end();itr++)
{
	dis[*itr]=0;
	q.push(*itr);
	memset(visit,0,sizeof(visit));
	visit[*itr]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<v[x].size();i++)
		{
			if(!visit[v[x][i]])
			{
				visit[v[x][i]]=1;
				dis[v[x][i]]=min(dis[x]+1,dis[v[x][i]]);
				q.push(v[x][i]);
			}
		}
	}
}
for(i=1;i<=n;i++)
{
	cout<<dis[i]<<" ";
}
  
 
return 0;
}