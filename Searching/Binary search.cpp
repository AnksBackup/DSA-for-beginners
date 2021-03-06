#include<iostream>
#include<vector>
using namespace std;
int b_search(vector<int>num,int n,int val)
{
           int beg=0,last=n-1;
           while(beg<=last)
           {
                  int mid=(beg+last)/2;
                      if(num[mid]==val)
                                 return 1;
                      else if(val<num[mid])
                                 last=mid-1;
                      else
                                 beg=mid+1;
           }
}
int main()
{
           int n,val,x,val1;
           cout<<"Enter the number of elements:";
           cin>>n;
           vector<int>a(n);
           cout<<"Enter elements:";
           for(int i=0;i<n;i++)
           {
                      cin>>a[i];
           }
           for(int i=0;i<n;i++)
           {
                      for(int j=i+1;j<n;j++)
                      {
                                 if(a[i]>=a[j])
                                 {
                                            val1=a[i];
                                            a[i]=a[j];
                                            a[j]=val1;
                                 }
                      }
           }
           cout<<"Enter the element to be searched:";
           cin>>val;
           x=b_search(a,n,val);
           if(x==1)
                      cout<<"Element is present in the array";
           else
                      cout<<"Element is not present in the array";
           return 0;
}
