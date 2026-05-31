class Solution {
public:

    int fun(unordered_map<char, int>& have,
            unordered_map<char, int>& need){
        int res = INT_MAX;

        for(auto it: need){
            char ch = it.first;

            int freqNeed = it.second;
            int freqHave = have[ch];

            int times = freqHave/freqNeed;

            res = min(res,times); 
        }
        return res;
    }

    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;

        for(int i = 0; i< text.size(); i++){
            have[text[i]]++;
        }

        unordered_map<char,int> need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        
        return fun(have, need);
    }
};