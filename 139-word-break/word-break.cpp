class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> myset;
        int maxLen=0;
        for(auto w : wordDict){
            int ns=w.size();
            maxLen=max(maxLen,ns);
            myset.insert(w);
        }
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            string temp;
            for(int j=i;j<=i+maxLen;j++){
                if(j>=n) break;
                temp.push_back(s[j]);
                if(myset.find(temp)!=myset.end()){
                    if(dp[j+1]){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     bool dpFun(string s,int ind,unordered_set<string>& myset,vector<int>& dp){
//         if(ind==s.size()){
//             return true;
//         }
//         if(dp[ind]!=-1)return dp[ind];
//         string temp;
//         for(int i=ind;i<s.size();i++){
//             temp+=s[i];
//             if(myset.find(temp)!=myset.end()){
//                 if(dpFun(s,i+1,myset,dp)){
//                     return dp[ind]=true;
//                 }
//             }
//         }
//         return dp[ind]=false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//         unordered_set<string> myset;
//         for(auto str : wordDict){
//             myset.insert(str);
//         }
//         vector<int> dp(s.size(),-1);
//         return dpFun(s,0,myset,dp);
//     }
// };