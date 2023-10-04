/* 
2874. Maximum Value of an Ordered Triplet II
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
 

Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 106


*/


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long int n = nums.size();
        if(n<3){
            return 0;
        }
        if(n==3){
            long long ans = ((long long)nums[0]-(long long)nums[1])*(long long)nums[2];
            return max((long long)0,ans);
        }
        vector<long long int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],(long long)nums[i]);
        }
        vector<long long int> suf(n);
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],(long long)nums[i]);
        }
        long long result = INT_MIN;
        for(int i=1;i<n-1;i++){
            long long temp = (pre[i-1]-(long long)nums[i])*(long long)suf[i+1];
            result = max(temp,result);
        }
        
        return max(0LL,result);
    }
};