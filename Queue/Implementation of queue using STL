#include<iostream>
#include<queue>
using namespace std;
void display(queue<int>q1)
{
           cout<<"QUEUE:";
           while(!q1.empty())
           {
                      cout<<q1.front()<<" ";
                      q1.pop();
           }
           cout<<endl;
}
int main()
{
           queue<int>q;
           for(int i=0;i<5;i++)
           {
                      q.push(i+1);
           }
           display(q);
           cout<<"Last element of queue:"<<q.back();
           cout<<"\nNo of elements present in a queue:"<<q.size();
           return 0;
}
