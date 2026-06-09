class Solution {
public:
    unordered_map<char,string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void fun(string &digits, int n, int idx,
             string &diary,
             vector<string> &res) {

        if(idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = mp[digits[idx]];

        for(int j = 0; j < choice.size(); j++) {

            diary.push_back(choice[j]);      // choose

            fun(digits, n, idx + 1,
                diary, res);                 // explore

            diary.pop_back();                // unchoose
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        int n = digits.size();

        vector<string> res;
        string diary = "";

        fun(digits, n, 0, diary, res);

        return res;
    }
};