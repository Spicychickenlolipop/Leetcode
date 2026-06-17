class Solution {
public:
    unordered_map<int,int>dp;
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp.find(n)!=dp.end())
            return dp[n];
        int ans1 = fib(n-1);
        int ans2 = fib(n-2);\
        int ans = ans1+ans2;
            dp[n]=ans;
        return ans;
    }
};