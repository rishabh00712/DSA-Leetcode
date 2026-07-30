class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(i>=0 && i<8){
                ans++;
            }else if(i>=8 && i<16){
                ans+=2;
            }else if(i>=16 && i<24){
                ans+=3;
            }else{
                ans+=4;
            }
        }
        return ans;
    }
};