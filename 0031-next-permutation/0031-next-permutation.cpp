class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;

        //find first decreaing element from the right
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }

        //if a next permutation exists
        if(i>=0){
            int j = n-1;

            //Find the smallest elememt greater than nums[i]
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};