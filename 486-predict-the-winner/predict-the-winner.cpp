class Solution {
public:
    bool dpFun(vector<int>& nums,int i,int j,int p1,int p2,bool isP1turn){
        if(i>j){
            return p1>=p2;
        }
        bool p11=false,p12=false,p21=false,p22=false;
        bool actualP2=false;
        if(isP1turn){
            p11=dpFun(nums,i+1,j,p1+nums[i],p2,false);
            p12=dpFun(nums,i,j-1,p1+nums[j],p2,false);
        }else{
            p21=dpFun(nums,i+1,j,p1,p2+nums[i],true);
            p22=dpFun(nums,i,j-1,p1,p2+nums[j],true);
            actualP2=p21 && p22;
        }
        return p11 || p12 || actualP2;
    }
    bool predictTheWinner(vector<int>& nums) {
        int p1=0;
        int p2=0;
        int n=nums.size();
        return dpFun(nums,0,n-1,p1,p2,true);
    }
};