// class Solution {
// public:
//     bool valid(int i,int j,int n,int m){
//         if(i<0 || i>=n || j<0 || j>=m)
//             return false;
//         return true;
//     }
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();
//         vector<vector<int>>res(n);
//         int i;
//         for(i=0;i<n;i++){
//             vector<int>t(m,INT_MAX);
//             res[i]=t;
//         }
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//         int x[4]={1,-1,0,0};
//         int y[4]={0,0,1,-1};
//         res[0][0]=0;
//         pq.push({0,{0,0}});
//         while(!pq.empty()){
//             pair<int,pair<int,int>>p=pq.top();
//                 pq.pop();
//             int dis=p.first;
//             int row=p.second.first;
//             int col=p.second.second;
//             if(dis>res[row][col])
//                 continue;
//             for(int k= 0;k<4;k++){
//                 int r=row+x[k];
//                 int c=col+y[k];
//                 if(!valid(r,c,n,m))
//                     continue;
//                 int absdiff=abs(heights[row][col]-heights[r][c]);
//                 int newwt= max(absdiff,dis);
//                 if(newwt<res[r][c]){
//                     res[r][c]=newwt;
//                     pq.push({newwt,{r,c}});
//                 }
//             } 
//         }
//         return res[n-1][m-1];
//     }
// };


class Solution {
public:
    typedef pair<int, pair<int, int>>P;
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;

        auto isSafe = [&](int x, int y){
            return x>=0 && x<m && y>= 0 && y<n;
        };

        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();

            int x = coord.first;
            int y = coord.second;

            for(auto &dir : dirs){
                int x_ = x+dir[0];
                int y_ = y+dir[1];

                if(isSafe(x_,y_)){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if(result[x_][y_]>maxDiff){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_,y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};