class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        int pre=nums[0];
        unordered_set<int>s;
        for(auto n : nums){
            s.insert(n);
        }
        for(int i=1;i<nums.size();i++){
            if(pre+1!=nums[i]){
                break;
            }
            pre=nums[i];
            ans+=nums[i];
        }
        while(1){
            if(s.find(ans)==s.end()){
                break;
            }
            ans++;
        }
        return ans;
    }
};