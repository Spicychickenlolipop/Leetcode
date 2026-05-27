class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       // vector<int> left(n,0);
       // vector<int> right(n,0);
       int i;
       int sum=0;
       for(i=0;i<n;i++)
       sum+=nums[i];
       int left=0;

       for(i=0;i<n;i++)
       {
           int right=sum-left-nums[i];
           if(left==right)
           return i;

           left=left+nums[i];
       }
       return -1;
    }
};