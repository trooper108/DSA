/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                Node* node = q.front();
                q.pop();
                bool flag = false;
                int sum = 0;
                if(node->left){
                    flag = true;
                    sum += node->left->data;
                    q.push(node->left);
                }
                if(node->right){
                    flag = true;
                    sum += node->right->data;
                    q.push(node->right);
                }
                if(flag && sum != node->data){
                    return false;
                }
            }
        }
        return true;
    }
};