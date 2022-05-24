//https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int listLength(ListNode *A) {
    int len = 0;
    while (A) {
        len++;
        A = A->next;
    }
    return len;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if (A == nullptr) return A;
    int n = listLength(A);
    B = min(B, n);
    int shift = n - B;
    ListNode *curr = A, *prev = nullptr;
    for (int i = 0; i < shift; ++i) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr) {
        A = A->next;
    }
    else {
        prev->next = curr->next;
    }
    return A;
}
