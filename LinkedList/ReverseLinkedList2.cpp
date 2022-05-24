//https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverseList(ListNode *head, ListNode *last, ListNode *prev) {
    while (head != last) {
        ListNode *nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (A == nullptr) return A;
    // [p1, p2] => points to start and end of the segment which should be reversed
    ListNode *p1 = A, *prev = nullptr, *p2 = A;
    B--; C--;
    while (B-- > 0) {
        prev = p1;
        p1 = p1->next;
    }
    while (C-- > 0) {
        p2 = p2->next;
    }
    ListNode *h = reverseList(p1, p2->next, p2->next);
    if (prev) prev->next = h;
    else A = h; //when B = 1
    return A;
}
/*
A : [ 1 -> 2 -> 3 ]
B : 1
C : 2
*/