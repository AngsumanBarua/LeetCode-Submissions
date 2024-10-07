class Solution {
public:
    int minLength(string s) {
        while(1){
            string t;
            int l=s.length();
            bool fg=false;
            int lst=-1;
            for(int i=1;i<l;i++){
                if(!fg && s[i]=='B' && s[i-1]=='A'){
                    fg=true;
                    lst=i;
                }
                else if(!fg && s[i]=='D' && s[i-1]=='C'){
                    fg=true;
                    lst=i;
                }
                else{
                    if(lst!=i-1){
                        t.push_back(s[i-1]);
                    }
                    if(i==l-1){
                        t.push_back(s[i]);
                    }
                }
            }
            if(!fg){
                break;
            }
            else{
                swap(s,t);
            }
        }
        return s.length();
    }
};