//https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Listlength(ListNode *head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (A == nullptr) return nullptr;
    int len = Listlength(A);
    B %= len;
    if (B == 0) B = len;
    int shift = len - B;
    ListNode *head2 = A, *prev = nullptr;;
    for (int i = 0; i < shift; ++i) {
        prev = head2;
        head2 = head2->next;
    }
    if (prev == nullptr) return A;
    prev->next = nullptr;
    ListNode *last = head2;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = A;
    return head2;
}
