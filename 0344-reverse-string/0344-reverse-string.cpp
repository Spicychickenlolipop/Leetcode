class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            st.push(ch);
        }

        for(int i=0; i<s.size();i++){
            s[i]=st.top();
            st.pop();
        }
    }
};