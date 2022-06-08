#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	//    Write your code here.
    Node* slow = head, *fast = head;
    
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) break;
    }
    if(!(fast && fast -> next)) return NULL;
    
    while(head != slow){
        head = head -> next;
        slow = slow -> next;
    }
    return head;
}
