/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* inorderPredecessor(Node* root ,int key){
        Node* predecessor = NULL;
        while(root){
            if(key <= root->data){
                root = root->left;
            }
            else{
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
    Node* inorderSuccessor(Node* root ,int key){
        Node* successor = NULL;
        while(root){
            if(key >= root->data){
                root = root->right;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* predecessor = inorderPredecessor(root,key);
        Node* successor = inorderSuccessor(root,key);
         
         return {predecessor,successor};
        
    }
};