// https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *middle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}


ListNode* Solution::reorderList(ListNode* A) {
    if (A == nullptr) return nullptr;
    ListNode *mid = middle(A);
    ListNode *r = reverseList(mid);
    ListNode *l = A;
    while (l != r) {
        ListNode *nxt = r->next;
        if (r == l->next) // even length case cause selfloop
            r->next = nullptr;
        else r->next = l->next;
        l->next = r;
        l = l->next->next;
        r = nxt;
    }
    return A;
}
/*
1 -> 2 -> 3 -> 4 -> 5 -> 6
1 -> 2 -> 3 -> 4 <- 5 <- 6

*/