/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void preOrder(Node*root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->data);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    vector<int> preOrder(Node* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
        
    }
};