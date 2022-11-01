class Solution {
public:
    int minSwap(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        int dp[n][2];
        for(int i=0;i<n;i++){dp[i][0]=INT_MAX; dp[i][1]=INT_MAX;}
        dp[0][0]=0;
        dp[0][1]=1;
        int prev1,prev2;
        for(int i=1;i<n;i++){
            prev1=v2[i-1];
            prev2=v1[i-1];
            if(dp[i-1][1]!=INT_MAX){
                if(v2[i]>prev1 && v1[i]>prev2){
                    dp[i][1]=1+dp[i-1][1];
                }
                //no swap at current position
                if(v1[i]>prev1 && v2[i]>prev2){
                    dp[i][0]=dp[i-1][1];
                }
            }

            //prev position no swap
            prev1=v1[i-1];
            prev2=v2[i-1];
            if(dp[i-1][0]!=INT_MAX){
                //swap at current position
                if(v2[i]>prev1 && v1[i]>prev2){
                    dp[i][1]=min(dp[i][1],1+dp[i-1][0]);
                }
                //no swap at current position
                if(v1[i]>prev1 && v2[i]>prev2){
                    dp[i][0]=min(dp[i][0],dp[i-1][0]);
                }
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};