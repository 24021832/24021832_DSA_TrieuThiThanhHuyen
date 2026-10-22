#include <iostream>
using namespace std;

const int MAX = 100;

// LIST
struct List {
    int a[MAX];
    int n;

    List() { n = 0; }

    bool isEmpty() { return n == 0; } // O(1)
    int size() { return n; }          // O(1)

    void addFirst(int x) {            // O(n)
        if (n == MAX) return;
        for (int i = n; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = x;
        n++; }

    void addLast(int x) {             // O(1)
        if (n == MAX) return;
        a[n++] = x;  }

    int removeFirst() {                // O(n)
        if (isEmpty()) return -1;
        int x = a[0];
        for (int i = 0; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
        return x;   }

    int getNode(int i) {               // O(1)
        if (i < 0 || i >= n) return -1;
        return a[i];  }
};

// LINKED LIST
struct Node {
    int data;
    Node *next;};

struct LinkedList {
    Node *head, *tail;
    int n;

    LinkedList() {
        head = tail = NULL;
        n = 0; }

    bool isEmpty() { return head == NULL; } // O(1)
    int size() { return n; }                // O(1)

    void addFirst(int x) {                  // O(1)
        Node *p = new Node;
        p->data = x;
        p->next = head;
        head = p;
        if (tail == NULL) tail = p;
        n++;   }

    void addLast(int x) {                   // O(1)
        Node *p = new Node;
        p->data = x;
        p->next = NULL;

        if (tail == NULL)
            head = tail = p;
        else {
            tail->next = p;
            tail = p;  }
        n++;
    }

    int removeFirst() {                     // O(1)
        if (isEmpty()) return -1;
        Node *p = head;
        int x = p->data;
        head = head->next;
        delete p;
        n--;
        if (head == NULL) tail = NULL;
        return x;  }

    int getNode(int i) {                    // O(n)
        if (i < 0 || i >= n) return -1;
        Node *p = head;
        for (int j = 0; j < i; j++)
            p = p->next;
        return p->data;  }
};
// QUEUE = LIST
struct QueueList {
    List danhSach;

    bool isEmpty() { return danhSach.isEmpty(); } // O(1)
    int size() { return danhSach.size(); }        // O(1)

    void enqueue(int x) {  danhSach.addLast(x);}// O(1)

    int dequeue() { return danhSach.removeFirst(); }   // O(n)

    int peek() {  return danhSach.getNode(0); }// O(1)
};

// QUEUE = LINKED LIST
struct QueueLinkedList {
    LinkedList danhSachLienKet;

    bool isEmpty() { return danhSachLienKet.isEmpty(); } // O(1)

    int size() { return danhSachLienKet.size();} // O(1)

    void enqueue(int x) { danhSachLienKet.addLast(x); } // O(1)

    int dequeue() { return danhSachLienKet.removeFirst();  } // O(1)

   int peek() {if (isEmpty()) return -1;
              return danhSachLienKet.head->data;} // O(1)
};

int main() {
    QueueList q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Queue List: " << q1.peek() << endl;
    cout << "Dequeue: " << q1.dequeue() << endl;

    QueueLinkedList q2;
    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);
    cout << "Queue Linked List: " << q2.peek() << endl;
    cout << "Dequeue: " << q2.dequeue() << endl;

    return 0;
}
