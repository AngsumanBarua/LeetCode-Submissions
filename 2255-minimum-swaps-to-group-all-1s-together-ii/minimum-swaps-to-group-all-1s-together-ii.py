class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        one=0
        for i in range(n):
            if nums[i]==1:
                one+=1

        if one==0 or one==n:
            return 0
    
        cur=0;
        for i in range(one):
            if nums[i]==1 :
                cur+=1
        
        ans=one-cur
        for i in range(1,n):
            if i+one<=n:
                if nums[i+one-1]==1:
                    cur+=1
        
                if nums[i-1]==1:
                    cur-=1

            else:
                if nums[i+one-n-1]==1:
                    cur+=1

                if nums[i-1]==1:
                    cur-=1

            ans=min(ans,one-cur)
            if not ans:
                break

        return ans;
        