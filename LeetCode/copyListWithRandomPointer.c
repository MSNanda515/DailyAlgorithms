
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* newHead = NULL;
    struct Node* ptr = NULL, *ptr1 = NULL, *tempPtr = NULL;
    ptr = head;
    int n = 0;
    while (ptr != NULL) {
        n += 1;
        tempPtr = (struct Node*)malloc(sizeof(struct Node));
        tempPtr->val = ptr->val;
        tempPtr->next = ptr->next;
        tempPtr->random = NULL;
        ptr->next = tempPtr;
        ptr = tempPtr->next;
    }

    // assign the random pointers
    ptr = NULL;
    while (ptr != NULL) {
        if (ptr->random != NULL) {
            ptr->next->random = ptr->random->next;
        }
        ptr = ptr->next->next;
    }
    
    ptr1 = head;
    ptr = head;
    while (ptr != NULL) {
        if (ptr1 == NULL) {
            newHead = ptr->next;
            ptr1 = newHead;
            tempPtr = ptr->next->next;
        } else {
            tempPtr = ptr->next->next;
            ptr1->next = ptr->next;
        }
        ptr->next = tempPtr;
        ptr = tempPtr;
    }    

    return newHead;
}
