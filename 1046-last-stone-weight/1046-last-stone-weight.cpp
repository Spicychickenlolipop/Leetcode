class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>=2){
            auto a= pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if(a==b)continue;
            else{
                pq.push(a-b);
            }
        }
        if(pq.empty())return 0;
            return pq.top();
    }
};