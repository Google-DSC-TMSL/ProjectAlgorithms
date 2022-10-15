//https://leetcode.com/submissions/detail/774318828/

//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//You must write an algorithm that runs in O(n) time.

class Solution 
{
    public int longestConsecutive(int[] nums) 
    {
        if(nums.length==0)
            return 0;
        int max=1,cur=1;
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i+1]-nums[i]==1)
            {
                cur+=1;
                max=Math.max(max,cur);
            }
            else if(nums[i]==nums[i+1])
                continue;
            else if(nums[i+1]-nums[i]>1)
                cur=1;
        }
        return max;
    }
}