/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if(!head){
        return NULL;
    }
    struct ListNode* temp_evenHead = head -> next;
    struct ListNode* temp_even = head -> next;
    struct ListNode* temp_odd = head;
    while(temp_even && temp_even -> next){
        temp_odd -> next = temp_even -> next;
        temp_odd = temp_odd -> next;
        temp_even -> next = temp_odd -> next;
        temp_even = temp_even -> next;
        
    }
    temp_odd -> next = temp_evenHead;
    return head;
    
}
