//3 Sum Closest
//Question Link :- https://leetcode.com/problems/3sum-closest/

/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
    }
};
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
                
                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    return target;
                }
            }
        }
        
        return closestSum;
    }
};