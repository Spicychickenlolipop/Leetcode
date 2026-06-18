class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int x:nums)
            totalSum += x;
        if(abs(target)>totalSum)
            return 0;
        if((totalSum+target)%2)
            return 0;
        int sum = (totalSum+target)/2;
        int n = nums.size();
        int i,j;
        vector<vector<int>>dp(n+1);
        for(i=0;i<=n;i++){
            vector<int>t(sum+1,0);
            dp[i]=t;
        }
        dp[n][0]=1;
        for(i=n-1;i>=0;i--){
            for(j=0;j<=sum;j++){
                if(nums[i]>j)
                    dp[i][j]=dp[i+1][j];
                else
                    dp[i][j]=dp[i+1][j-nums[i]]+dp[i+1][j];
            }
        }
        return dp[0][sum];
    }
};