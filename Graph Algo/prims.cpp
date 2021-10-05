#include <bits/stdc++.h>
using namespace std;

int prims(vector<int> g[],int V)
{
    vector<int> dist(V,INT_MAX);
    dist[0]=0;
    vector<bool> fin(V,false);

    int ans=0;

    for(int count=0;count<V;count++)
    {
        int u=-1;
        for(int i=0;i<V;i++)
        {
            if(!fin[i] && (u==-1 || dist[i]<dist[u]))
            u=i;
        }
        fin[u]=true;
        ans+=dist[u];
        //cout<<ans<<endl;
        for(int v=0;v<V;v++)
        {
            if(g[u][v]!=0 && !fin[v])
            {
                //cout<<v<<dist[v]<<" ";
                dist[v]=min(g[u][v],dist[v]);
            }
            
        }
        //cout<<endl;
    }
    return ans;
}


int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

    int V;
    cin>>V;

    vector<int> g[V];

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            int x=0;
            cin>>x;
            g[i].push_back(x);
        }
    }

    cout<<prims(g,V)<<endl;;

}