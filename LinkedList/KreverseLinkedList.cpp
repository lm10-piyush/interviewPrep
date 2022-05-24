//https://www.interviewbit.com/problems/k-reverse-linked-list/

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

ListNode* Solution::reverseList(ListNode* A, int B) {
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
    }
    return A;
}


/*
1 2 3 4 5 6 7 8 9
3 2 1 4 5 6 7 8 9
3 2 1 6 4 5 7 8 9
*/