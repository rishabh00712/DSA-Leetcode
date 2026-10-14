class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int nines=sum/9;
        int rem=sum%9;
        if(rem!=0 && num<nines+1) return "";
        string ans;
        while(nines>0){
            ans.push_back('9');
            nines--;
        }
        if(rem==0 && ans.size()==num) return ans;
        ans.push_back(rem+'0');
        while(ans.size()!=num){
            ans.push_back('0');
        }
        return ans;
    }
};