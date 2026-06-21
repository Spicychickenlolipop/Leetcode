// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>res;

//         int l = 0;
//         int r = nums.size()-1;

//         while(l<r){
//             int sum = nums[l]+nums[r];

//             if(sum==target){
//                 res.push_back(l+1);
//                 res.push_back(r+1);
//                 break;
//             }else if(sum<target){
//                 l++;
//             }else if(sum>target){
//                 r--;
//             } 
//         }
//         return res;
//     }
// };


//two pointer easy

class Solution{
public:
    vector<int>twoSum(vector<int>& numbers, int target){
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target)
                return{i+1,j+1};
            if(numbers[i]+numbers[j]>target)
                j--;
            if(numbers[i]+numbers[j]<target)
                i++;
        }
        return{};
    }
};