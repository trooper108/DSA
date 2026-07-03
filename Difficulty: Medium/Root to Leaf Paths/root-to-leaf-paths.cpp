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
  
  
  void path(Node* root,vector<vector<int>>&ans,vector<int>tmp){
      if(root == NULL){
          return;
      }
      if(root->left == NULL && root->right == NULL){
          tmp.push_back(root->data);
          ans.push_back(tmp);
          return;
      }
      tmp.push_back(root->data);
      path(root->left,ans,tmp);
      
      path(root->right,ans,tmp);
      
  }
  
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int>tmp;
        if(root == NULL){
            return ans;
        }
        path(root,ans,tmp);
        return ans;
    }
};