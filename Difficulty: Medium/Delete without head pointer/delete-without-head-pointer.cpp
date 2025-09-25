/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
public:
    void deleteNode(Node* del_node) {
        if (del_node == nullptr || del_node->next == nullptr) return; // safety check

        Node* temp = del_node->next;
        del_node->data = temp->data;
        del_node->next = temp->next;
        delete temp;  // free memory to avoid leak
    }
};
