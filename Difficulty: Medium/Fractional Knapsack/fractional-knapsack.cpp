//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratio(n); // {value/weight, index}

        for (int i = 0; i < n; i++) {
            ratio[i] = { (double)val[i] / wt[i], i };
        }

        // Sort in descending order of value-to-weight ratio
        sort(ratio.rbegin(), ratio.rend());

        double finalValue = 0.0;
        int curWeight = 0;

        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;

            if (curWeight + wt[idx] <= capacity) {
                curWeight += wt[idx];
                finalValue += val[idx];
            } else {
                int remain = capacity - curWeight;
                finalValue += (double)val[idx] / wt[idx] * remain;
                break;
            }
        }
        return finalValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends