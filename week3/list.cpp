
#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int a[MAX];
    int n;

    // O(1)
    List() { n = 0;}

    // Kiem tra danh sach rong, O(1)
    bool isEmpty() {return n == 0;}

    // Tra ve so phan tu, O(1)
    int size() {return n;}

    // Truy cap phan tu tai vi tri i, O(1)
    int getNode(int i) { if (i < 0 || i >= n) return -1;
                         return a[i]; }
   
    // Them vao dau, O(n)
    void addFirst(int x) {
        if (n == MAX) return;
        for (int i = n; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = x;
        n++; }

    // Them vao cuoi, O(1)
    void addLast(int x) {
        if (n == MAX) return;
        a[n] = x;
        n++; }

    // Chen x vao vi tri i, O(n)
    void insert(int x, int i) {
        if (n == MAX || i < 0 || i > n) return;
        for (int j = n; j > i; j--)
            a[j] = a[j - 1];
        a[i] = x;
        n++;  }

    // Xoa phan tu dau, O(n)
    int removeFirst() {
        if (isEmpty()) return -1;
        int x = a[0];
        for (int i = 0; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
        return x;    }

    // Xoa phan tu cuoi, O(1)
    int removeLast() {
        if (isEmpty()) return -1;
        n--;
        return a[n];   }

    // Xoa phan tu tai vi tri i, O(n)
    int removeAt(int i) {
        if (i < 0 || i >= n) return -1;
        int x = a[i];
        for (int j = i; j < n - 1; j++)
            a[j] = a[j + 1];
        n--;
        return x;   }

    // Duyet tu dau den cuoi, O(n)
    void printForward() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;    }

    // Duyet tu cuoi ve dau, O(n)
    void printBackward() {
        for (int i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        cout << endl;    }
};

int main() {
    List a;

    a.addFirst(20);
    a.addFirst(10);
    a.addLast(40);
    a.insert(30, 2);

    cout << "Duyet xuoi: ";
    a.printForward();

    cout << "Duyet nguoc: ";
    a.printBackward();

    cout << "Phan tu vi tri 2: " << a.getNode(2) << endl;

    a.removeFirst();
    a.removeLast();
    a.removeAt(1);

    cout << "Sau khi xoa: ";
    a.printForward();

    return 0;
}
