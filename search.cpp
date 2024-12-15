#include <iostream>
#include <math.h>
using namespace std;

//jump search
int jumpSearch(int* arr, int n, int key){
    cout << n;
    int end = sqrt(n);
    int start = 0;
    while(arr[end] < key && start < n){
        start  = end;
        end += sqrt(n);
        if(end >= n)
            end = n;
    }
    for(int i = start; i < end; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

//binary search
int binSearch(int* arr, int n, int key){
    int left = 0; 
    int right = n - 1;
    
    while(left < right){
        int mid = (right + left)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            right = mid - 1;
        if(arr[mid] > key)
            left = mid + 1;
    }
    return -1;
}

//dictionary search
int dictSearch(int* arr, int n, int key){
    int left = 0;
    int right = n - 1;
    while(left <= right && key >= arr[left] && key <= arr[right]){
        if(left == right){
            if(arr[left] == key)
                return left;
            return -1;
            }
        int p = ((key - arr[left])*(right - left))/ (arr[right] - arr[left]);
        cout << arr[p];
        if(arr[p] == key)
            return p;
        if(arr[p] < key)
            right = p -1;
        else
            left = p + 1;
    }
    return -1;
}
int main(){
    int arr[] = {3,5,12,16,20,21,28,30,32,38,40,41,45,47,50,56,57,58,62,66,69,72,75};
    cout << dictSearch(arr, sizeof(arr)/sizeof(int), 63);
    return 0;
}