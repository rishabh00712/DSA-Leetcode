class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> box;
        for(auto n : nums){
            box.insert(n);
        }
        int i=1;
        while(i){
            int val = i*k;
            if(box.find(val)==box.end()){
                return val;
            }
            i++;
        }
        return -1;
    }
};