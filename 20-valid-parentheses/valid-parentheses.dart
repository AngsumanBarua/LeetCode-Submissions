class Solution {
  bool isValid(String s) {
    int l=s.length;
    List <String> ls=[];
    bool ans=true;
    for(int i=0;i<l;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            ls.add(s[i]);
        }
        else{
            if(ls.isNotEmpty && ((ls.last=='(' && s[i]==')') || (ls.last=='{' && s[i]=='}') || (ls.last=='[' && s[i]==']'))){
                ls.removeLast();
            }
            else{
                ans=false;
                break;
            }
        }
    }
    if(ans && ls.isNotEmpty){
        ans=false;
    }
    return ans;
  }
}