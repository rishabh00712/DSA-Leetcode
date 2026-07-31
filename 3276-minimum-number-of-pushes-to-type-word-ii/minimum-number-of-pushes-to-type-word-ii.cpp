class Solution {
public:
    int minimumPushes(string word) {
        vector<int> fiq(26,0);
        for(auto c : word){
            fiq[c-'a']++;
        }
        sort(fiq.begin(),fiq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            if(fiq[i]==0)break;
            int temp=(i/8+1);
            ans+=temp*fiq[i];
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();