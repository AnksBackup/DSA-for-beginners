#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(int i=a;i<n;i++)
#define vi vector<ll>
#define mpi unordered_map<ll>
#define si unordered_set<ll>
int key;
stack<int> st;
vi temp;
void dfs(vi al[],vi &v,vi &s,vi &e,int i){
    v[i]=1;
    s[i]=key++;
    for(int j:al[i]){
        if(v[j]==0){
            dfs(al,v,s,e,j);
        }
    }
    e[i]=key++;
    st.push(i);
}
void dfs2(vi al[],vi &v,int i){
    temp.push_back(i);
    v[i]=1;
    for(int j: al[i]){
        if(v[j]==0)
        dfs2(al,v,j);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vi al[n+1],visited(n+1,0),v(n+1,0),alt[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        al[a].push_back(b);        
        alt[b].push_back(a);
    }
    key=1;
    vi s(n+1),e(n+1);
    f(i,1,n+1)
    if(visited[i]==0)
    dfs(al,visited,s,e,i);
    // f(i,1,n+1){
    //     cout<<s[i]<<"--"<<e[i]<<endl;
    // }
    vector<vi> ans;
    while(!st.empty()){
        int i=st.top();st.pop();
        if(v[i]==0){
            dfs2(alt,v,i);
            ans.push_back(temp);
            temp.clear();
        }
    }
    f(i,0,ans.size()){
        for(int j:ans[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}