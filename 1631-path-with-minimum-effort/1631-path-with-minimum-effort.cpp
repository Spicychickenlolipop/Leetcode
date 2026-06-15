class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;

        pq.push({0,{0,0}});

        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};

        while(!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int effort = p.first;
            int r = p.second.first;
            int c = p.second.second;

            if(r == n-1 && c == m-1)
                return effort;

            if(effort > dist[r][c])
                continue;

            for(int k=0;k<4;k++) {

                int row = r + x[k];
                int col = c + y[k];

                if(row>=0 && row<n &&
                   col>=0 && col<m) {

                    int newEffort =
                        max(
                            effort,
                            abs(heights[r][c] -
                                heights[row][col])
                        );

                    if(newEffort < dist[row][col]) {

                        dist[row][col] = newEffort;

                        pq.push(
                            {newEffort,{row,col}}
                        );
                    }
                }
            }
        }

        return 0;
    }
};