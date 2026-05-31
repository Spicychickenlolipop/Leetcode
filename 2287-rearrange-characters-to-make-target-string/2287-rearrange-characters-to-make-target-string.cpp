class Solution {
public:

    int fun(unordered_map<char,int>& have,
            unordered_map<char,int>& need){
        
        int res = INT_MAX;
        
        for(auto it : need){
            char ch = it.first;

            int freqNeed = it.second;
            int freqHave = have[ch];

            int times= freqHave/freqNeed;
            res = min(res, times);
        }
        return res;
    }

    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(char ch : s){
            have[ch]++;
        }
        for(char ch : target){
            need[ch]++;
        }

        return fun(have, need);
    }
};