class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=max(nums[0],nums[1]);
        int m2=min(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int n=nums[i];
            if(n>m1){
                int temp=m1;
                m1=n;
                m2=max(m2,temp);
            }else{
                m2=max(m2,n);
            }
        }
        cout<<m1<<" "<<m2<<endl;
        return (m1-1)*(m2-1);
    }
};