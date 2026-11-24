class Solution {
public:
    int dpFun(int i,string s,int n,vector<int>& dp){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int takeOneChar=dpFun(i+1,s,n,dp);
        int takeTwoChar=0;
        if(i!=n-1){
            string str;
            str.push_back(s[i]);
            str.push_back(s[i+1]);
            if(str<="26"){
                takeTwoChar=dpFun(i+2,s,n,dp);
            }
        }
        return dp[i]=takeOneChar+takeTwoChar;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        // return dpFun(0,s,n,dp);

        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                int takeOneChar=dp[i+1];
                int takeTwoChar=0;
                if(i!=n-1){
                    string str;
                    str.push_back(s[i]);
                    str.push_back(s[i+1]);
                    if(str<="26"){
                        takeTwoChar=dp[i+2];
                    }
                }
                dp[i]=takeOneChar+takeTwoChar;
            }
        }
        return dp[0];
    }
};