//https://www.interviewbit.com/problems/intersection-of-linked-lists/

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

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    if (A == nullptr or B == nullptr) return nullptr;
    int n = listLength(A), m = listLength(B);
    ListNode *p1 = A, *p2 = B;
    int diff = n - m; // difference between lengths
    if (diff >= 0) {
        for (int i = 0; i < diff; ++i) {
            p1 = p1->next;
        }
    }
    else {
        diff *= -1;
        for (int i = 0; i < diff; ++i) {
            p2 = p2->next;
        }
    }
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
