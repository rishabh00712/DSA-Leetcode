class Solution {
public:
    bool dpFun(string s,int i,int openB,vector<vector<int>>& dp){
        if(i==s.size()){
            if(openB==0) return true;
            return false;
        }
        if(openB<0) return false;
        if(dp[i][openB]!=-1) return dp[i][openB];
        if(s[i]=='*'){
            bool oB=dpFun(s,i+1,openB+1,dp);
            bool cB=dpFun(s,i+1,openB-1,dp);
            bool noB=dpFun(s,i+1,openB,dp);
            return dp[i][openB] = oB || cB || noB;
        }
        bool oB=false,cB=false;
        if(s[i]=='('){
            oB=dpFun(s,i+1,openB+1,dp);
        }
        if(s[i]==')'){
            cB=dpFun(s,i+1,openB-1,dp);
        }
        return dp[i][openB]=oB||cB;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return dpFun(s,0,0,dp);
    }
};
