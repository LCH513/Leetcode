/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1 || !l2){
        if(!l1){
            return l2;
        }
        else{
            return l1;
        }
    }
    if(l1 -> val > l2 -> val){
        l2 -> next = mergeTwoLists(l1, l2 -> next); // the small one become node head
        return l2;
    }
    else{
        l1 -> next = mergeTwoLists(l1 -> next, l2);
        return l1;
    }
}
