class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int remain = n-1000;
        return remain+1;
    }
};