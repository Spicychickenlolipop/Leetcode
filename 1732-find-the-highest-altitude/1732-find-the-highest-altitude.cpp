class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int ans = 0;
        for(int i=0;i<gain.size();i++){
            int x = gain[i];
            altitude += x;
            ans = max(ans, altitude);
        }
        return ans;
    }
};