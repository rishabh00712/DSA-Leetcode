// class Solution {
// public:
//     bool recursion(string s,int i,int j,int k){
//         if(i>=j) return true;
//         if(s[i]!=s[j] && k==0) return false;
//         if(s[i]!=s[j]){
//             bool leftInc=recursion(s,i+1,j,0);
//             bool rightInc=recursion(s,i,j-1,0);
//             return leftInc || rightInc;
//         }
//         return recursion(s,i+1,j-1,k);
//     }
//     bool validPalindrome(string s) {
//         return recursion(s,0,s.size()-1,1);
//     }
// };
class Solution {
public:
    bool checkPalindroome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int k=1;
        while(i<=j){
            if(s[i]!=s[j] && k==0) return false;
            if(s[i]!=s[j]){
                k=0;
                return checkPalindroome(s,i+1,j) || checkPalindroome(s,i,j-1);
            }
            i++;j--;
        }
        return true;
    }
};
