class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indexStack;
        int n=s.size();
        vector<int> flags(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                indexStack.push(i);
            }else{
                if(indexStack.empty()) continue;
                int openBI=indexStack.top();
                indexStack.pop();
                int len=i-openBI+1;
                int totalLen=0;
                if(openBI==0){
                    totalLen=len;
                }else{
                    totalLen=len+flags[openBI-1];
                }
                ans=max(totalLen,ans);
                flags[i]=totalLen;
            }
        }
        return ans;
    }
};