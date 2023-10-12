#include <iostream>
#include<vector>
using namespace std;

void findProperSubSet(int k,int n,vector<vector<int>>&ans,vector<int>&partAns,int l){
        if(k==0&&n<0)
            return;
        if(k==0&&n==0){
            ans.push_back(partAns);
            return;
        }
        if(k==0&&n>0)
            return;
        for(int i=l;i<=9;i++){
            partAns.push_back(i);
            findProperSubSet(k-1,n-i,ans,partAns,i+1);
            partAns.pop_back();
        }

    }
vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>partAns;
        findProperSubSet(k,n,ans,partAns,1);
        return ans;
}
int main()
{
    int k,n;
    cin>>k;
    cin>>n;
    vector<vector<int>>ans=combinationSum3(k,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<k;j++){
            cout<<ans[i][j];
        }
        cout<<""<<endl;
    }

    return 0;
}