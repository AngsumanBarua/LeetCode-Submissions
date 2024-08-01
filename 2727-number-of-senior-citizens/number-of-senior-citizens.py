class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        ans=0
        n=len(details)
        for i in range(n):
            if details[i][11]>'6' or details[i][11]=='6' and details[i][12]>'0':
                ans+=1
        
        return ans

