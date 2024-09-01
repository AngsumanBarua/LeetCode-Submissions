class Solution(object):
    def construct2DArray(self, ori, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        l=len(ori)
        ans=[]
        if l==m*n:
            k=0
            for i in range(m):
                row=[]
                for j in range(n):
                    row.append(ori[k])
                    k+=1
                ans.append(row)
            
        return ans