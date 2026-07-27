class Solution {
public:
    bool canBeAns(vector<int>& weights,int days,int maxWeight){
        int count=0;
        int day=1;
        for(int n : weights){
            if(n>maxWeight) return false;
            count+=n;
            if(count>maxWeight){
                day++;
                count=n;
            }
        }
        
        cout<<day<< " "<<maxWeight<<endl;
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=0;
        for(auto n: weights){
            r+=n;
        }
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canBeAns(weights,days,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};