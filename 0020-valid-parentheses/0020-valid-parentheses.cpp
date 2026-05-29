class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Push expected closing bracket
            if(ch == '(') {
                st.push(')');
            }
            else if(ch == '{') {
                st.push('}');
            }
            else if(ch == '[') {
                st.push(']');
            }
            else {

                // Closing bracket case
                if(st.empty() || st.top() != ch) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};