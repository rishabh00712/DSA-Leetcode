class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        unordered_set<int> set;
        for(auto n : nums){
            set.insert(n);
            maxi=max(maxi,n);
            mini=min(mini,n);
        } 
        vector<int> ans;  
        while(mini<maxi){
            if(set.find(mini)==set.end()){
                ans.push_back(mini);
            }
            mini++;
        }
        return ans;
    }
};