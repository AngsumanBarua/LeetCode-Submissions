class Solution {
public:
    int maxScore(string s) {
        int l=s.length();
        vector <int> left(l+1),right(l+1);
        if(s[0]=='0'){left[0]=1;};
        if(s[l-1]=='1'){right[l-1]=1;};
        for(int i=1,j=l-2;i<l;i++,j--){
            left[i]=left[i-1];
            right[j]=right[j+1];
            if(s[i]=='0'){
                left[i]+=1;
            }
            if(s[j]=='1'){
                right[j]+=1;
            }
        }
        int ans=0;
        for(int i=0;i<l-1;i++){
            ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};