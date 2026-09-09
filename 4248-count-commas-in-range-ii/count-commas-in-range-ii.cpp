class Solution {
public:
    long long countCommas(long long n) {
        unordered_map<int,long long> m;
        if(n<=999) return 0;
        m[1]=999;
        m[2]=999999;
        m[3]=999999999;
        m[4]=999999999999;
        m[5]=999999999999999;
        long long ans=0;
        int i=1;
        while(1){
            long long temp = n-m[i];
            //cout<<temp<<endl;
            //cout<<m[i]<<endl;
            if(temp<0) break;
            i++;
            //cout<<i<<endl;
            ans+=temp;
            if(temp<999) break;
        }
        return ans;
    }
};