class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result = "";

        int n = s.length();

        if(n == 0) return "";

        st.push(s[0]);

        for(int i = 1; i < n; i++) {
            char currentChar = s[i];

            if(!st.empty() && currentChar == st.top()) {
                st.pop();
            } 
            else {
                st.push(currentChar);
            }
        }

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};