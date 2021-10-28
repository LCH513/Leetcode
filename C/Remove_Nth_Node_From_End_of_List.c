/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *front = head, *back = head;
    while(front){
        front = front -> next;
        
        //it will terminate in the front of the target node
        if(n-- < 0){
            back = back -> next;
        }
    }
    //if the remove node is the first node
    if(n == 0){
        head = head -> next;
    }
    else{
        back ->next = back -> next -> next;
    }
    return head;
}
