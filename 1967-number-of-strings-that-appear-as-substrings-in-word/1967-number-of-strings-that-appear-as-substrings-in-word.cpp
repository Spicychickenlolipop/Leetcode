// Approach 1: Using string::find() (Simplest)
// Time Complexity: O(n × m × k)
// Space Complexity: O(1)
// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {
//         int count = 0;
//         for(int i=0;i<patterns.size();i++){
//             if(word.find(patterns[i])!=-1)
//                 count++;
//         }
//         return count;
//     }
// };





class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string pattern : patterns){
            int m = pattern.size();
            if(m > word.size())
            continue;
            bool found = false;

            for(int i = 0; i<=word.size()-m;i++){
                int j = 0;
                while(j < m && word[i + j] == pattern[j]) {
                    j++;
                }
                if(j==m){
                    found = true;
                    break;
                }
            }
            if(found)
                count++;
        }
        return count;
    }
};