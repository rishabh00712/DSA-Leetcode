class Solution {
public:
    bool isDivisible(int n,int t){
        int product=1;
        while(n>0){
            product*=(n%10);
           
            n/=10;
        }
        return product%t==0 ? true : false;
    }
    int smallestNumber(int n, int t) {
        for(int i=0;i<=10;i++){
            if(isDivisible(n+i,t)){
                return n+i;
            }
        }
        return  -1;
    }
};