class Solution {
public:
    bool dpFun(string s,int ind,unordered_set<string>& myset,vector<int>& dp){
        if(ind>s.size()-1){
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        string temp;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(myset.find(temp)!=myset.end()){
                if(dpFun(s,i+1,myset,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> myset;
        for(auto str : wordDict){
            myset.insert(str);
        }
        vector<int> dp(s.size(),-1);
        return dpFun(s,0,myset,dp);
    }
};