//Brute force{o(n2)}

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int i, j;
//         for(i=0;i<nums.size();i++){
//             for(j=i+1;j<nums.size();j++){
//                 if(nums[i]==nums[j])
//                     return true;
                
//            }
//         }
//         return false;
//     }
// };


//sorting

// class Solution {//tc (o(nlogn))
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1])
//                 return true;
//         }
//         return false;
//     }
// };



class Solution {//tc (o(n))
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int x : nums){
            if(s.find(x) != s.end())
                return true;
            s.insert(x);
        }
        return false;
    }
};