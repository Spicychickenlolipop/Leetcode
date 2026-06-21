// story points:
// 1.when new element comes nums[i], make space for in (window size cant be greater than k)
// 2.now, when nums[i] comes, there is no need to keep small elements in that window, pop them
// 3.Now push i in deque-> for nums[i]
// 4.if (i<k-1), then deq.front() is our answer for that window

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>deq;
        vector<int> result;
        for(int i = 0;i<n;i++){
            //step1 make space for nums[i]
            while(!deq.empty() && deq.front()<=i-k){
                deq.pop_front();
            }
            //step2
            while(!deq.empty() && nums[i]>nums[deq.back()]){
                deq.pop_back();
            }
            //step3
            deq.push_back(i);
            
            //step4
            if(i>=k-1){
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};