class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;
        unordered_map<char,int> freeTime;

        for(char ch : tasks) {
            freq[ch]++;
            freeTime[ch] = 1;   // initially all tasks available
        }

        priority_queue<pair<int,char>> pq;

        for(auto &it : freq) {
            pq.push({it.second, it.first});
        }

        int time = 1;

        while(!pq.empty()) {

            vector<pair<int,char>> pulled;
            bool scheduled = false;

            while(!pq.empty()) {

                auto curr = pq.top();
                pq.pop();

                int cnt = curr.first;
                char task = curr.second;

                if(freeTime[task] <= time) {

                    cnt--;

                    if(cnt > 0)
                        pq.push({cnt, task});

                    freeTime[task] = time + n + 1;

                    scheduled = true;
                    break;
                }
                else {
                    pulled.push_back(curr);
                }
            }

            for(auto &x : pulled)
                pq.push(x);

            time++;
        }

        return time - 1;
    }
};