template <typename E, typename F>
class Pair{
public:
    E val;
    F freq;
    Pair(){}
    Pair(E val, F freq) :  val(val), freq(freq){}
};

template <typename T>
class FrequentSearch{
    Pair<T*,int>* arr;
    int n;
public:
    FrequentSearch(T* arr, int n){
        this->arr = new Pair<T*, int>[n];
        for(int i = 0; i < n; i++){
            this->arr[i] = Pair<T*, int>(arr + i, 0);
        }
        this->n = n;
    }
    ~FrequentSearch(){
        delete[] this->arr;
    }
    void Sort(Pair<T*, int>* arr, int k){
        Pair<T*, int> temp = arr[k];
        int i = k - 1;
        for(; i >= 0 && temp.freq >= arr[i].freq; --i){
            arr[i+1] = arr[i];
        }
        arr[i + 1] = temp;
    }
    bool search(T key){
        for(int i = 0; i < this->n; i++){
            cout << *this->arr[i].val;
            if(*this->arr[i].val == key){
                arr[i].freq++;
                Sort(this->arr, i);
                cout << endl;
                return true;
            }
            cout << ",";
        }
        print();
        return false;
    }
    void print(){
        for(int i = 0; i < n; i++){
            cout << *this->arr[i].val;
                cout << ",";
        }
        cout << endl;
    }
};

// 	Test	Expected	Got	
// int arr[4] = {5,3,4,2};
// int ori[4]; memcpy(ori,arr,sizeof(arr));
// FrequentSearch<int>* x = new FrequentSearch<int>(arr,4);
// x->search(4);
// x->search(2);
// x->search(4);
// x->print();
// cout << (memcmp(arr,ori,sizeof(arr)) == 0);
// 5,3,4
// 4,5,3,2
// 2,4
// 4,2,5,3,
// 1
// 5,3,4
// 4,5,3,2
// 2,4
// 4,2,5,3,
// 1
// int arr[4] = {5,3,4,2};
// int ori[4]; memcpy(ori,arr,sizeof(arr));
// FrequentSearch<int>* x = new FrequentSearch<int>(arr,4);
// x->search(4);
// x->search(2);
// x->search(4);
// x->search(3);
// x->search(2);
// x->print();
// cout << (memcmp(arr,ori,sizeof(arr)) == 0);
// 5,3,4
// 4,5,3,2
// 2,4
// 4,2,5,3
// 4,3,2
// 2,4,3,5,
// 1
// 5,3,4
// 4,5,3,2
// 2,4
// 4,2,5,3
// 4,3,2
// 2,4,3,5,
// 1
// char arr[4] = {'d','b','c','a'};
// int ori[4]; memcpy(ori,arr,sizeof(arr));
// FrequentSearch<char>* x = new FrequentSearch<char>(arr,4);
// x->search('a');
// x->search('b');
// x->search('a');
// x->search('a');
// x->search('c');
// x->print();
// cout << (memcmp(arr,ori,sizeof(arr)) == 0);
// d,b,c,a
// a,d,b
// b,a
// a
// a,b,d,c
// a,c,b,d,
// 1
// d,b,c,a
// a,d,b
// b,a
// a
// a,b,d,c
// a,c,b,d,
// 1