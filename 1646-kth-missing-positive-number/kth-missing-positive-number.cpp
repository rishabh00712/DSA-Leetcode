class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int kth=0;
        int i=1;
        int ind=0;
        int n=arr.size();
        while(ind<n){
            if(arr[ind]==i){
                ind++;
            }else{
                kth++;
                if(kth==k) return i;
            }
            i++;
        }
        while(kth<k){
            kth++;
            i++;
        }
        return --i;
    }
};