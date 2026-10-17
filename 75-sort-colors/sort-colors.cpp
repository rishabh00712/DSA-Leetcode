class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> fiq(3,0);
        for(int num : nums){
            fiq[num]++;
        }
        int ind=0;
        int i=0;
        while(fiq[2] || fiq[1] || fiq[0]){
            if(fiq[i]==0){
                i++;
                continue;
            } 
            nums[ind]=i;
            ind++;
            fiq[i]--;
        }
    }
};