class Solution:
    def maxam(self,nums,ind):
        n=len(nums)
        if n==1:
            return nums[0]
        prev=nums[ind]
        prevv=0
        for i in range(ind+1,n):
            if ind==0 and i==n-1:
                break
            cnt=prev
            cnt=max(cnt,prevv+nums[i])
            prevv=prev
            prev=cnt
            
        return prev
    
    def rob(self, nums: List[int]) -> int:
        return max(self.maxam(nums,1),self.maxam(nums,0))
        