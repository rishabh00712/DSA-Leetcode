class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> storeNums2;
        unordered_set<int> storeAns;
        for(int n : nums2){
            storeNums2.insert(n);
        }
        nums2.clear();
        for(int n : nums1){
            if(storeNums2.find(n)!=storeNums2.end() && storeAns.find(n)==storeAns.end()){
                nums2.push_back(n);
                storeAns.insert(n);
            }
        }
        return nums2;
    }
};