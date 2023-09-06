/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* smaller = malloc(sizeof(struct ListNode));
    smaller -> val = 0;
    struct ListNode* smallerTail = smaller;

    struct ListNode* greater = malloc(sizeof(struct ListNode));
    greater -> val = 0;
    struct ListNode* greaterTail = greater;

    struct ListNode* curr = head;

    while(curr){
        if(curr -> val < x){
            smallerTail -> next = curr;
            smallerTail = smallerTail -> next;
        }
        else{
            greaterTail -> next = curr;
            greaterTail = greaterTail -> next;
        }
        curr = curr -> next;
    }
    greaterTail -> next = NULL;
    smallerTail -> next = greater -> next;
    head = smaller -> next;
    free(greater);
    free(smaller);

    return head;
}
