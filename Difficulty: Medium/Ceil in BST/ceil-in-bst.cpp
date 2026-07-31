/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(root == NULL){
            return -1;
        }
        int ans = -1;
        Node* temp = root;
        while(root != NULL){
            if(root->data == x){
                return x;
            }
            if(root->data > x){
                ans = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ans;
    }
};
