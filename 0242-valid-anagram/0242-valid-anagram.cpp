class Solution {
public:
    bool isAnagram(string s, string t) {
        int ssize = s.length();
        int tsize = t.length();
        if(ssize != tsize)
            return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i=0;i<ssize;i++){
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};