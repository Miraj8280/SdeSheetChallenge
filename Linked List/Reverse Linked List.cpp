#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* prevNode = NULL;
    LinkedListNode<int>* currNode = head;
    LinkedListNode<int>* nextNode = NULL;
    
    while(currNode){
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
