#include <bits/stdc++.h>
using namespace std;
int countOfSubsetSumWithAGivenSum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int countOfSubsetsWithAGivenDifference(int arr[],int n,int diff)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    sum=(diff+sum)/2;
    return countOfSubsetSumWithAGivenSum(arr,n,sum);
}
int main()
{
    int n,diff;
    cin>>n>>diff;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<countOfSubsetsWithAGivenDifference(arr,n,diff)<<endl;
    return 0;
}
