#include <bits/stdc++.h>
using namespace std;
long long int n,l,r,i,a[100009],b[100009],c[100009],ans[100009],pos[100009],temp,c2[100009],ma=-1000000000000,t;
    vector<pair< long long int , long long int> >v,v1,v2;
int main() {
    
    cin>>n>>l>>r;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
        pos[c[i]]=i;
    }

    for(i=1;i<=n;i++)
    {
        t=max(l,ma+a[pos[i]]);
        //cout<<t<<" ";
        if(t>r)
        {
            cout<<-1;
            return 0;
        }
        ans[pos[i]]=t;
        ma=ans[pos[i]]-a[pos[i]]+1;
        //cout<<ma<<"a ";
    }
    //cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
	return 0;
}