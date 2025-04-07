//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        for(int i = 0; i < exp.size(); i++){
            char ch = exp[i];
            if(isalnum(ch)){
            st.push(string(1, ch));
        }
        else {
            string op1 = st.top();  st.pop();
            string op2 = st.top();  st.pop();
            string temp = '(' + op2 + ch + op1 + ')';
            st.push(temp);
        }
        }
        return st.top();

    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends