#include<bits/stdc++.h>
using namespace std;
struct triplet{
    int a,b,d;
};
bool compare(triplet a,triplet b){
    return a.d<b.d;
}
int link[100000],size[100000];
int find(int x){
    while(x!=link[x])
    x=link[x];
    return x;
}
bool same(int a,int b){
    return find(a)==find(b);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(size[a]<size[b])
    swap(a,b);
    size[a]+=size[b];
    link[b]=a;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<triplet> al,spT;
    for(int i=1;i<=n;i++){
        link[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        al.push_back({a,b,d});
    }
    sort(al.begin(),al.end(),compare);
    int sum=0;
    for(int i=0;i<m;i++){
        if(!same(al[i].a,al[i].b)){
            unite(al[i].a,al[i].b);
            spT.push_back(al[i]);
            sum+=al[i].d;
        }
        else
        continue;
    }
    cout<<sum<<endl;
    for(int i=0;i<spT.size();i++){
        cout<<spT[i].a<<" "<<spT[i].b<<" "<<spT[i].d<<endl;
    }
}