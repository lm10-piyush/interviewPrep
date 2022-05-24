//https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverseL(ListNode *head, ListNode *last, ListNode *prev) {
    while (head != last) {
        ListNode *nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

ListNode* Solution::solve(ListNode* A, int B) {
    if (A == nullptr) return A;
    ListNode *head = A, *prev = nullptr;
    while (head != nullptr) {
        ListNode *nxt = head;
        for (int i = 1; i < B; ++i) {
            nxt = nxt->next;
        }
        ListNode *h = reverseL(head, nxt->next, nxt->next);
        if (prev) prev->next = h;
        else A = h;
        prev = head;
        head = head->next;
        //skipping the B nodes
        for (int i = 0; i < B and head; ++i) {
            prev = head;
            head = head->next;
        }
    }
    return A;
}
