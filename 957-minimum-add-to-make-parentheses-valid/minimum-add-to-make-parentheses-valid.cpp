class Solution {
public:
    int minAddToMakeValid(string s) {
        int total=0;
        int ans=0;
        for(auto p : s){
            if(p=='('){
                total++;
            }else{
                total--;
            }
            if(total<0) {
                total=0;
                ans++;
            }
        }
        if(total>0){
            ans+=total;
        }
        return ans;
    }
};