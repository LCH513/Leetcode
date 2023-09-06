/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp -> next = head;
    struct ListNode* pre = temp;
    struct ListNode* curr = head; 
    while(curr != NULL){
        while(curr -> next != NULL && pre -> next -> val == curr -> next -> val){
            curr = curr -> next;
        }
        if(pre -> next == curr){
            pre = pre -> next;
        }
        else{
            pre -> next = curr -> next;
            curr = curr -> next;
        }
    }
    return temp -> next;
}
