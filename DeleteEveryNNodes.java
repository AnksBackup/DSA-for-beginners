/*

    Following is the Node class already written for the Linked List

    class LinkedListNode<T> {
        T data;
        LinkedListNode<T> next;
    
        public LinkedListNode(T data) {
            this.data = data;
        }
    }

*/



public class Solution {
	
	public static LinkedListNode<Integer> skipMdeleteN(LinkedListNode<Integer> head, int M, int N) {
		//Your code goes here
        if(head==null){
            return head;
        }
        int count=0;
        if(M==0){
            return null;
        }
        if(N==0){
            return head;
        }
        LinkedListNode<Integer> temp = head;
        LinkedListNode<Integer> skip = null;
        while(temp!=null){
            while(count<M-1){
                if(temp.next==null){
                    return head;
                }
                temp=temp.next;
                count++;
            }
            
            skip=temp.next;
            count=0;
            while(count<N-1){
                if(skip.next==null){
                    break;
                }
                skip=skip.next;
                count++;
            }
            temp.next=skip.next;
            temp=temp.next;
            count=0; 
        }
        return head;
        
	}
}
