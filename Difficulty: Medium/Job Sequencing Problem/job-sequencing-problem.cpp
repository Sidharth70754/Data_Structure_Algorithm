//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job {
    int id, deadline, profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit; // Sort by profit in descending order
}

class Solution {
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        vector<Job> jobs;
        
        for (int i = 0; i < n; i++)
            jobs.push_back({id[i], deadline[i], profit[i]});

        sort(jobs.begin(), jobs.end(), comp);

        int maxDeadline = 0;
        for (auto &job : jobs)
            maxDeadline = max(maxDeadline, job.deadline);

        vector<bool> slot(maxDeadline + 1, false);
        vector<int> ans(2, 0); // ans[0] = job count, ans[1] = max profit

        for (auto &job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    ans[0]++; 
                    ans[1] += job.profit;
                    break;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends