class Solution {
public:
    
    //Approach-2
    vector<int> search_stl(vector<int>& nums, int target) {
        //first element equal to or greater than target
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //first element greater than target
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //Why do we need this (nums[l] != target) ? 
        //Because lower_bound returns first element which is equal or GREATER THAN target.
        //So, in case the target is not in the list, it will return first greater element than target which will be wrong
        if(l == nums.size() || nums[l] != target)
            return {-1, -1};
        
        return {l, r-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return search_stl(nums, target); //Approach - 2
    }
};