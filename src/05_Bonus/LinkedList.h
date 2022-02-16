
#ifndef CPPBASICS_LINKEDLIST_H
#define CPPBASICS_LINKEDLIST_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Reverses the LinkedList
 * @param head the starting node.
 * @return the new head of the linked list.
 */
ListNode *reverseList(ListNode *head) {
    // Case: 0, 1
    if (head == nullptr || head->next == nullptr) return head;

    // Case: 2-n
    ListNode *previous = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr) {
        // Set next list before relinking
        next = current->next;
        // Relinking
        current->next = previous;

        // Prepare for next iteration step
        previous = current;
        current = next;
    }

    return previous;
}

/**
 * Merge Two Sorted Lists
 * @param list1 the list sorted linked list with n elements.
 * @param list2 the second sorted linked list with n elements.
 * @return list1 now containing all elements of both lists in a sorted manner.
 */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Use dummy node to avoid edge cases (0,1)
    ListNode dummy(INT_MIN);
    ListNode *tail = &dummy;

    // Traverse both lists at the same time
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    // Append the rest
    if (list1 != nullptr) {
        tail->next = list1;
    } else if (list2 != nullptr) {
        tail->next = list2;
    }

    // Returns dummy.next which is actual starting value
    // Dummy gets deleted then because allocated on stack
    return dummy.next;
}

/**
 * Linked List Cycle (very common!)
 * @param head
 * @return
 */
bool hasCycle(ListNode *head) {
    // 0 case
    if (head == nullptr || head->next == nullptr) return false;

    ListNode *slow = head;
    ListNode *fast = head;

    // Possible because 1 slow cycle == 2 fast cycles if cycle exists
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

/**
 * 876. Middle of the Linked List
 * Slow and fast pointers
 * @param head the start of the linked list.
 * @return the second middle list node.
 */
ListNode *middleNode(ListNode *head) {
    // 0 case
    if (head == nullptr) return head;

    ListNode *slow = head;
    ListNode *fast = head;

    // 1 slow cycle == 2 fast cycles
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/**
 * 19. Remove Nth Node From End of List
 * @param head
 * @param n
 * @return
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy_head = new ListNode(0, head);
    ListNode *slow = dummy_head;
    ListNode *fast = head;

    // Move fast pointer n steps forward
    while (n > 0 && fast != nullptr) {
        fast = fast->next;
        n--;
    }

    // Now move both until fast pointer reaches end of the list
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete node
    slow->next = slow->next->next;

    return dummy_head->next;
}

#endif //CPPBASICS_LINKEDLIST_H
