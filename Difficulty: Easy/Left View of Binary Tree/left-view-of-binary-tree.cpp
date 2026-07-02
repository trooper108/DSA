/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(root == NULL){
            return {};
        }
        queue<pair<Node*,int>> q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int dp = p.second;
            if(mp.find(dp) == mp.end()){
                mp[dp] = node->data;
            }
            if(node->left){
                q.push({node->left,dp+1});
            }
            if(node->right){
                q.push({node->right,dp+1});
            }
        }
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};