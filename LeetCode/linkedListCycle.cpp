// Floyd's cycle finding algorithm
// Two pointers; one slow the other fast. The slower pointer meets faster pointer if cycle exists. One they meet, start moving each other by 1
// when they meet again, that is the begin of the cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* ptr1 = head, *ptr2 = head;
		while (ptr2 != NULL && ptr2->next != NULL) {
			if (ptr1 == ptr2) {
				return true;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		return false;        
    }
};
