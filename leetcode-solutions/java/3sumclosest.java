class Solution {
    public int threeSumClosest(int[] nums, int target){
        // idea is to have 2 pointers in a sorted array
        Arrays.sort(nums);
        
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<nums.length-2; i++){
            int a = i+1;
            int b = nums.length-1;
            while(a<b){
                int curr = nums[i] + nums[a] + nums[b];
                if(curr > target){
                    b--;
                }
                else if(curr < target){
                    a++;
                }
                else{
                    return curr;
                }
                if(Math.abs(ans-target) > Math.abs(curr-target)){
                    ans = curr;
                }
            }
        }
        
        return ans;
    }
}