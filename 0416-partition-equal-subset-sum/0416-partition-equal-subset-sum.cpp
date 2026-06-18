class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums)
            totalSum += x;

        if(totalSum % 2)
            return false;
        int sum = totalSum/2;
        int n = nums.size();
        int i,j;
        vector<vector<int>>dp(n+1);
        for(i=0;i<=n;i++){
            vector<int>t(sum+1,0);
            dp[i]=t;
        }
        for(j=0;j<=sum;j++)
            dp[n][j]=0;
        dp[n][0]=1;
        for(i=n-1;i>=0;i--){
            for(j=0;j<=sum;j++){
                if(nums[i]>j)
                    dp[i][j]=dp[i+1][j];
                else
                    dp[i][j]=dp[i+1][j-nums[i]]||dp[i+1][j];
            }
        }
        return dp[0][sum];
    }
};