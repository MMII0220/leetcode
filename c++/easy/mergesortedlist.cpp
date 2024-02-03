#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify the code
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If one of the lists is not empty, append it to the merged list
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    // Save the head of the merged list and delete the dummy node
    ListNode* mergedList = dummy->next;
    delete dummy;

    return mergedList;
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
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);

    ListNode* mergedList1 = mergeTwoLists(list1, list2);
    printList(mergedList1);

    // Example 2
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;

    ListNode* mergedList2 = mergeTwoLists(list3, list4);
    printList(mergedList2);

    // Example 3
    ListNode* list5 = nullptr;
    ListNode* list6 = new ListNode(0);

    ListNode* mergedList3 = mergeTwoLists(list5, list6);
    printList(mergedList3);

    return 0;
}
