#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int> al[],vector<int> &col,vector<int> visited,int maxclr){
    int clrused=1;
    for(int i=1;i<col.size();i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int a=q.front();q.pop();
                visited[a]=1;
                for(int j:al[a]){
                    if(col[a]==col[j])
                    col[j]++;
                    clrused=max(clrused,max(col[a],col[j]));
                    if(clrused>maxclr)
                    return false;
                    if(!visited[j])
                    q.push(j);
                }
            }
            
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> al[n+1],col(n+1,1),visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int maxclr;
    cin>>maxclr;
    cout<<bfs(al,col,visited,maxclr);
}