class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> fiq;
        int i=0;
        int j=0;
        int n=s.size(),ans=0;
        while(i<n){
            fiq[s[i]]++;
            while(j<i && fiq[s[i]]>2){
                fiq[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};