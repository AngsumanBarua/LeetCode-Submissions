class Solution {
public:
    int appendCharacters(string s, string t) {
        int sl=s.length();
        int st=t.length();
        int ind=0;
        for(int i=0;i<sl;i++){
            if(s[i]==t[ind]){
                ind++;
                if(ind==st){
                    break;
                }
            }
        }
        return st-ind;
    }
};