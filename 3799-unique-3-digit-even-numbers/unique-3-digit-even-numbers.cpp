class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n=digits.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                for(int k=0;k<n;k++){
                    if(j==k || i==k) continue;
                    if(digits[j]%2!=0) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(s.find(num)==s.end()){
                        s.insert(num);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};