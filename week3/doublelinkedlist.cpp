#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;};

// Cau truc danh sach lien ket kep
struct DoublyLinkedList {
    Node *head;
    Node *tail;

    // Khoi tao danh sach rong: O(1)
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;   }

    // Kiem tra danh sach rong: O(1)
    bool isEmpty() {   return head == NULL; }

    // Them nut vao dau: O(1)
    void addFirst(int x) {
        Node *p = new Node;
        p->data = x;
        p->prev = NULL;
        p->next = head;

        if (isEmpty()) {
            head = p;
            tail = p;
        } else {
            head->prev = p;
            head = p;   }
    }

    // Them nut vao cuoi: O(1)
    void addLast(int x) {
        Node *p = new Node;
        p->data = x;
        p->next = NULL;
        p->prev = tail;

        if (isEmpty()) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;    }
    }

    // Lay gia tri tai vi tri i: O(n)
    int getNode(int i) {
        if (i < 0) {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }
        Node *p = head;
        int dem = 0;
        while (p != NULL && dem < i) {
            p = p->next;
            dem++;
        }
        if (p == NULL) {
            cout << "Vi tri khong hop le!\n";
            return -1;    }
        return p->data;
    }

    // Chen x vao vi tri i: O(n)
    void insert(int i, int x) {
        if (i < 0) {
            cout << "Vi tri khong hop le!\n";
            return;     }
        if (i == 0) {
            addFirst(x);
            return;    }
        Node *q = head;
        int dem = 0;
        while (q != NULL && dem < i - 1) {
            q = q->next;
            dem++;       }
        if (q == NULL) {
            cout << "Vi tri khong hop le!\n";
            return;   }
        if (q == tail) {
            addLast(x);
            return;    }
        Node *p = new Node;
        p->data = x;
        p->prev = q;
        p->next = q->next;
      
        q->next->prev = p;
        q->next = p;
    }

    // Xoa nut dau: O(1)
    void removeFirst() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;       }

        Node *p = head;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;   }
        delete p;
    }

    // Xoa nut cuoi: O(1)
    void removeLast() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;      }
        Node *p = tail;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;       }
        delete p;
    }

    // Xoa nut tai vi tri i: O(n)
    void removeAt(int i) {
        if (i < 0 || isEmpty()) {
            cout << "Vi tri khong hop le!\n";
            return;      }
        Node *p = head;
        int dem = 0;

        while (p != NULL && dem < i) {
            p = p->next;
            dem++;    }
        if (p == NULL) {
            cout << "Vi tri khong hop le!\n";
            return;  }
        if (p == head) {
            removeFirst();
            return;     }
        if (p == tail) {
            removeLast();
            return;        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }

    // Duyet tu dau den cuoi: O(n)
    void printForward() {
        Node *p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;        }
        cout << endl;
    }
    // Duyet tu cuoi ve dau: O(n)
    void printBackward() {
        Node *p = tail;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->prev;        }
        cout << endl;
    }

    // Giai phong bo nho: O(n)
    void clear() {
        while (head != NULL) {
            Node *p = head;
            head = head->next;
            delete p;       }
        tail = NULL;
    }
    // Huy danh sach: O(n)
    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList ds;

    ds.addLast(10);
    ds.addLast(20);
    ds.addLast(30);

    cout << "Danh sach ban dau: ";
    ds.printForward();

    ds.addFirst(5);
    cout << "Sau khi them dau: ";
    ds.printForward();

    ds.insert(2, 15);
    cout << "Sau khi chen vi tri 2: ";
    ds.printForward();

    ds.removeFirst();
    cout << "Sau khi xoa dau: ";
    ds.printForward();

    ds.removeLast();
    cout << "Sau khi xoa cuoi: ";
    ds.printForward();

    ds.removeAt(1);
    cout << "Sau khi xoa vi tri 1: ";
    ds.printForward();

    cout << "Phan tu vi tri 0: " << ds.getNode(0) << endl;

    cout << "Duyet nguoc: ";
    ds.printBackward();

    return 0;
}
