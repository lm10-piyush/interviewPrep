
//https://www.interviewbit.com/problems/lru-cache/

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

Node *head, *tail;
int cap;

void insertBeg(Node * &head, int key, int val) {
    if (head == nullptr) {
        head = new Node(key, val);
        tail = head;
    }
    else {
        Node *t = new Node(key, val);
        t->next = head;
        head->prev = t;
        head = t;
    }
}

void deleteNode(Node *&head, Node *node) {
    if (node == head) {
        if (head == tail)
            tail = nullptr;
        head = head->next;
        delete node;
    }
    else {
        if (tail == node)
            tail = tail->prev;
        Node *p = node->prev;
        if (p != nullptr)
            p->next = node->next;
        if (node->next != nullptr) {
            Node *n = node->next;
            n->prev = p;
        }
        delete node;
    }
}

unordered_map <int, Node *> cache;

LRUCache::LRUCache(int capacity) {
    head = nullptr;
    tail = nullptr;
    cap = capacity;
    cache.clear();
}

int LRUCache::get(int key) {
    if (!cache.count(key)) return -1;
    int value = cache[key]->val;
    set(key, value);
    return head->val;
}

void LRUCache::set(int key, int value) {
    if (cache.count(key)) {
        Node *address = cache[key];
        deleteNode(head, address);
        insertBeg(head, key, value);
        cache[key] = head;
    }
    else {
        if ((int)cache.size() == cap) {
            cache.erase(tail->key);
            deleteNode(head, tail);
            insertBeg(head, key, value);
            cache[key] = head;
        }
        else {
            insertBeg(head, key, value);
            cache[key] = head;
        }
    }
}

/*
Use doubly linked list to store the the order of data in most recent to least recent nodes.
map will store the key -> address of linkedlist node.
https://www.youtube.com/watch?v=xDEuM5qa0zg

https://pastebin.com/MRvY0EXX     (another solution)
*/