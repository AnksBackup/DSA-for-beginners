#include<bits.stdc++.h>
using namespace std;

/*
What is Priority Queue?
Priority queues are a type of container adapters, 
specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non increasing order 
(hence we can see that each element of the queue has a priority {fixed order}).
*/


// Implementation of Priority Queue using STL

int main()
{
	priority_queue<int,vector<int>> dcpq;	// decreasing order priority queue
	priority_queue<int,vector<int>, greater<int>> inpq;	// increasing order priority queue
	
	int arr[10];
	
	for(int i=0; i<10; i++){
		cin>>arr[i];
		dcpq.push(arr[i]);
		inpq.push(arr[i]);
	}
	
	cout<<"Increasing order : ";
	while(!inpq.empty()){
		cout<<inpq.top()<<" ";
		inpq.pop();
	}
	
	cout<<endl;
	
	cout<<"Decreasing order : ";
	while(!dcpq.empty()){
		cout<<dcpq.top()<<" ";
		dcpq.pop();
	}
  	
	cout<<endl;
}
