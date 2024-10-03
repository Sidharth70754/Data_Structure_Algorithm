//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the leaders in the array.
    vector<int> leaders(int n, int arr[]) {
        vector<int> ns; // To store the leaders
        int maxi = INT_MIN;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ns.push_back(arr[i]); // Add current element as a leader
            }
            maxi = max(maxi, arr[i]);
        }

        // The leaders are collected in reverse order, so we reverse the vector
        reverse(ns.begin(), ns.end());

        return ns; 
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends