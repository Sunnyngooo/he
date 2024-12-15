#include <iostream>
#include <math.h>
using namespace std;
enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};



class OpenBucketHash{

private:
    STATUS_TYPE* status;
    int* data;
    int size; // number of bucket
    int bucketSize; // size of each bucket
    
public:

    OpenBucketHash() {
        throw "Cannot create a hash with no size!";
    }
    OpenBucketHash(int size, int bucketSize) {
        this->size = size; this->bucketSize=bucketSize;
        this->data = new int[size*bucketSize];
        this->status = new STATUS_TYPE[size*bucketSize];
        for (int i = 0; i < size*bucketSize; i++) {
            this->status[i] = NIL;
        }
    }
int insert(int key){
    int bucketIdx = key % size;
    int start = bucketIdx * bucketSize;
    //check duplicate
    for(int i = 0; i < bucketSize * size; i++){
        int slot = start + i;
        if(status[slot] == NON_EMPTY && data[slot] == key)
            throw runtime_error("Duplicate key: "+to_string(key));
    }
    for(int i = 0; i < bucketSize; i++){
        int slot = start + i;
        if(slot >= bucketSize * size)
            break;
        if(status[slot] == NIL || status[slot] == DELETED){
            data[slot] = key;
            status[slot] = NON_EMPTY;
            return slot;
        }
        if(i == bucketSize - 1){
            bucketIdx = (bucketIdx + 1)%size;
            start = bucketIdx * bucketSize;
            i = -1;
        }
    }
    throw runtime_error("Overflow!");
}
void remove(int key){
    int bucketIdx = key % size;
    int start = bucketIdx * bucketSize;
    for(int i = 0; i < bucketSize; i++){
        int slot = start + i;
        if(slot >= bucketSize * size)
            break;
        cout << data[slot] << ",";
        if(status[slot] == NON_EMPTY && data[slot] == key){
            status[slot] = DELETED;
            return;
        }
        if(status[slot] == NIL)
            throw runtime_error("Not found!");
        if(i == bucketSize - 1){
            bucketIdx = (bucketIdx + 1)%size;
            start = bucketIdx * bucketSize;
            i = -1;
        }
    }
    throw runtime_error("Not found!");
}
int search(int key){
    int bucketIdx = key % size;
    int start = bucketIdx * bucketSize;
    for(int i = 0; i < bucketSize; i++){
        int slot = start + i;
        if(status[slot] == NON_EMPTY)
            cout << data[slot] << ",";
        if(status[slot] == NON_EMPTY && data[slot] == key){
            return slot;
        }
        if(status[slot] == NIL)
            return -1;
        if(i == bucketSize - 1){
            bucketIdx = (bucketIdx + 1)%size;
            start = bucketIdx * bucketSize;
            i = -1;
        }
    }
    return -1;
}
    void dump() {
        for (int i = 0; i < this->size*this->bucketSize; i++) {
            if (this->status[i] != NON_EMPTY)
                cout << "Slot " << i << ": Empty" << endl;
            else cout << "Slot " << i << ": " << this->data[i] << endl;
        }
    }
};

int main(){
OpenBucketHash* hashTable = new OpenBucketHash(5, 2);
int data[] = {10, 22, 77, 28, 17, 88, 59};
int size = sizeof(data) / sizeof(int);
try {
   for (int i = 0; i < size; i++) {
    hashTable->insert(data[i]);
   }
   hashTable->remove(77);
   hashTable->insert(66);
   hashTable->dump();
} catch (const exception& e) {
   cout << e.what();
}
    return 0;
}