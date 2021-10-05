#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> al[n+1];
    vector<int> visited(n+1,0),distance(n+1,INT_MAX),paths(n+1,0);
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        al[a].push_back({b,d});
        al[b].push_back({a,d});
    }
    distance[1]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()){
        int a=q.top().second;
        int d=q.top().first;
        q.pop();
        if(visited[a]==1)
        continue;
        visited[a]=1;
        for(pair<int,int> i :al[a]){
            int j=i.first;
            if(i.second-d>distance[j])
            {
                distance[j]=i.second-d;
                q.push({-distance[j],j});
                paths[j]=a;
            } 
        }
    }
    cout<<distance[n-1]<<endl;
    vector<int> a;
    int k=n-1;
    while(k!=0){
        a.push_back(k);
        k=paths[k];
    }
    for(int i: a){
        cout<<i<<" ";
    }
}