#include<bits/stdc++.h>
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size(),0);
        vector<int> rmax(height.size(),0);
        int i;
        lmax[0]=height[0];
        for(i=1;i<height.size();i++)
        {
            lmax[i]=max(lmax[i-1],height[i]);
        }
        rmax[height.size()-1]=height[height.size()-1];
        for(i=height.size()-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],height[i]);
        }
        int res=0;
        for(i=0;i<height.size();i++)
        {
            res+=min(lmax[i],rmax[i])-height[i];
        }
        return res;
    }
};