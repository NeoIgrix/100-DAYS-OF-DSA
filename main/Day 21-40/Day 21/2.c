struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move one step
        fast = fast->next->next;    // move two steps
    }
    
    return slow;
}