#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool dfs(vector<int> al[],vector<int> &visited,int j){
    visited[j]=1;
    for(int i : al[j]){
        if(visited[i]==2)
        continue;
        if(visited[i]==1){
            return true;
        }
        if(dfs(al,visited,i))
        return true;
    }
    visited[j]=2;
    return false;
}
bool findcycle(vector<int> al[],vector<int> &visited){
    for(int i=1;i<visited.size();i++){
        if(visited[i]==0)
        if(dfs(al,visited,i))
        return true;
    }
    return false;
}
void dfs2(vector<int> al[],vector<int> &visited,int j){
    visited[j]=1;
    for(int i : al[j]){
        if(visited[i]==2)
        continue;
        dfs2(al,visited,i);
    }
    visited[j]=2;
    ans.push_back(j);
    return; 
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> al[n+1],visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        al[a].push_back(b);
    }
    if(findcycle(al,visited))
    cout<<"contain cycle";
    else{
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++){
            if(v[i]==0)
            dfs2(al,v,i);
        }
    }
    for(int i :ans)
    cout<<i<<" ";
}