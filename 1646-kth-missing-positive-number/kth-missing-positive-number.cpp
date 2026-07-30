class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int miss=arr[mid]-mid-1;
            if(k>miss){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<l<<" "<<h;
        return l+k;
    }
};

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int kth=0;
//         int i=1;
//         int ind=0;
//         int n=arr.size();
//         while(ind<n){
//             if(arr[ind]==i){
//                 ind++;
//             }else{
//                 kth++;
//                 if(kth==k) return i;
//             }
//             i++;
//         }
//         while(kth<k){
//             kth++;
//             i++;
//         }
//         return --i;
//     }
// };