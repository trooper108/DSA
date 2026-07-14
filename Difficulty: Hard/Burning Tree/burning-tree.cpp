/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* markParents(Node* root,unordered_map<Node*,Node*> &parent,int start){
        queue<Node*> q;
        q.push(root);
        Node* target;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
            if(node->data == start){
                target = node;
            }
        }
        return target;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parent;
        Node* targetNode = markParents(root,parent,target);
        
        unordered_map<Node*,bool>visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            level++;
        }
        return level-1;
    }
};