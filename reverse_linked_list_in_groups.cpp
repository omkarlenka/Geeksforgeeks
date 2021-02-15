//
//  reverse_linked_list_in_groups.cpp
//
//  Created by omlenka on 15/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

/*
 Reverse a linked list
 The input list will have at least one element
 Return the node which points to the head of the new LinkedList
 Node is defined as
 struct node
 {
 int data;
 struct node* next;
 
 node(int x){
 data = x;
 next = NULL;
 }
 
 }*head;
 */
typedef struct node Node;

Node* reverseUtil(Node* head, int k){
    if(head == NULL || k == 1)
        return head;
    Node* start = head;
    Node* prev = head;
    Node* curr = head->next;
    Node* res = NULL;
    
    int count = 1;
    
    while(prev && curr){
        Node* tmp = curr->next;
        curr->next = prev;
        if(count == k-1){
            res = curr;
            start->next = reverseUtil(tmp, k);
            return res;
        }
        else{
            prev = curr;
            curr = tmp;
            count++;
        }
    }
    start->next = NULL;
    res = prev;
    return res;
}

struct node *reverse (struct node *head, int k)
{
    // Complete this method
    
    Node* res = reverseUtil(head, k);
    
    return res;
}
