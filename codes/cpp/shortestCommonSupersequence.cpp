class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m=a.length();
        int n=b.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=m;
        int j=n;
        string s;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                s=a[i-1]+s;
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    s=a[i-1]+s;
                    i--;
                }
                else
                {
                    s=b[j-1]+s;
                    j--;
                }
            }
        }
        while(i>0)
        {
            s=a[i-1]+s;
            i--;
        }
        while(j>0)
        {
            s=b[j-1]+s;
            j--;
        }
        return s;
    }
};
