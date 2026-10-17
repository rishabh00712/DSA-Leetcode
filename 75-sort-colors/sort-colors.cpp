//we can also do it by fix and travel two pointer 
//for 0's 
// then for 1's
// last for 2's 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> fiq(3,0);
        for(int num : nums){
            fiq[num]++;
        }
        int ind=0;
        for(int i=0;i<3;i++){
            while(fiq[i]>0){
                nums[ind++]=i;
                fiq[i]--;
            }
        }
    }
};