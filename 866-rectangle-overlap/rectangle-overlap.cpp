class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a=rec1[0],b=rec1[1],c=rec1[2],d=rec1[3];
        int p=rec2[0],q=rec2[1],r=rec2[2],s=rec2[3];
        return !((p<=a && r<=a) || (p>=c && r>=c) || (q<=b && s<=b) || (q>=d && s>=d)); 
    }
};