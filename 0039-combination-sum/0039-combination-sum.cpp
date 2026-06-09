class Solution {
public:

    void fun(vector<int>& a,int n,int idx,vector<int>& diary,int sum, vector<vector<int>>& res,int target){
        if(idx==n){
            if(sum==target)
                res.push_back(diary);
            return;
        }
        //choice1: dont take
        fun(a,n,idx+1,diary,sum, res, target);
        //choice2: take
        if(sum+a[idx]<=target){
            diary.push_back(a[idx]);

            fun(a,n,idx,diary,sum+a[idx],res, target);
            diary.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int>diary;

        fun(candidates,n,0,diary,0,res,target);
        return res;
    }
};