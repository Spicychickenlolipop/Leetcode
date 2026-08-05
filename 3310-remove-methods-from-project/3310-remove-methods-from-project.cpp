class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &it : invocations){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool>removed(n,false);

        function<void(int)>dfs = [&](int node){
            removed[node] = true;
            for(int nei : adj[node]){
                if(!removed[nei]) dfs(nei);
            }
        };

        dfs(k);

        for(int i =0;i<n;i++){
            if(!removed[i]){
                for(int nei : adj[i]){
                    if(removed[nei]){
                        vector<int>ans(n);
                        iota(ans.begin(), ans.end(),0);
                        return ans;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i<n ; i++){
            if(!removed[i])ans.push_back(i);
        }
        return ans;
    }
};