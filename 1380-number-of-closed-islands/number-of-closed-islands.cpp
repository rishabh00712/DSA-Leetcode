class Solution {
public:
    bool isSafe(int r,int c,int n,int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
    void markEdgeLands(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,int n,int m){
        vector<vector<int>> moves={{-1,0},{0,-1},{1,0},{0,1}};
        for(auto move : moves){
            int newR=i+move[0];
            int newC=j+move[1];
            if(isSafe(newR,newC,n,m) && !grid[newR][newC] && !vis[newR][newC]){
                vis[newR][newC]=1;
                markEdgeLands(grid,newR,newC,vis,n,m);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!grid[i][0] && !vis[i][0]){
                vis[i][0]=1;
                markEdgeLands(grid,i,0,vis,n,m);
            }
            if(!grid[i][m-1] && !vis[i][m-1]){
                vis[i][m-1]=1;
                markEdgeLands(grid,i,m-1,vis,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(!grid[0][i] && !vis[0][i]){
                vis[0][i]=1;
                markEdgeLands(grid,0,i,vis,n,m);
            }
            if(!grid[n-1][i] && !vis[n-1][i]){
                vis[n-1][i]=1;
                markEdgeLands(grid,n-1,i,vis,n,m);
            }
        }
        int totalIsland=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j] && !vis[i][j]){
                    totalIsland++;
                    markEdgeLands(grid,i,j,vis,n,m);
                }
            }
        }
        return totalIsland;
    }
};