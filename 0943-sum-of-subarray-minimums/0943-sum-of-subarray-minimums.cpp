class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n, -1);
        int mod = 1e9 + 7;

        for(int i = 0 ; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >=  0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
      
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }

        return total;
    }
};
