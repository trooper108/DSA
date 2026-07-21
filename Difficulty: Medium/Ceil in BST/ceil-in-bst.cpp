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
        int ans = INT_MAX;
        Node* temp = root;
        while(root != NULL){
            if(root->data == x){
                return x;
            }
            else if(root->data > x){
                ans = min(ans,root->data);
            }
            if(root->data > x){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
