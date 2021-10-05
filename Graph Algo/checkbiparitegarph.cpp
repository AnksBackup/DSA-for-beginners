#include <bits/stdc++.h>
using namespace std;
//#define ll long long int;
bool dfs(vector<int> adj[],vector<int> &col,vector<int> &visited,int n){
    for(int i:adj[n]){
        if(visited[i]==0){
            visited[i]=1;
            col[i]!=col[n];
            if(!dfs(adj,col,visited,i))
            return false;
        }
        else if(col[i]==col[n])
        return false;
    }
    return true; 
}


int main()
{  
    int t;
    cin >> t;
    for(int j=0;j<t;j++){

    int n, e;
    cin >> n >> e;
    int a, b;
    vector<int> adj[n+1],col(n+1),visited(n+1,0);
    for (int i = 0; i < e; i++)
    {    
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1]=1;
    col[1]=0;
    bool ans;
    if(dfs(adj,col,visited,1))
    ans=false;
    else 
    ans=true;
    if(ans) cout << "Scenario #" << j+1 << ":" << endl << "No suspicious bugs found!" << endl;
    else cout << "Scenario #" << j+1 << ":" << endl << "Suspicious bugs found!" << endl;
    }
}