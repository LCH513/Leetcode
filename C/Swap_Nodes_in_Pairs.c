struct ListNode* swapPairs(struct ListNode* head){
    
    //no node or only one node
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    struct ListNode *start = head -> next;
    struct ListNode *temp_head = NULL;   
    struct ListNode *temp_previous = head;   
    
    while(head != NULL && head -> next != NULL){
        temp_previous -> next = head -> next; //the previous node linked to the second node which be changed
        temp_head = head -> next;
        head -> next = temp_head -> next;
        temp_head -> next = head;
        temp_previous = head; //record the previous node
        head = head -> next; // move to next node
    }
    
    return start;
}
