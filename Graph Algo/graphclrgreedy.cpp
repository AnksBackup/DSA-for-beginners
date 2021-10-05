#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> al[],int n,int k){
    vector<int> result(n+1,-1),available(k+1,0);
    result[1]=1;
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j :al[i]){
            if(result[j]!=-1)
            available[result[j]]=1;
        }
        int cr;
        flag=false;
        for(cr=1;cr<=k;cr++){
            if(available[cr]==0){
                flag=true;
                break;
            }
        }
        if(flag==false){
            break;
        }
        result[i]=cr;
        for(int j :al[i]){
            if(result[j]!=-1){
                available[result[j]]=0;
            }
        }
    }
    if(flag==false){
        cout<<"notpossible\n";
    }
    else 
    cout<<"possible\n";
    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
    }
}
int main(){
    int n,m,k;
    cin>>n>>m;
    vector<int> al[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    cin>>k;
    // k=n if for finding max color in graph; 
    solution(al,n,k);
    
}