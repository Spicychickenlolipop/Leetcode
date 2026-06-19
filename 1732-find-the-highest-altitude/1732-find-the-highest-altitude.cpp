class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            int altitude = 0;
            for(int j = 0;j<=i;j++){
                altitude += gain[j];
            }
            ans=max(ans,altitude);
        }
        return ans;
    }
};