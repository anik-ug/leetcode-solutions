/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node*leftMost = root;
        while(leftMost->left!=NULL){
            Node* curr = leftMost;
            while(curr!=NULL){
                //connect sibling
                curr->left->next = curr->right;

                //connect accross parents
                if(curr->next!=NULL){
                    curr->right->next = curr->next->left;
                }

                //move horizontal
                curr = curr->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }
};