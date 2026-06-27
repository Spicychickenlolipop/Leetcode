class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        int maxi = 1;

        if(count.count(1)){
            int ones = count[1];
            if(ones%2==0){
                ones--;
            }
            maxi = max(maxi, ones);
        }
        for(auto &it : count){
            int x = it.first;
            if(x==1)
                continue;
            int currentLen=0;
            long long curr = x;
            
            while (curr <= 1000000000LL &&
                   count.count((int)curr) &&
                   count[(int)curr] >= 2) {

                currentLen += 2;
                curr = curr * curr;
            }
            if(curr<= 1000000000LL &&
                count.count((int)curr)&&
                count[(int)curr]>0){
                    currentLen += 1;
                }else{
                    currentLen -= 1;
                }
                maxi = max(maxi, currentLen);
        }
        return maxi;
    }
};