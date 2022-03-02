
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
 * 206. Reverse Linked List (easy)
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
        next = current->next;      // Set next list before relinking
        current->next = previous;  // Relinking

        // Prepare for next iteration step
        previous = current;
        current = next;
    }

    return previous;
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
 * 21. Merge Two Sorted Lists (easy)
 * Two Pointer
 * @param list1 the list sorted linked list with n elements.
 * @param list2 the second sorted linked list with n elements.
 * @return listBase now containing all elements of both lists in a sorted manner.
 */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Use dummy node to avoid edge cases (0,1) because head can change
    ListNode dummy(INT_MIN);
    ListNode *tail = &dummy;

    // Traverse both lists at the same time
    while (list1 != nullptr && list2 != nullptr) {
        // Pick list node with smaller value
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        // Iteration step
        tail = tail->next;
    }

    // Append the rest
    if (list1 != nullptr) {
        tail->next = list1;
    } else if (list2 != nullptr) {
        tail->next = list2;
    }

    // Returns dummy.next which is actual head
    // Dummy gets deleted when out of scope because allocated on stack
    return dummy.next;
}


/**
 * 148. Sort List (medium) - Helper function
 * Merge Sort, Two pointer
 * Merges both lists by linking them together.
 * @param list1
 * @param list2
 */
ListNode *merge(ListNode *list1, ListNode *list2) {

    ListNode dummy;
    ListNode *current = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        // Choose smaller one
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    // Append rest
    if (list1 != nullptr) {
        current->next = list1;
    }
    if (list2 != nullptr) {
        current->next = list2;
    }

    return dummy.next;
}

/**
 * 148. Sort List (medium) - Helper function
 * Slow/Fast Two pointer
 * Finds the mid by iterating through the entire list.
 * @param head
 * @return
 */
ListNode *getMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

/**
 * 148. Sort List (medium)
 * @param head
 * @return
 */
ListNode *sortList(ListNode *head) {
    // Base case: 0
    if (head == nullptr || head->next == nullptr) { return head; }

    ListNode *left = head;
    ListNode *right = getMid(head);

    // Splits list
    ListNode *temp = right->next;
    right->next = nullptr;
    right = temp;

    // Recursive steps
    left = sortList(left);
    right = sortList(right);

    // Finally, merge lists
    return merge(left, right);
}

/**
 * 141. Linked List Cycle (easy, very common)
 * Floyd's Tortoise and Hare
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

        // Node is visited twice
        if (slow == fast) return true;
    }

    return false;
}

/**
 * 19. Remove Nth Node From End of List (medium)
 * Slow/Fast Two pointer
 * @param head
 * @param n
 * @return
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy_head(0, head);
    ListNode *slow = &dummy_head;
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

    return dummy_head.next;
}

/**
 * 203. Remove Linked List Elements
 * @param head the head of a linked list.
 * @param val all nodes with corresponding val must be removed
 * @return the new head
 */
ListNode *removeElements(ListNode *head, int val) {
    // 0 case
    if (head == nullptr) { return head; }

    ListNode dummyNode = ListNode(0, head);

    ListNode *previous = &dummyNode;
    ListNode *current = head;

    while (current != nullptr) {
        // Check if remove
        if (current->val == val) {
            previous->next = current->next;
        } else {
            // Only move if nothing removed because current then still exists
            previous = current;
        }

        current = current->next;
    }

    return dummyNode.next;
}

/**
 * 83. Remove Duplicates from Sorted List
 * @param head the head of the linked list.
 * @return a linked list only containing unique values.
 */
ListNode *deleteDuplicates(ListNode *head) {
    // 0,1 case
    if (head == nullptr || head->next == nullptr) { return head; }

    // 2-n case
    // No dummy node required because head never changes
    ListNode *previous = head;
    ListNode *current = head->next;

    while (current != nullptr) {
        if (previous->val == current->val) {
            previous->next = current->next;
        } else {
            previous = current;
        }
        current = current->next;
    }

    return head;
}

#endif //CPPBASICS_LINKEDLIST_H
