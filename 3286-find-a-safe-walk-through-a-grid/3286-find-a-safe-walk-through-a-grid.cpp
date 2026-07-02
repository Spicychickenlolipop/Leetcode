class Solution {
public:
    int dp[51][51][102];
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        bool solve(int i,int j, int m, int n, vector<vector<int>>& grid, int health, vector<vector<int>> &vis){
            if(health<1) return false;
            if(i==m-1 && j==n-1){
                if(health>0)return true;
                else return false;
            }
            if(dp[i][j][health]!=-1) return dp[i][j][health];
            bool ans = false;
            for(int k= 0;k<4;k++){
                int u = i+dx[k];
                int v = j+dy[k];
                if(u>=0 && v>=0 && u<m && v<n && vis[u][v]==0){
                    vis[u][v]=1;
                    ans=ans | solve(u,v,m,n,grid,health-grid[u][v],vis);
                    vis[u][v]=0;
                }
            }
            return dp[i][j][health]=ans;
        }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0]=1;
        health-=grid[0][0];
        return solve(0,0,m,n,grid,health,vis);    
    }
        
};