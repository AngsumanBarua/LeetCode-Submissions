class Solution {
public:
    bool isPalindrome(int x) {
        int a=x;
        if(a<0){
            return false;
        }
        vector <int> v;
        while(a){
            v.push_back(a%10);
            a/=10;
        }
        int vs=v.size();
        bool fg=true;
        for(int i=0,j=vs-1;i<j;i++,j--){
            if(v[i]!=v[j]){
                fg=false;
                break;
            }
        }
        return fg;
    }
};