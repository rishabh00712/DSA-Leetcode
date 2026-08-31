class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int ans=0;
        int n=g.size(),m=s.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};