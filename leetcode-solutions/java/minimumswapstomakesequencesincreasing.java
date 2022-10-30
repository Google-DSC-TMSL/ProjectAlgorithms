class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int n = nums1.length;
        
        // initialize dp table
        int[][] memo = new int[2][n];
        Arrays.fill(memo[0], -1);
        Arrays.fill(memo[1], -1);
        memo[0][0] = 0;
        memo[1][0] = 1;
        
        return Math.min(recurse(nums1, nums2, n - 1, 0, memo),
                        recurse(nums1, nums2, n - 1, 1, memo));
    }
    
    private int recurse(int[] nums1, int[] nums2, int i, int swap, int[][] memo) {
        //check dp table
        if (memo[swap][i] != -1)
            return memo[swap][i];
        
        // initial value is set as max
        int res = Integer.MAX_VALUE;
        
        // if array is increasing without swapping
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                res = recurse(nums1, nums2, i - 1, swap, memo);
        
        // if array is increasing with swapping
        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
                res = Math.min(res, 
                               recurse(nums1, nums2, i - 1, 1 - swap, memo));
        
        memo[swap][i] = swap == 0 ? res : res + 1;
        return memo[swap][i];
    }
}