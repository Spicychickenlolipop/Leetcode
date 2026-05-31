class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for (char ch : ransomNote) {
            need[ch]++;
        }

        for (char ch : magazine) {
            have[ch]++;
        }

        for (auto &it : need) {
            char ch = it.first;
            int freqNeed = it.second;

            if (have[ch] < freqNeed) {
                return false;
            }
        }

        return true;
    }
};