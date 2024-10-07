class Solution {
public:
    int minLength(string s) {
        int l=s.length();
        stack <char> st;
        st.push(s[0]);
        int n=1;
        for(int i=1;i<l;i++){
            if(n==0){
                st.push(s[i]);
                n++;
                continue;
            }
            char a=st.top();
            st.pop();
            n--;
            if((s[i]!='B' || a!='A') && (s[i]!='D' || a!='C')){
                st.push(a);
                st.push(s[i]);
                n+=2;
            }
            //cout << i << " " << n << endl;
        }
        //cout << n << endl;
        return n;
    }
};