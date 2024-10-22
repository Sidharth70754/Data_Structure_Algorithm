//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> prefixSumMap; 
        int maxi = 0; 
        int sum = 0;  

        for (int i = 0; i < n; i++) {
            sum += arr[i];

           
            if (sum == 0) {
                maxi = i + 1;
            }

            
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxi = max(maxi, i - prefixSumMap[sum]);
            } else {
               
                prefixSumMap[sum] = i;
            }
        }

        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends