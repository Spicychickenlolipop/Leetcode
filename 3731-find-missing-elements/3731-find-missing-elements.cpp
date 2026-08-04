class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        unordered_set<int>st;

        //find min, max and store elements
        for(int x : nums){
            mn = min(mn, x);
            mx = max(mx, x);
            st.insert(x);
        }

        vector<int>ans;

        //check missing numbers in range
        for(int i = mn+1; i<mx; i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};