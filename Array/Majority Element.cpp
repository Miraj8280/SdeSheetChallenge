#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int count = 0;
    int majority;
    
    for(int i = 0; i < n; ++i){
        if(count == 0)
            majority = arr[i];
        if(majority == arr[i])
            count++;
        else 
            count--;
    }
    
    count = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == majority)
            count++;
    }
    return (count > n / 2) ? majority : -1;
}
