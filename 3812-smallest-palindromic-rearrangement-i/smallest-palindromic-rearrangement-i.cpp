class Solution {
public:
    string smallestPalindrome(string s) {
        string ans;
        int size=s.size();
        int n=size/2;
        for(int i=0;i<n;i++){
            ans.push_back(s[i]);
        }
        //cout<<n<<endl;
        sort(ans.begin(),ans.end());
        if(size%2!=0){
            ans.push_back(s[n]);
        }
        n--;
        for(;n>=0;n--){
            ans.push_back(ans[n]);
        }
        return ans;
    }
};