class Solution {
public:
    vector<int>topologicalSort(unordered_map<int, vector<int>>&adj, int n, vector<int>& indegree){
        queue<int>que;
        vector<int>result;
        int count=0;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                result.push_back(i);
                count++;
                que.push(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }
        if(count==n)
            return result;
        //means we had a cycle and we couldn't complete all courese(visite all nodes)
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;

        vector<int>indegree(numCourses, 0);//kahn's algo

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            //{a,b}
            //b-->a
            adj[b].push_back(a);
            //arrow -> 'a' me ja raha hai
            indegree[a]++;
        }
        return topologicalSort(adj, numCourses, indegree);

    }
};