// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int ssize = s.length();
//         int tsize = t.length();
//         if(ssize != tsize)
//             return false;

//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());

//         for(int i=0;i<ssize;i++){
//             if(s[i]!=t[i])
//                 return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count (26,0);
        
        for(char &ch : s){
            count[ch-'a']++;
        }
        for(char &ch : t){
            count[ch-'a']--;
        }

        bool allZeros = all_of(begin(count),end(count), [](int element){
            return element == 0;
        });
        
        return allZeros;
    }
};