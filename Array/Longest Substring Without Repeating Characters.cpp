#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char, int> mp;
    int len = 0;
    
    for(int left = 0, right = 0; right < input.size(); ++right){
        if(mp.find(input[right]) != mp.end()){
            left = max(left, mp[input[right]] + 1);
        }
        mp[input[right]] = right;
        len = max(len, right - left + 1);
    }
    return len;
}
