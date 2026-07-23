class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        if(n<3){
            return n;
        }   
        for(auto it:nums){
            int p=log2(it);
            mx = max(mx,p);
        }

        return (1LL<<(mx+1));
    }
};