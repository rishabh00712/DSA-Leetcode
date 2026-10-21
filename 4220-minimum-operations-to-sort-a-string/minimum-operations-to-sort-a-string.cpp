class Solution {
public:
    int minOperations(string s) {
        string usS=s;
        int n=s.size();
        sort(s.begin(),s.end());
        if(usS==s) return 0;
        if(n<3) return -1;
        int ans=0;
        if(usS[0]!=s[0]) ans++;
        if(usS[n-1]!=s[n-1]) ans++;
        if(usS[n-1]==s[0] && usS[0]==s[n-1] && s[0]!=s[1] && s[n-1]!=s[n-2]) ans++;
        if(ans==0){
            //check if any middle missmatch 
            for(int i=0;i<n;i++){
                if(s[i]!=usS[i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};