class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //first take row wise cumulative sum
        for(int row=0; row<rows; row++){
            for(int col=1; col<cols;col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        //Now, you need to find the no. of subarray with sum == target(leetcode 560)===> downwards direction
        int result=0;

        for(int startCol =0; startCol< cols; startCol++){
            for(int j= startCol; j<cols;j++){

                unordered_map<int, int>mp;
                mp.insert({0,1});
                int cumSum = 0;

                for(int row=0; row<rows; row++){
                    cumSum += matrix[row][j] - (startCol>0 ? matrix[row][startCol-1]:0);

                    if(mp.find(cumSum-target)!=mp.end()){
                        result += mp[cumSum - target];
                    }
                    mp[cumSum]++;
                }
            }
        }
        return result;
    }
};