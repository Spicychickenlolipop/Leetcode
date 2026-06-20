// //Prefix/Suffix Array Pattern
// class Solution {
// public:
//     vector<int> getLeftMaxArray(vector<int>& height, int& n){
//         vector<int> leftMax(n);
//         leftMax[0] = height[0];

//         for(int i=1;i<n;i++){
//             leftMax[i] = max(leftMax[i-1],height[i]);
//         }
//         return leftMax;
//     }
//     vector<int> getRightMaxArray(vector<int>& height, int& n){
//         vector<int> rightMax(n);
//         rightMax[n-1] = height[n-1];

//         for(int i=n-2;i>=0;i--){
//             rightMax[i] = max(rightMax[i+1],height[i]);
//         }
//         return rightMax;
//     }

//     int trap(vector<int>& height) {
//         int n = height.size();

//         vector<int> leftMax = getLeftMaxArray(height, n);
//         vector<int> rightMax = getRightMaxArray(height,n);

//         int sum = 0;

//         for(int i=0;i<n;i++){
//             int h = min(leftMax[i], rightMax[i])-height[i];
//             sum += h;
//         }
//         return sum;
//     }
// };


//two pointer
class Solution{
    public:
        int trap(vector<int>& height){
            int n=height.size();
            int left = 0;
            int right = n-1;

            int leftMax = 0;
            int rightMax = 0;

            int sum = 0;

            while(left<right){
                if(height[left]<height[right]){
                    if(height[left]>=leftMax){
                        leftMax = height[left];
                    }else{
                        sum += leftMax - height[left];
                    }
                    left++;
                }else{
                    if(height[right]>=rightMax){
                        rightMax = height[right];
                    }else{
                        sum += rightMax - height[right];
                    }
                    right--;
                }
            }
            return sum;
        }
};