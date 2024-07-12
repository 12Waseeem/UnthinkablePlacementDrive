#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int additions = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // Matching pair found
                } else {
                    additions++; // No matching '(' for this ')'
                }
            }
        }

        // Add remaining '(' in the stack to additions count
        additions += st.size();

        return additions;
    }
};
