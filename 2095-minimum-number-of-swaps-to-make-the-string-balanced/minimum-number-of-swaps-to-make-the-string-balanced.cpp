class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        stack <char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        int l=st.size();
        int ans=l/4;
        if(l%4!=0){
            ans++;
        }
        return ans;
    }
};