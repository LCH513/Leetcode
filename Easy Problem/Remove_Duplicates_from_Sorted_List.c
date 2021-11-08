struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp =  head;
    while(head != NULL && head -> next != NULL){
        if(head -> val == head -> next -> val){
            head -> next = head -> next -> next;
        }
        else{
            head = head -> next;
        }
    }
    return temp;
}
