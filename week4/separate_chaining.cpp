#include <iostream>
using namespace std;
const int M = 10;
struct Node { int key, value;
              Node *next;
};
struct HashTable {
    Node *a[M];
    HashTable() { for (int i = 0; i < M; i++)
                  a[i] = NULL; }

    int hash(int key) { return key % M; } //O(1)

    void insert(int key, int value) //O(1), xau nhat O(n)
    {
        int k = hash(key);
        Node *p = a[k];

        while (p != NULL) 
        { 
          if (p->key == key) 
            { p->value = value;
                return; }
            p = p->next;
        }

        Node *q = new Node;
        q->key = key;
        q->value = value;
        q->next = a[k];
        a[k] = q;
    }

    int get(int key) //O(1), xau nhat O(n)
    {
        int k = hash(key);
        Node *p = a[k];

        while (p != NULL) 
        {
            if (p->key == key)
                return p->value;
            p = p->next;
        }
        return -1;
    }

    bool search(int key) //O(1), xau nhat O(n)
    {
        int k = hash(key);
        Node *p = a[k];

        while (p != NULL) 
        { if (p->key == key)
                return true;
            p = p->next;
        }
        return false;
    }
};

int main() {
    HashTable h;

    h.insert(15, 100);
    h.insert(25, 200);
    h.insert(35, 300);

    cout << h.get(25) << endl;
    cout << h.search(35) << endl;
    cout << h.search(99) << endl;

    return 0;
}
