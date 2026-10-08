class Solution {
public:
    string removeOuterParentheses(string s) {
        int hand = 0;
        string ans;
        for(auto c : s){
            if(c=='(' && hand==0){
                //non take 
                hand++;
            }else if(c==')' && hand ==1){
                // non take 
                hand--;
            }else if(c=='('){
                ans.push_back('(');
                hand++;
            }else if(c==')'){
                ans.push_back(')');
                hand--;
            }
        }
        return ans;
    }
};