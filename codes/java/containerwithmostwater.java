class Solution {
    public int maxArea(int[] height) {
        
        int area=0;
        int start=0;
        int end=height.length-1;
        int res=Math.min(height[start],height[end])*(end-start);
        while(start<end)
        {
            
            if(height[start]<height[end])
                start++;
            else
                end--;
            area=Math.min(height[start],height[end])*(end-start);
            if(area>res)
                res=area;
            
            
        }
        return res;
    }
}