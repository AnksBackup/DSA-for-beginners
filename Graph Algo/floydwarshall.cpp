#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int al[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            al[i][j]=0;    
        }
    }
    vector<int> visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        al[a][b]=d;
        al[b][a]=d;
    }
    int distance[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(i==j){
                distance[i][j]=0;
            }
            else if(al[i][j])
            distance[i][j]=al[i][j];
            else
            distance[i][j]=INT_MAX;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distance[i][j]=min((distance[i][k]+distance[k][j])%1000000007,distance[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    
}