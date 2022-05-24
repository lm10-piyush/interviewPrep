// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void insertNode(ListNode * &head, int data) {
    ListNode *p = new ListNode(data);
    if (head == nullptr) head = p;
    else {
        head->next = p;
        head = head->next;
    }
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if (A == nullptr) return B;
    if (B == nullptr) return A;
    ListNode *head = nullptr, *curr = nullptr;
    int carry = 0;
    while (A or B or carry) {
        int sum = carry;
        if (A) {
            sum += A->val;
            A = A->next;
        }
        if (B) {
            sum += B->val;
            B = B->next;
        }
        carry = sum / 10;
        sum %= 10;
        insertNode(curr, sum);
        if (head == nullptr) head = curr;
    }

    return head;
}
