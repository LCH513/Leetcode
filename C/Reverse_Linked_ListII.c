/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* record = head, *result = head;
    int i = 1;
    int pos = 0;
    int temp[500];

    while(record){
        if(i >= left && i <= right){
            temp[pos++] = record -> val;
        }
        record = record -> next;
        i++;
    }

    i = 1;

    while(result){
        if(i >= left && i <= right){
            result -> val = temp[--pos];
        }
        result = result -> next;
        i++;
    }
    return head;
}
