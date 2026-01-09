/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    void inOrder(Node* root, vector<int>& res){
        if(root == NULL) return;
        
        inOrder(root->left, res);
        res.push_back(root->data);
        inOrder(root->right, res);
        
    }
    
    
    vector<int> inOrder(Node* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};