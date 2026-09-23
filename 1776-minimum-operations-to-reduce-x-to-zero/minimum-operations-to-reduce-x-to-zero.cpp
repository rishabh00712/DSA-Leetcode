class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int num : nums){
            sum+=num;
        }
        int find=sum-x;
        sum=0;
        int mini=INT_MAX;
        if(find==0) return n;
        for(int i=0,j=0;i<n;i++){
            sum+=nums[i];
            while(j<i && sum>find){
                sum-=nums[j];
                j++;
            }
            //cout<<sum<<" "<<find<<" "<<i<<" "<<j<< endl;
            if(sum==find){
                mini=min(mini,(n-(i-j+1)));
            }
        }
        return mini==INT_MAX?-1 : mini;
    }
};

// class Solution {
// public:
//     int dpFun(vector<int>& nums,int x,int i,int j,vector<vector<vector<int>>>& dp){
//         if(x==0) return 0;
//         if(i>j) return -1;
//         if(x<0) return -1;
//         if(dp[i][j][x]!=-1) return dp[i][j][x];
        
//         int left=dpFun(nums,x-nums[i],i+1,j,dp);
//         int right=dpFun(nums,x-nums[j],i,j-1,dp);
//         if(left==-1 && right==-1) return -1;
//         if(left==-1) return 1+right;
//         if(right==-1) return 1+left;
//         return dp[i][j][x]=1+(min(left,right));
//     }
//     int minOperations(vector<int>& nums, int x) {
//         int n=nums.size()-1;
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(x+1,-1)));
//         return dpFun(nums,x,0,n,dp);
//     }
// };