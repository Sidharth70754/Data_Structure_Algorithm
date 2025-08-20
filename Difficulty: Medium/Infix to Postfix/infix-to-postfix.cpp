class Solution {
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }
public:
    string infixToPostfix(string &s) {
        string ans;
        stack<char> st;

        for (char ch : s) {
            if (ch == ' ') continue;

            if (isalnum(ch)) {
                ans += ch;                         // operand → output
            } else if (ch == '(') {
                st.push(ch);                       // '(' → push
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top(); st.pop();     // pop till '('
                }
                if (!st.empty()) st.pop();         // pop '('
            } else {                                // operator
                // LEFT-associative for '^' as per your judge: pop on >= precedence
                while (!st.empty() && st.top() != '(' &&
                       prec(st.top()) >= prec(ch)) {
                    ans += st.top(); st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty()) { ans += st.top(); st.pop(); }
        return ans;
    }
};

