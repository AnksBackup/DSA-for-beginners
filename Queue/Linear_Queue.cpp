#include<stdio.h>
#include<stdlib.h>
#define n 7


int enqueue(int[],int,int);
int dequeue(int[],int,int);
void display(int[],int,int);
void peek(int[],int,int);


int main(){
    int queue[n];
    int front=-1,rear=-1;
    int ch;
    
    do{
        printf("\n1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Display \n");
        printf("4. Peek \n");
        printf("5. Quit \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                rear=enqueue(queue,front,rear);          
            }break;

            case 2:
            {
                front=dequeue(queue,front,rear);
            }break;

            case 3:
            {
                display(queue,front,rear);
            }break;

            case 4:
            {
                peek(queue,front,rear);
            }break;
            
            case 5:
            {
                exit(1);
            }break;

            default:{
                printf("Invalid Choice: \n");
            }
        }
    }while(ch<=5);
}

int enqueue(int queue[],int front, int rear)
{
    int x;
    if(rear==n-1){
        printf("Overflow ");
    }
    else if(front==-1 && rear==-1){
        printf("Enter :");
        scanf("%d",&x);
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else{
        printf("Enter :");
        scanf("%d",&x);
        rear++;
        queue[rear]=x;
    }
    return rear;
}

int dequeue(int queue[],int front, int rear)
{
    int item;
    if(front==-1 && rear==-1){
        printf("Uverflowx");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
        
        printf("Dequeued element is: %d",queue[front]);
    }
    return front;
}

void display(int queue[],int front,int rear){
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Empty queue \n");
    }
    else{
        for(i=front+1;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
    }
}

void peek(int queue[],int front, int rear){
    if(front==-1 && rear==-1){
        printf("Empty");
    }
    else{
        printf("%d",queue[front]);
    }
}
