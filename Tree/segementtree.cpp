#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(int i=a;i<n;i++)
#define vi vector<ll>
#define vp vector<pi>
#define mpi unordered_map<ll,ll>
#define si unordered_set<ll>
#define str string
#define st stack<ll> 
#define q queue<ll> 
#define pi pair<ll,ll>
#define mps unordered_map<str,ll>
#define mod 1000000007
int sum(vi a,int i,int j){
    i+=a.size()/2;
    j+=a.size()/2;
    int s=0;
    while(i<=j){
        if(i%2)
        s+=a[i++];
        if(j%2==0)
        s+=a[j--];
        i/=2;
        j/=2;
    }
    return s;
}
int main(){
    ll n;
    cin>>n;
    vi a(2*n,0);
    f(i,0,n){
        cin>>a[i+n];
    }
    for(int i=n-1;i>=1;i--){
        a[i]=a[2*i+1]+a[2*i];
    }
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<sum(a,5,5);
}