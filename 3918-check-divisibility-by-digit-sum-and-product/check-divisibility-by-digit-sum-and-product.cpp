class Solution {
public:
    int product(vector<int>& dig){
        int pro=1;
        int sum=0;
        for(auto d : dig){
            pro*=d;
            sum+=d;
        }
        return pro+sum;
    }
    bool checkDivisibility(int n) {
        int temp=n;
        vector<int> dig;
        while(n>0){
            dig.push_back(n%10);
            n/=10;
        }
        int total=product(dig);
        if(temp%total==0) return true;
        return false;
    }
};