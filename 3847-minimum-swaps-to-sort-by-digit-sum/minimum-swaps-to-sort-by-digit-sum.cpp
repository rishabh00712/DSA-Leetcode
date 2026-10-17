class Solution {
public:
    static int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    static bool cmp(int a,int b){
        int dsA=digitSum(a);
        int dsB=digitSum(b);
        if(dsA==dsB){
            if(a<b) return true;
            return false;
        }
        if(dsA<dsB) return true;
        return false;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> unsortedNum=nums;
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();
        vector<bool> vis(n,false);
        unordered_map<int,int> mapNumInd;
        for(int i=0;i<n;i++){
            mapNumInd[nums[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int k=0;
            int node=unsortedNum[i];
            int ind=i;
            while(!vis[ind]){
                vis[ind]=true;
                ind=mapNumInd[node];
                node=unsortedNum[ind];
                k++;
            }
            swaps+=(k-1);
        }
        return swaps;

    }
};