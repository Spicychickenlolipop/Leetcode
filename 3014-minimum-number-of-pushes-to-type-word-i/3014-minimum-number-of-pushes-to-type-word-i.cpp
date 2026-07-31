// class Solution {
// public:
//     int minimumPushes(string word) {
//         int result = 0;
//         unordered_map<int, int> mp;

//         int assign_key = 2;
//         for(char &ch : word){
//             if(assign_key > 9){
//                 assign_key = 2;
//             }

//             mp[assign_key]++;
//             result += mp[assign_key];

//             assign_key++;
//         }
//         return result;
//     }
// };










class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);

        for(char &ch : word){
            mp[ch-'a']++;  
        }

        sort(begin(mp),end(mp),greater<int>());

        int result = 0;

        for(int i = 0; i<26;i++){
            int freq = mp[i];
            int press = i/8+1;

            result += press * freq;
        }
        return result;
    }
};