class Solution {
  bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int a=x;
    List <int> v=[];
    while(a>0){
        v.add(a%10);
        a~/=10;
    }
    int vs=v.length;
    bool fg=true;
    for(int i=0,j=vs-1;i<j;i++,j--){
        if(v[i]!=v[j]){
            fg=false;
            break;
        }
    }
    return fg;
  }
}