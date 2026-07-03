// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int,int>>>a(n+1);
//         for(int i=0;i<times.size();i++){
//             int s = times[i][0];
//             int d = times[i][1];
//             int w = times[i][2];
//             a[s].push_back({d,w});
//         } 
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

//         vector<int>dist(n+1,INT_MAX);
//         dist[k]=0;
//         pq.push({0,k});
//         while(!pq.empty()){
//             pair<int,int>p=pq.top();
//             pq.pop();
//             int d = p.first;
//             int node = p.second;
//             if(d>dist[node])
//                 continue;
//             for(int j=0;j<a[node].size();j++){
//                 int neigh=a[node][j].first;
//                 int wt = a[node][j].second;
//                 if(d+wt<dist[neigh]){
//                     dist[neigh]=d+wt;
//                     pq.push({d+wt,neigh});
//                 }
//             }
//         }
//         int ans =0;
//         for(int i = 1; i<=n;i++){
//             if(dist[i]==INT_MAX)
//                 return -1;
//             ans=max(ans,dist[i]);
//         }
//         return ans;
//     }
// };







class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto &vec:times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<int> result(n+1,INT_MAX);

        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node]){
                int adjNode = vec.first;
                int dist = vec.second;

                if(d+dist <result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }        
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans= max(ans, result[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
























