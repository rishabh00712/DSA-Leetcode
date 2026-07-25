class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        while(n>0){
            int lastDigit=n%10;
            minHeap.push(lastDigit);
            if(minHeap.size()>2){
                minHeap.pop();
            }
            n/=10;
        }
        int ans=minHeap.top();
        minHeap.pop();
        return minHeap.top()*ans;
    }
};