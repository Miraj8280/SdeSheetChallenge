#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st(arr.begin(), arr.end());
    int maxLen = 0;
    
    for(int it : st){
        if(st.count(it - 1)) continue;
        int currLen = 1;
        
        while(st.count(it + currLen)){
            currLen++;
        }
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}
