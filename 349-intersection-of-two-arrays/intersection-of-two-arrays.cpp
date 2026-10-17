class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> storeNums2(nums2.begin(),nums2.end());
        nums2.clear();
        for(int n : nums1){
            if(storeNums2.find(n)!=storeNums2.end()){
                nums2.push_back(n);
                storeNums2.erase(n);
            }
        }
        return nums2;
    }
};