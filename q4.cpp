template <typename T>
bool jumpsearch(T arr[], int n, T k, int j){
    int i = 0;
    for(; i < n; i += j){
        cout << arr[i] << ",";
        if(arr[i] == k)
            return 1;
        if(i == 0 && arr[i] > k){
            return false;
        }
        if(arr[i] > k){
            int idx = i - j + 1;
            while(idx < i){
                cout << arr[idx] << ",";
                if(arr[idx] == k)
                    return true;
                else if(arr[idx] > k)
                    return false;
                idx++;
            }
        }
    }
    i = i - j + 1;
    for(; i < n; i++){
        cout << arr[i] << ",";
        if(arr[i] == k)
            return true;
        if(arr[i] > k)
            return false;
    }
    return false;
}   

// Test	                                                                            Expected	            
// int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};     3,21,35,56,69,72,75,1   
// std::cout<<jumpsearch(arr,23,75,5);

// int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};     3,21,5,12,16,20,0      
// std::cout<<jumpsearch(arr,23,17,5);

// int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};     3,21,35,56,69,72,75,0
// std::cout<<jumpsearch(arr,23,78,5);

// int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
// std::cout<<jumpsearch(arr,23,1,5);
// 3,0
// int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
// std::cout<<jumpsearch(arr,23,59,5);
// 3,21,35,56,69,57,58,62,0
