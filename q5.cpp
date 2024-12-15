#include <iostream>
#include <stdexcept>
#include <string>

enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};

class OpenHash {
private:
    int (*hp)(int, int);
    STATUS_TYPE* status;
    int* data;
    int size;
    
public:
    OpenHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    OpenHash(int size, int (*hp)(int, int)) {
        this->hp = hp;
        this->size = size;
        this->data = new int[size];
        this->status = new STATUS_TYPE[size];
        for (int i = 0; i < size; i++) {
            this->status[i] = NIL;
        }
    }

    ~OpenHash() {
        delete[] data;
        delete[] status;
    }

    int insert(int key){
        for(int i = 0; i < this->size; i++){
            if(data[i] == key)
                throw std::runtime_error("Duplicate key: " + std::to_string(key));
        }
        for(int i = 0; i < this->size; i++){
            int idx = hp(key, i);
            if(status[idx] == NIL || status[idx] == DELETED){
                this->data[idx] = key;
                status[idx] = NON_EMPTY;
                return idx;
            }
        }
        throw std::runtime_error("Overflow!");
    }

    void remove(int key){
        for(int i = 0; i < this->size; i++){
            int idx = hp(key, i);
            if(status[idx] == NON_EMPTY && data[idx] == key){
                status[idx] = DELETED;
                return;
            }
        }
        throw std::runtime_error("Not found!");
    }

    int search(int key){
        for(int i = 0; i < this->size; i++){
            int idx = hp(key, i);
            if(status[idx] == NON_EMPTY && data[idx] == key){
                return idx;
            } 
            else if(status[idx] == NIL)
                break;
        }
        return -1;
    }

    void dump() {
        for (int i = 0; i < this->size; i++) {
            if (this->status[i] != NON_EMPTY)
                std::cout << "Slot " << i << ": Empty" << std::endl;
            else
                std::cout << "Slot " << i << ": " << this->data[i] << std::endl;
        }
    }
};

// Hash functions provided
int linearProbing(int key, int i) {
    return ((key % 11) + i) % 11;
}

int quadraticProbing(int key, int i) {
    return ((key % 11) + i + 3 * i * i) % 11;
}

int doubleHashing(int key, int i) {
    int h1 = key % 11;
    int h2 = 1 + (key % 10);
    return (h1 + i * h2) % 11;
}

int main() {
    OpenHash* hashTable = new OpenHash(11, linearProbing);
    int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    int size = sizeof(data) / sizeof(int);
    for (int i = 0; i < size; i++) {
        try {
            hashTable->insert(data[i]);
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    hashTable->dump();
    delete hashTable;
    return 0;
}

// Test	Expected	Got	
// OpenHash* hashTable = new OpenHash(11, linearProbing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: 88
// Slot 2: Empty
// Slot 3: Empty
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 17
// Slot 8: 59
// Slot 9: 31
// Slot 10: 10
// Slot 0: 22
// Slot 1: 88
// Slot 2: Empty
// Slot 3: Empty
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 17
// Slot 8: 59
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 88
// Slot 3: 17
// Slot 4: 4
// Slot 5: Empty
// Slot 6: 28
// Slot 7: 59
// Slot 8: 15
// Slot 9: 31
// Slot 10: 10
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 88
// Slot 3: 17
// Slot 4: 4
// Slot 5: Empty
// Slot 6: 28
// Slot 7: 59
// Slot 8: 15
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, doubleHashing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 59
// Slot 3: 17
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 88
// Slot 8: Empty
// Slot 9: 31
// Slot 10: 10
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 59
// Slot 3: 17
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 88
// Slot 8: Empty
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, doubleHashing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->remove(22);
// hashTable->dump();
// Slot 0: Empty
// Slot 1: Empty
// Slot 2: 59
// Slot 3: 17
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 88
// Slot 8: Empty
// Slot 9: 31
// Slot 10: 10
// Slot 0: Empty
// Slot 1: Empty
// Slot 2: 59
// Slot 3: 17
// Slot 4: 4
// Slot 5: 15
// Slot 6: 28
// Slot 7: 88
// Slot 8: Empty
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, doubleHashing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->remove(22);
// cout << hashTable->search(88);
// 7
// 7
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);
// try {
//   for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
//   }
// hashTable->remove(22);
// hashTable->insert(77);
// hashTable->dump();
// } catch (const std::exception&  e) {
//    cout << e.what();
// }
// Slot 0: 77
// Slot 1: Empty
// Slot 2: Empty
// Slot 3: 88
// Slot 4: 15
// Slot 5: Empty
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 59
// Slot 9: 17
// Slot 10: 10
// Slot 0: 77
// Slot 1: Empty
// Slot 2: Empty
// Slot 3: 88
// Slot 4: 15
// Slot 5: Empty
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 59
// Slot 9: 17
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);
// try {
// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }
// hashTable->remove(22);
// cout << hashTable->search(22);
// } catch (const std::exception& e) {
//  cout << e.what();
// }
// -1
// -1
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 77, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);
// try {
//    for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
//    }
//    hashTable->remove(77);
//    hashTable->insert(66);
//    hashTable->dump();
// } catch (const exception& e) {
//    cout << e.what();
// }
// Slot 0: 22
// Slot 1: Empty
// Slot 2: Empty
// Slot 3: 88
// Slot 4: 66
// Slot 5: Empty
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 59
// Slot 9: 17
// Slot 10: 10
// Slot 0: 22
// Slot 1: Empty
// Slot 2: Empty
// Slot 3: 88
// Slot 4: 66
// Slot 5: Empty
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 59
// Slot 9: 17
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 77, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);
// try {
//    for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
//    }
//    hashTable->remove(77);
//    hashTable->insert(88);
//    hashTable->dump();
// } catch (const exception& e) {
//    cout << e.what();
// }
// Duplicate key: 88
// Duplicate key: 88
// OpenHash* hashTable = new OpenHash(11, quadraticProbing);
// int data[] = {10, 22, 77, 28, 17, 22, 59};
// int size = sizeof(data) / sizeof(int);
// try {
//    for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
//    }
//    hashTable->dump();
// } catch (const exception& e) {
//    cout << e.what();
// }
// Duplicate key: 22
// Duplicate key: 22
