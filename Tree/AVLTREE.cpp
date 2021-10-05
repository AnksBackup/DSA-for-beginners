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
struct Tree{
    int data,height;
    struct Tree *left,*right;
};
#define TREE struct Tree
ll height(TREE *root){
    if(root==NULL)
    return 0;
    return root->height;
}
ll getimbalance(TREE *root){
    if(root==NULL)
    return 0;
    return height(root->left)-height(root->right);
}

TREE *leftRotate(TREE *root){
    TREE *rchild=root->right;
    TREE *lchild=rchild->left;
    rchild->left = root;
    root->right = lchild;
    root->height = max(height(root->left),
            height(root->right)) +
            1;
    rchild->height = max(height(rchild->left),
            height(rchild->right)) +
            1;
    return rchild;
}
TREE *rightRotate(TREE *root){
    TREE *lchild=root->left;
    TREE *rchild=lchild->right;
    lchild->right = root;
    root->left = rchild;
    root->height = max(height(root->left),
            height(root->right)) +
            1;
    lchild->height = max(height(lchild->left),
            height(lchild->right)) +
            1;
    return lchild;
}
TREE *insertNode(TREE *root,int key){
    if(root==NULL){
        root=(TREE *)malloc(sizeof(TREE));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        root->height=1;
        return root;
    }
    else if(root->data>key){
        root->left=insertNode(root->left,key);
    }
    else if(root->data<key){
        root->right=insertNode(root->right,key);
    }
    else
        return root;
    root->height=1+max(height(root->left),height(root->right));
    int imbalance=getimbalance(root);
    if(imbalance>1){
        if(key<root->left->data){
            return rightRotate(root);
        }
        else{
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if(imbalance<-1){
        if(key>root->right->data){
            return leftRotate(root);
        }
        else{
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}
TREE *deleteNode(TREE *root,int key){
    if(root==NULL)
    return NULL;
    else if(root->data>key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->data<key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->right==NULL&&root->left!=NULL){
            return root->left;
        }
        else if(root->left==NULL||root->right!=NULL){
            return root->right;
        }
        else{
            TREE *temp=root->right;
            while(temp->left!=NULL)
            temp=temp->left;
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    root->height=1+max(height(root->left),height(root->right));
    int imbalance=getimbalance(root);
    if(imbalance>1){
        if(key<root->left->data){
            return rightRotate(root);
        }
        else{
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if(imbalance<-1){
        if(key>root->right->data){
            return leftRotate(root);
        }
        else{
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}
int main(){
    
}