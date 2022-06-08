#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    /*
    // Iterative Approach
    
    if(!first) return second;
    if(!second) return first;
    
    Node<int>* head = NULL, *tail = NULL;
    if(first -> data < second -> data){
        head = tail = first;
        first = first -> next;
    }
    else{
        head = tail = second;
        second = second -> next;
    }
    while(first && second){
        if(first -> data < second -> data){
            tail -> next = first;
            tail = tail -> next;
            first = first -> next;
        }
        else{
            tail -> next = second;
            tail = tail -> next;
            second = second -> next;
        }
    }
    if(first){
        tail -> next = first;
        first = first -> next;
    }
    if(second){
        tail -> next = second;
        second = second -> next;
    }
    return head;
    */
    
    // Recursive Approach
    if(!first) return second;
    if(!second) return first;
    
    if(first -> data < second -> data){
        first -> next = sortTwoLists(first -> next, second);
        return first;
    }
    else{
        second -> next = sortTwoLists(first, second -> next);
        return second;
    }
}
