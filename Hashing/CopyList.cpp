//https://www.interviewbit.com/problems/copy-list/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

void insertNode(RandomListNode *&root, int data) {
    if (root == nullptr) root = new RandomListNode(data);
    else {
        root->next = new RandomListNode(data);
        root = root->next;
    }
}

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *head = nullptr, *curr1 = nullptr, *curr2 = A;
    while (curr2) {
        insertNode(curr1, curr2->label);
        if (head == nullptr) head = curr1;
        curr2 = curr2->next;
    }
    curr1 = head; curr2 = A;
    int idx = 0;
    map <int, RandomListNode*> mp1; // index => address in deeep copy
    map <RandomListNode *, int> mp2; // address => index in given list
    while (curr1) {
        mp1[idx] = curr1;
        mp2[curr2] = idx;
        curr1 = curr1->next;
        curr2 = curr2->next;
        idx++;
    }

    curr1 = head; curr2 = A;
    while (curr2) {
        if (curr2->random == nullptr) {
            curr1->random = nullptr;
        }
        else {
            int index = mp2[curr2->random];
            RandomListNode * ptr = mp1[index];
            curr1->random = ptr;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return head;
}
