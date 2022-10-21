import math
class Solution:
    def maxSubArraySum(self,arr,N):
        ##Your code here
        max_ending=0
        max_so_far=-math.inf
        for i in range(N):
            max_ending+=arr[i]
            if max_so_far<max_ending:
                max_so_far=max_ending
            if max_ending<0:
                max_ending=0
        return max_so_far
        

import math

# Aditya Seth
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()