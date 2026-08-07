class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target){
        int left=0;
        int right = matrix.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][0]==target){
                return mid;
            }
            if(matrix[mid][0]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        //here we need to return the previous postion not the correct positon 
        //beacuse after break the loop the target must be present in the previous
        //prsiton not the next postion 
        return left-1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix,target);
        if (row < 0) return false;
        if(matrix[row][0]==target)return true;
     
        int left=0;
        int right=matrix[0].size()-1;
        while(left<=right){
            int mid=(left+right)/2;
           
            if(matrix[row][mid]==target){
                return true;
            }
            if(matrix[row][mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
    }
};