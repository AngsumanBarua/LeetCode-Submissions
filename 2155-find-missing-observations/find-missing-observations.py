class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        m=len(rolls)
        tot=(m+n)*mean
        cur=0
        for i in range(m):
            cur+=rolls[i]
        
        ans=[]
        d=(tot-cur)//n
        mod=(tot-cur)%n
        if d>=1 and d<=5 or d==6 and mod==0:
            for i in range(n):
                ans.append(d)
                if mod>=1:
                    ans[i]+=1
                    mod-=1
        return ans