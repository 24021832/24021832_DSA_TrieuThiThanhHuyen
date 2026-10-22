
#include <iostream>
using namespace std;

// Cau truc mot nut
struct Node {
    int data;
    Node *next;};

// Cau truc danh sach lien ket don
struct LinkedList {
    Node *head;

    // Khoi tao danh sach rong, O(1)
    LinkedList() {  head = NULL;  }

    // Kiem tra danh sach rong, O(1)
    bool isEmpty() { return head == NULL;  }

    // Them nut vao dau, O(1)
    void addFirst(int x) {
        Node *p = new Node;
        p->data = x;
        p->next = head;
        head = p;  }

    // Them nut vao cuoi, O(n)
    void addLast(int x) {
        Node *p = new Node;
        p->data = x;
        p->next = NULL;

        if (isEmpty()) {  head = p;
                          return; }
        Node *q = head;
        while (q->next != NULL) {  q = q->next;  }
        q->next = p;   }

    // Lay gia tri tai vi tri i, O(n)
    int getNode(int i) {
        if (i < 0) {
    cout << "Vi tri khong hop le!\n";
    return -1;}
        Node *p = head;
        int dem = 0;
        while (p != NULL && dem < i) {  p = p->next;
                                        dem++;    }
        if (p == NULL) {    cout << "Vi tri khong hop le!\n";
                            return -1;   }
        return p->data;  }

    // Chen x vao vi tri i, O(n)
    void insert(int i, int x) {
        if (i < 0) {    cout << "Vi tri khong hop le!\n";
                        return;    }

        if (i == 0) {   addFirst(x);
                        return;   }
        Node *q = head;
        int dem = 0;
        while (q != NULL && dem < i - 1) {   q = q->next;
                                             dem++;  }

        if (q == NULL) {   cout << "Vi tri khong hop le!\n";
                           return;   }
        Node *p = new Node;
        p->data = x;
        p->next = q->next;
        q->next = p;    }

    // Xoa nut dau, O(1)
    void removeFirst() {
        if (isEmpty()) {     cout << "Danh sach rong!\n";
                             return;     }
        Node *p = head;
        head = head->next;
        delete p; }

    // Xoa nut cuoi, O(n)
    void removeLast() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node *q = head;
        while (q->next->next != NULL) {
            q = q->next;    }
        delete q->next;
        q->next = NULL;
    }

    // Xoa nut tai vi tri i, O(n)
    void removeAt(int i) {
        if (i < 0 || isEmpty()) {
            cout << "Khong xoa duoc!\n";
            return; }
        if (i == 0) {
            removeFirst();
            return;   }
        Node *q = head;
        int dem = 0;
        while (q->next != NULL && dem < i - 1) {
            q = q->next;
            dem++; }
        if (q->next == NULL) {
            cout << "Vi tri khong hop le!\n";
            return;}
        Node *p = q->next;
        q->next = p->next;
        delete p;
    }
    // Duyet tu dau den cuoi, O(n)
    void printForward() {
        Node *p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    // Duyet nguoc bang de quy, O(n)
    void printReverse(Node *p) {
        if (p == NULL) {
            return;
        }
        printReverse(p->next);
        cout << p->data << " ";
    }

    // Duyet tu cuoi ve dau
    // Time: O(n), Space phu: O(n)
    void printBackward() {
        printReverse(head);
        cout << endl;
    }
    // Giai phong bo nho cac nut, O(n)
    void clear() {
        while (head != NULL) {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }
    // Tu dong giai phong bo nho khi doi tuong ket thuc, O(n)
    ~LinkedList() {
        clear();
    }
};
int main() {
    LinkedList ds;

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

    cout << "Phan tu vi tri 0: "
         << ds.getNode(0) << endl;

    cout << "Duyet nguoc: ";
    ds.printBackward();

    return 0;
}
