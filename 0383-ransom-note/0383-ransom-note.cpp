class Solution {
public:
    bool fun(unordered_map<char, int>& have,
             unordered_map<char, int>& need) {

        for (auto it : need) {
            char ch = it.first;
            int freqNeed = it.second;
            int freqHave = have[ch];

            if (freqHave < freqNeed) {
                return false;
            }
        }

        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for (int i = 0; i < ransomNote.size(); i++) {
            need[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            have[magazine[i]]++;
        }

        return fun(have, need);
    }
};