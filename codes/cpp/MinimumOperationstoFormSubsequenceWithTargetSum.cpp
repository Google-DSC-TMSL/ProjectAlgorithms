/*
2835. Minimum Operations to Form Subsequence With Target Sum

You are given a 0-indexed array nums consisting of non-negative powers of 2, and an integer target.

In one operation, you must apply the following changes to the array:

Choose any element of the array nums[i] such that nums[i] > 1.
Remove nums[i] from the array.
Add two occurrences of nums[i] / 2 to the end of nums.
Return the minimum number of operations you need to perform so that nums contains a subsequence whose elements sum to target. If it is impossible to obtain such a subsequence, return -1.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/


class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long int s = 0;
        int n = nums.size();
        int ans = 0;
        vector<int> freq(32, 0);
        for(int i=0;i<n;i++){
            s+=nums[i];
            int curPow = int(log(nums[i])/log(2));
            freq[curPow]++; 
            
        }
       
        if(target>s){
            return -1;
        }
        int minInd = 32;
        for(int i= 0;i<31;i++){
            int bit = (1<<i);
            if((target&bit)>0){
                if(freq[i]>0){
                    freq[i]--;
                }
                else{
                    minInd = min(minInd , i);
                }
            }
            if((freq[i]>0)&&(minInd<i)){
                ans+=i-minInd;
                freq[i]--;
                minInd=32;
            }
            freq[i+1] += freq[i]/2;
        }
        return ans;
        
    }
};