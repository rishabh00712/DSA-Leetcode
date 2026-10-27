class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        for(int i=0;i<m;i++){
            string row;
            for(int j=0;j<n;j++){
                if(i==m-1){
                    row.push_back('.');
                }else if(j==0){
                    row.push_back('.');
                }else{
                    row.push_back('#');
                }
            }
            grid.push_back(row);
        }
        return grid;
    }
};