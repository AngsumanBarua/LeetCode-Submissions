class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        n=len(target)
        ara=[0]*(1003)
        for i in range(n):
            ara[target[i]]+=1
            ara[arr[i]]-=1

        for i in range(1,1001):
            if ara[i]!=0:
                return False
        
        return True;
