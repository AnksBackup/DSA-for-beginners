#include <iostream>
using namespace std;

class node 
{
    public:
    int val;
    node *next;
    node(int value){
        val=value;
        next=NULL;
    }
};
  void display(node *start){
        node* temp=start;
        while (temp!=NULL)
        {
            cout<< temp->val<<endl;
            temp=temp->next; 
        } }

void insertAtHead(node* &head,int val){
        node* n=new node(val);
        n->next=head;
        head=n;
    }

void insertAtTail(node* &head,int val){
    node* temp=head;
    node* n=new node(val);
    if (temp==NULL)
    {
        head=n;
        return;
    }
    
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}



int main()
{
    node* head=NULL;
    insertAtHead(head,2);
    insertAtHead(head,254);
    insertAtTail(head,45);
    insertAtTail(head,6);
    insertAtTail(head,8);
    display(head);
    return 0;
}
