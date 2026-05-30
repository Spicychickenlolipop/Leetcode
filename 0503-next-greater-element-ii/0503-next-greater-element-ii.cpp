class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = n - 2; i >= 0; i--)
            st.push(i);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty() and nums[st.top()] > nums[i])
                ans[i] = nums[st.top()];
            st.push(i);
        }

        return ans;
    }
};