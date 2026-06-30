// class Solution {
// public:
//     bool res = true;
//     void dfs(vector<vector<int>> & a, int node,int c, vector<int>& colors){
//         colors[node]=c;
//         for(int j=0;j<a[node].size();j++){
//             int neigh=a[node][j];
//             if(colors[neigh] !=-1 && colors[neigh]==c)
//                 res= false;
//             if(colors[neigh]==-1)
//                 dfs(a,neigh,1-c,colors);
//         }
//         return;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int  n= graph.size();
//         vector<int>colors(n,-1);
//         for(int i=0;i<n;i++){
//             if(colors[i]==-1)
//                 dfs(graph,i,0,colors);
//         }
//         return res;
//     }
// };

////////////codestorywithMIK//////
//bfs

class Solution{
public: 
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int>& color,int currColor){
        queue<int>que;
        que.push(curr);
        color[curr]=currColor;
        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v: adj[u]){
                if(color[v]==color[u])
                    return false;
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>&adj){
        int V = adj.size();
        vector<int> color(V,-1);///no one is colored as of now(no one is visited)
        //red=1
        //green=0
        for(int i = 0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartiteBFS(adj,i,color,1)==false)
                    return false;
            }
        }
        return true;
    }
};

