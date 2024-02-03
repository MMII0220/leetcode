#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Duplicate found, delete the next node
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            // Move to the next node
            current = current->next;
        }
    }

    return head;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);

    ListNode* deduplicatedList1 = deleteDuplicates(list1);
    printList(deduplicatedList1);

    // Example 2
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(2);
    list2->next->next->next = new ListNode(3);
    list2->next->next->next->next = new ListNode(3);

    ListNode* deduplicatedList2 = deleteDuplicates(list2);
    printList(deduplicatedList2);

    return 0;
}
