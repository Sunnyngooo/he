//ques1
// Implement the probing function using the key offset method where offset = key / listSize + 1

// For example:

// Test	Result
// OpenHash* hashTable = new OpenHash(listSize, keyOffset);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: 28
// Slot 2: Empty
// Slot 3: Empty
// Slot 4: 4
// Slot 5: 59
// Slot 6: 15
// Slot 7: 88
// Slot 8: 17
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(listSize, keyOffset);
// int data[] = {10, 22, 11, 4, 15, 26, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 11
// Slot 3: Empty
// Slot 4: 4
// Slot 5: 59
// Slot 6: 15
// Slot 7: 26
// Slot 8: 17
// Slot 9: 88
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(listSize, keyOffset);
// int data[] = {10, 22, 59, 33, 4, 45, 28, 17, 88};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: 45
// Slot 2: Empty
// Slot 3: 17
// Slot 4: 59
// Slot 5: 4
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 33
// Slot 9: 88
// Slot 10: 10


int keyOffset(int key, int i) {
    //To Do
    int offset = key / listSize + 1; //listSize declare outside listSize = 11;
    return (key + i*offset) % listSize;
}


//ques 2
// Implement the probing function using the double hashing method where h1(k) = k % listSize  and h2(k) = (listSize/2)- (k % (listSize/2))

// For example:

// Test	Result
// OpenHash* hashTable = new OpenHash(listSize, doubleHashing);
// int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: 17
// Slot 2: 88
// Slot 3: 15
// Slot 4: 4
// Slot 5: 59
// Slot 6: 28
// Slot 7: Empty
// Slot 8: Empty
// Slot 9: 31
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(listSize, doubleHashing);
// int data[] = {10, 22, 11, 4, 15, 26, 17, 88, 59};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: Empty
// Slot 2: 88
// Slot 3: Empty
// Slot 4: 11
// Slot 5: 4
// Slot 6: 17
// Slot 7: 59
// Slot 8: 26
// Slot 9: 15
// Slot 10: 10
// OpenHash* hashTable = new OpenHash(listSize, doubleHashing);
// int data[] = {10, 22, 59, 33, 4, 45, 28, 17, 88};
// int size = sizeof(data) / sizeof(int);

// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 22
// Slot 1: 45
// Slot 2: 33
// Slot 3: Empty
// Slot 4: 59
// Slot 5: 4
// Slot 6: 28
// Slot 7: Empty
// Slot 8: 88
// Slot 9: 17
// Slot 10: 10

int doubleHashing(int key, int i) {
    //To Do
    return (key % listSize + i*((listSize/2)- (key % (listSize/2)))) % listSize;
}

// //ques3
// Implement an integer hash (with separate chaining) in class ChainingHash with three following elementary methods:

// - insert: to Insert an integer key into a hash

// - remove: to remove an integer key from a hash if found (print out the values (followed by a comma) compared during searching), otherwise throw exception "Not found!"

// - search: to search a key in hash,print out the values (followed by a comma) compared during searching and return true if found, otherwise return false.

// Assume that there is no duplicate key.

// Initial code:

// class ChainingHash {
// private:
//     int (*hash)(int);
//     list<int> *data;
//     int size;
    
// public:
//     ChainingHash() {
//         throw "Cannot create a hash with no hash function!";
//     }
    
//     ChainingHash(int size, int (*hash)(int)) {
//         this->hash = hash;
//         this->size = size;
//         this->data = new list<int>[size];
//     }
    
//     {{ STUDENT_ANSWER }}
    
//     int count() {
//         int total = 0;
//         for (int i = 0; i < this->size; i++) {
//             total += this->data[i].size();
//         }
//         return total;
//     }
    
//     void dump() {
//         for (int i = 0; i < this->size; i++) {
//             cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
//         }
//     }
// };
// Given some hash function:

// int hashWith11(int key) {
//     return key % 11;
// }
// int hashWith15(int key) {
//     return key % 15;
// }
// int hashWith17(int key) {
//     return key % 17;
// }
// For example:

// Test	Result
// ChainingHash* hashTable = new ChainingHash(11, hashWith11);
// int data[] = {28, 81, 55, 92, 33, 29, 18, 23, 40, 99, 79, 74, 49, 64, 17};
// int size = sizeof(data)/ sizeof(int);
// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// hashTable->dump();
// Slot 0: 3 element(s)
// Slot 1: 1 element(s)
// Slot 2: 1 element(s)
// Slot 3: 0 element(s)
// Slot 4: 2 element(s)
// Slot 5: 1 element(s)
// Slot 6: 2 element(s)
// Slot 7: 3 element(s)
// Slot 8: 1 element(s)
// Slot 9: 1 element(s)
// Slot 10: 0 element(s)
// ChainingHash* hashTable = new ChainingHash(11, hashWith11);
// int data[] = {28, 81, 55, 92, 33, 29, 18, 23, 40, 99, 79, 74, 49, 64, 17};
// int size = sizeof(data)/ sizeof(int);
// for (int i = 0; i < size; i++) {
//     hashTable->insert(data[i]);
// }

// int indices[] = { 1, 5, 7 };
// int indicesSize = sizeof(indices)/ sizeof(int);
// for (int i = 0; i < indicesSize; i++) {
//     hashTable->remove(data[indices[i]]);
// }


// hashTable->dump();
// 92,81,40,18,29,23,Slot 0: 3 element(s)
// Slot 1: 0 element(s)
// Slot 2: 1 element(s)
// Slot 3: 0 element(s)
// Slot 4: 1 element(s)
// Slot 5: 1 element(s)
// Slot 6: 2 element(s)
// Slot 7: 2 element(s)
// Slot 8: 1 element(s)
// Slot 9: 1 element(s)
// Slot 10: 0 element(s)

void insert(int key) {
    int idx = hash(key) % this->size;
    data[idx].push_front(key);
}

void remove(int key) {
    int idx = hash(key) % this->size;
    bool found = false;
        
    for(auto it = data[idx].begin(); it != data[idx].end(); ++it){
        cout << *it << ",";
        if(*it == key){
            data[idx].remove(*it);
            found = true;
            break;
        }
    }
    if(!found)
        throw runtime_error("Not found!");
}

bool search(int key) {
    int idx = hash(key) % this->size;
    for(auto i : data[idx]){
        cout << i << ",";
        if(i == key)
            return true;
    }
    return false;
}

//ques 4
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
