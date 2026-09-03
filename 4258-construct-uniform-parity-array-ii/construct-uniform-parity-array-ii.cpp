class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sOdd=INT_MAX;
        int sEven=INT_MAX;
        for(auto n : nums1){
            if(n%2==0){
                sEven=min(sEven,n);
            }else{
                sOdd=min(sOdd,n);
            }
        }
        if(sOdd==INT_MAX || sEven==INT_MAX) return true;
        if(sOdd>sEven) return false;
        return true;
    }
};