class Solution {
public:
    string intToRoman(int num) {
        int ten=1,val;
        string ans;
        while(num!=0){
            val=ten*(num%10);
            num/=10;
            if(ten==1){
                if(val<=3){
                    for(int i=0;i<val;i++){
                        ans.push_back('I');
                    }
                }
                else if(val==4){
                    ans.push_back('V');
                    ans.push_back('I');
                }
                else if(val==5){
                    ans.push_back('V');
                }
                else if(val<=8){
                    for(int i=0;i<val-5;i++){
                        ans.push_back('I');
                    }
                    ans.push_back('V');
                }
                else if(val==9){
                    ans.push_back('X');
                    ans.push_back('I');
                }
            }
            else if(ten==10){
                if(val<=30){
                    for(int i=0;i<val/10;i++){
                        ans.push_back('X');
                    }
                }
                else if(val==40){
                    ans.push_back('L');
                    ans.push_back('X');
                }
                else if(val==50){
                    ans.push_back('L');
                }
                else if(val<=80){
                    for(int i=0;i<(val-50)/10;i++){
                        ans.push_back('X');
                    }
                    ans.push_back('L');
                }
                else if(val==90){
                    ans.push_back('C');
                    ans.push_back('X');
                }
            }
            else if(ten==100){
                if(val<=300){
                    for(int i=0;i<val/100;i++){
                        ans.push_back('C');
                    }
                }
                else if(val==400){
                    ans.push_back('D');
                    ans.push_back('C');
                }
                else if(val==500){
                    ans.push_back('D');
                }
                else if(val<=800){
                    for(int i=0;i<(val-500)/100;i++){
                        ans.push_back('C');
                    }
                    ans.push_back('D');
                }
                else if(val==900){
                    ans.push_back('M');
                    ans.push_back('C');
                }
            }
            else if(ten==1000){
                if(val<=3000){
                    for(int i=0;i<val/1000;i++){
                        ans.push_back('M');
                    }
                }
            }
            ten*=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};