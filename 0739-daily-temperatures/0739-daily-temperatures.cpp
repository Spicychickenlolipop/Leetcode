class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> answer(length);
        stack<int>S;
        S.push(0);
        for(int i=1; i<length;i++){
            //int curr = S.top();
            while(!S.empty() && temperatures[S.top()]<temperatures[i]){
                answer[S.top()]=(i-S.top());
                S.pop();
                //curr=S.top();
            }
            S.push(i);
        }
        return answer;
    }
};