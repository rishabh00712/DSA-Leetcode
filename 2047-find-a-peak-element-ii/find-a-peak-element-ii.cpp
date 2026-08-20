class Solution {
public:
    int findVal(vector<vector<int>>& mat,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return -1;
        return mat[i][j];
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int val=mat[i][mid];
                int top=findVal(mat,i-1,mid,n,m);
                int bottom=findVal(mat,i+1,mid,n,m);
                int left=findVal(mat,i,mid-1,n,m);
                int right=findVal(mat,i,mid+1,n,m);
                if(val>top && val>bottom && val>left && val>right){
                    return {i,mid};
                }
                if(right>left){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return {-1,-1};
    }
};