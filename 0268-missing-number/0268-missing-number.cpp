class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int target = 0; target <= n; target++) {
            bool found = false;

            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return target;
            }
        }

        return -1;
    }
};