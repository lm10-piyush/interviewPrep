//https://www.interviewbit.com/problems/sort-binary-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int countZeros(ListNode *head) {
    int zeros = 0;
    while (head) {
        zeros += !head->val;
        head = head->next;
    }
    return zeros;
}
ListNode* Solution::solve(ListNode* A) {
    int zeros = countZeros(A);
    ListNode *head = A;
    for (int i = 0; i < zeros; ++i) {
        head->val = 0;
        head = head->next;
    }
    while (head) {
        head->val = 1;
        head = head->next;
    }
    return A;
}
