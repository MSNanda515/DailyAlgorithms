// https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1#

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	
};

bool toAddEl(int val, int part, int state) {
    if (state == 0) {
        // smaller values
        return val < part;
    } else if (state == 1) {
        return val == part;
    } else {
        return val > part;
    }
}

struct Node* partition(struct Node* head, int x) {
    // code here
    Node* newHead, *ptr, *ptrNew;
    ptrNew = newHead = NULL;
    int state = 0;
    for (int i = 0; i <= 2; i++) {
        ptr = head;
        while (ptr != NULL) {
            if (toAddEl(ptr->data, x, state)) {
                if (ptrNew == NULL) {
                    // to add head
                    ptrNew = new Node(ptr->data);
                    newHead = ptrNew;
                } else {
                    ptrNew->next = new Node(ptr->data);
                    ptrNew = ptrNew->next;
                }
            }
            ptr = ptr->next;
        }    
        state++;
    }
    return newHead;
}

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}