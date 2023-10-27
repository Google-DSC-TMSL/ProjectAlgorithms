Question Link:- https://leetcode.com/problems/set-matrix-zeroes/
Youtube Link:- https://www.youtube.com/watch?v=M65xBewcqcI
class Solution {
public:
    void makezero(vector<vector<int>>&matrix, int i, int j){
        for(int z=0;z<matrix[0].size();z++) matrix[i][z]=0;
        for(int z=0;z<matrix.size();z++) matrix[z][j]=0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroindex;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) zeroindex.push_back({i,j});
            }
        }
        for(int x=0;x<zeroindex.size();x++){
            int i = zeroindex[x].first;
            int j = zeroindex[x].second;
            makezero(matrix,i,j);
        }
    }
};
