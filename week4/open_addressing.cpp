#include <iostream>
using namespace std;
const int M = 10;
struct HashTable {
    int key[M], value[M];

    HashTable() { for (int i = 0; i < M; i++)
                  key[i] = -1;  }

    int hash(int k) { return k % M; } // O(1)

    void insert(int k, int v) //O(1), xau nhat O(n)
    { 
        int h = hash(k);
        for (int i = 0; i < M; i++) 
        {
            int j = (h + i) % M;
            if (key[j] == k) { value[j] = v;
                               return; }
            if (key[j] == -1) 
            {
                key[j] = k;
                value[j] = v;
                return;
            }
        }
    }
    int get(int k) // O(1), xau nhat O(n)
    { 
        int h = hash(k);
        for (int i = 0; i < M; i++) 
        {
            int j = (h + i) % M;
            
          if (key[j] == -1)
                return -1;

            if (key[j] == k)
                return value[j];
        }
        return -1;
    }
    bool search(int k) //O(1), xau nhat O(n)
    { 
        int h = hash(k);
        for (int i = 0; i < M; i++) 
        {
            int j = (h + i) % M;

            if (key[j] == -1)
                return false;

            if (key[j] == k)
                return true;
        }
        return false;
    }
};

int main() {
    HashTable h;

    h.insert(15, 227);
    h.insert(25, 22);
    h.insert(35, 7);

    cout << h.get(15) << endl;
    cout << h.get(25) << endl;
    cout << h.get(35) << endl;

    return 0;
}
