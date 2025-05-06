#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int hashTable[TABLE_SIZE];


void initTable() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Folding method: break the key into two 3-digit parts and add
int foldingHash(int key) {
    int part1 = key / 1000;      
    int part2 = key % 1000;      
    int sum = part1 + part2;
    return sum % TABLE_SIZE;
}


void insert(int key) {
    int index = foldingHash(key);
    int startIndex = index;
    
    while(hashTable[index] != -1) {
        
        index = (index + 1) % TABLE_SIZE;

        
        if(index == startIndex) {
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}

// Display hash table
void display() {
    cout << "\nHash Table:" << endl;
    for(int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " --> ";
        if(hashTable[i] != -1)
            cout << hashTable[i];
        else
            cout << "empty";
        cout << endl;
    }
}

int main() {
    initTable();

    // Sample keys
    int keys[] = {123456, 234567, 345678, 456789};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys
    for(int i = 0; i < n; i++) {
        insert(keys[i]);
    }


    display();

    return 0;
}
