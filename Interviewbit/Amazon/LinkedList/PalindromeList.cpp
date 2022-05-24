//https://www.interviewbit.com/problems/palindrome-list/

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

int Solution::lPalin(ListNode* A) {
    if (A == nullptr) return 1;
    ListNode *mid = middle(A);
    ListNode *r = reverseList(mid);
    ListNode *l = A;
    while (r != nullptr) {
        if (l->val != r->val) return 0;
        l = l->next;
        r = r->next;
    }
    return 1;
}

/*
1 -> 2 -> 3 -> 4 -> 5 -> 6
1 -> 2 -> 3 -> 4 <- 5 <- 6
1 -> 2 -> 3 -> 4 -> 5
1 -> 2 -> <- 3 <- 4 <- 5
[ 1 1 6 4 1 ]
*/
