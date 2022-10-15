// https://leetcode.com/submissions/detail/796452282/

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

class Solution 
{
    public int maxSubArray(int[] nums) 
    {
        int sum=Integer.MIN_VALUE,currentsum=0;
        for(int i:nums)
        {
            currentsum+=i;
            sum=Math.max(sum,currentsum);
            if(currentsum<0)
                currentsum=0;
        }
        return sum;
    }
}