class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(char c : tasks) mp[c]++;
        for(auto &pair : mp) pq.push({pair.second,pair.first});
        int c = 0;

        while(!pq.empty()){
            int cycle = n+1;
            vector<pair<int,char>> q;
            while(cycle-- && !pq.empty()){
                int f = pq.top().first;
                int top = pq.top().second;
                pq.pop();
                if(f-1>0) q.push_back({f-1,top});
                c++;
            }
            for(auto &pair : q) pq.push(pair);
            if(!pq.empty()) c+= cycle+1;
        }
        return c;
    }
};