#include<bits/stdc++.h>
using namespace std;
class node{
public:
     int data;
     node* next;
     
     node(int d){
          data = d;
          next = NULL;
     }
};

void insertAtHead(node * &head,int data){
     node * n = new node(data);
     n->next = head;
     head = n;
}

void insertAtTail(node*&head, int data){
     node * n = new node(data);
     node* temp = head;
     if(head==NULL)
     {
          insertAtHead(head,data);
          return ;
     }
     while(temp->next!= NULL){
          temp = temp->next;
     }    
     temp->next = n;
}

node* check(node* head)
{
      node* temp = head;
      node* prev = NULL;
      unordered_map<int,int> h;
      while(temp)
      {
            int x = temp->data;
          
            if(h.count(x))
            {
                  prev->next = NULL;
                  break;
            }
            else
            h[x]=1;
            prev = temp;
            temp = temp->next;
            
      }
      return head;
}

void print(node* head)
{
      while(head)
      {
            cout<<head->data<<" ";
            head = head->next;
      }
}
int main(){
     int n,x;
     node * head = NULL;
     while(scanf("%d",&x))
     {
           if(x!=-1)
          insertAtTail(head,x);
          else
          break;
     }
     head = check(head);
     print(head);
}
