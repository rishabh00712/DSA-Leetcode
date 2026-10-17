class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Fiq(26,0);
        vector<int> windowFiq(26,0);

        for(char c : s1){
            s1Fiq[c-'a']++;
        }
        int n=s1.size();
        if(s2.size()<n) return false;

        int i=0,j=0;
        for(;j<n;j++){
            windowFiq[s2[j]-'a']++;
        }
        cout<<j;
        for(;j<s2.size();j++){
            if(s1Fiq==windowFiq) return true;
            windowFiq[s2[i]-'a']--;
            windowFiq[s2[j]-'a']++;
            i++;
        }
        if(s1Fiq==windowFiq) return true;
        return false;
    }
};