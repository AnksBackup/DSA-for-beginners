#include<bits/stdc++.h>
using namespace std;
int n,m;
bool dfs(int i,vector<int> al[],vector<int> visited){
        visited[i]=1;
        for(int j :al[i]){
            if(visited[j]==2){
                continue;
            }
            if(visited[j]==1){
                return true;
            }
            if(dfs(j,al,visited)){
                return true;
            }
        }
    visited[i]=2;
    return false;
}
bool find_cycle(vector<int> v[]){
    vector<int> visited(n+1,0);
    stack<int> s;
    for(int i=1;i<=n;i++){
        if(visited[i]==0)
        if(dfs(i,v,visited)){
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    vector<int> al[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        al[a].push_back(b);
    }
    cout<<find_cycle(al);
}