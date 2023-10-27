class Solution {
public:
    int subsetSumCount(vector<int> nums,int sum)
    {
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(int i=0;i<nums.size();i++)
            s+=nums[i];
        if((s+target)%2==1 || abs(target)>s)
            return 0;
        int sum = (target+s)/2;
        return subsetSumCount(nums,sum);
    }
};
