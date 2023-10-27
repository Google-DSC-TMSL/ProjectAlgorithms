class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        l=0
        cnt=0
        d=0
        what=0
        if len(nums)==1:
            return 1
        if nums[l+1]-nums[l]>0:
            d=1
        elif nums[l+1]-nums[l]<0:
            d=2
        else:
            d=0
            what=1
        cnt+=1
        l+=1
        while l<len(nums)-1:
            if (d==1 or d==0)and nums[l+1]-nums[l]<0:
                d=2
                cnt+=1
            elif (d==0 or d==2) and nums[l+1]-nums[l]>0:
                d=1
                cnt+=1
            l+=1
        if what==1:
            return cnt
        else:
            return cnt+1 #i have no idea what just happened but it worked