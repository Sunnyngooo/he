#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
bool binarysearch(T arr[], int left, int right, T k){
    if(left > right)
        return false;
    int mid = (right + left)/2;
    cout << arr[mid] <<",";
    if(arr[mid] == k)
        return true;
    else if(arr[mid] < k)
        return binarysearch(arr, mid + 1, right, k);
    else 
        return binarysearch(arr, left, mid - 1, k);
}

int round1(double a, int b){
    double res = a/b;
    double rem = res -(int)res;
    return res + (rem > 0 ? 1 : 0);
}
template <typename T>
bool dictionarySearch(T arr[], int left, int right, T k){
    if(left > right)
        return false;
    int n = right - left + 1;
    double i =  (k - arr[left])*n;
    int res = left + round1(i, arr[right] - arr[left]) - 1;
    if(res < 0 || res >= n)
        return false;
    cout << arr[res] << ",";
    if(arr[res] == k)
        return true;
    if(arr[res] < k){
        left = res + 1;
        if(left >= n || arr[left] > k)
            return false;
        while(left <= right && arr[left] <= k){
            if(arr[left] == k){
                cout << arr[left] << ",";
                return true;
            }
            else  if(arr[left] > k)
                return false;
            cout << arr[left] << ",";
            left++;
            
        }
    }
    else {
        right = res - 1;
        if(right < 0 || arr[right] < k)
            return false;
        while(left <= right && arr[right] >= k){
            if(arr[right] == k){
                cout << arr[right] << ",";
                return true;
            }
            else if(arr[right] < k)
                return false;
            cout << arr[right] << ",";
            right--;
        }
    }
    return 1;
}
int main(){
    //binary search
    // int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    // std::cout<<binarysearch(arr,0,22,75); //36,58,69,72,75,1

    //dictionary search
    int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    cout << dictionarySearch(arr, 0, 22, 56);
    // double i = (17 - 3)*23;
    // double res = i/(75 - 3);
    // cout << round1(i, 72);

    return 0;
}