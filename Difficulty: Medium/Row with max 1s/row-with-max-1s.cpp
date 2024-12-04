//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Function to find the lower bound of x in a sorted array
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Function to find the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();       // Number of rows
        if (n == 0) return -1;    // If matrix is empty, return -1
        int m = arr[0].size();    // Number of columns

        int cnt_max = 0;          // Maximum count of 1s found so far
        int index = -1;           // Index of the row with the maximum 1s

        for (int i = 0; i < n; i++) {
            // Count the number of 1s in the current row
            int cnt_ones = m - lowerBound(arr[i], m, 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends