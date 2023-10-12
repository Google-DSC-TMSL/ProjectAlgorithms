#include <iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;

int dp[301];
int help(int i,string s ,set<string>&wordDict){
        if(i==s.size())
            return 1;
        string temp;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(help(j+1,s,wordDict)){
                    dp[i]=1;
                    return 1;
                }
            }
        }
        dp[i]=0;
        return 0;
    }

bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st;
       memset(dp,-1,sizeof dp);
       for(int i=0;i<wordDict.size();i++){
           st.insert(wordDict[i]);
       }
       return help(0,s,st);
    }
    
int main()
{
    string s;
    cin>>s;
    vector<string>worddict;
    int n;
    cin>>n;string word;
    for(int i=0;i<n;i++){
        cin>>word;
        worddict.push_back(word);
    }
    cout<<wordBreak(s,worddict);
    return 0;
    
}