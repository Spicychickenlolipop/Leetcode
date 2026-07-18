class Solution {
public:
    int fun_gcd(int a, int b){//O(log M)
        if(b==0)return a;
        return fun_gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int greatest = *max_element(nums.begin(), nums.end());

        return fun_gcd(smallest,greatest);
    }
};