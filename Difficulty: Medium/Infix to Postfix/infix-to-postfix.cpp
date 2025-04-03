//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to return precedence of operators
    int priority(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/' || c == '%') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            // If operand, add to result
            if (isalnum(c)) {
                ans += c;
            }
            // If '(', push to stack
            else if (c == '(') {
                st.push(c);
            }
            // If ')', pop and add to result until '(' is found
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Remove '(' from stack
            }
            // Operator
            else {
                while (!st.empty() && priority(c) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends