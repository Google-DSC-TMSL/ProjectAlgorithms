class Solution {
    public int maxSubArray(int[] arr) {
        int s=0;// intialzing sum with zero
        int max=Integer.MIN_VALUE;// intialzing max variable with minimum value 
        for(int i=0;i<arr.length;i++)
        {
             s=s+arr[i]; //adding array element in sum variable
             if(s>max) // finding maximum sum
                 max=s; //update max variable
             if(s<0) //if sum is -ve,means this subarray is useless
                 s=0; //restart calculating sum
        }
        return max;
    }
}
