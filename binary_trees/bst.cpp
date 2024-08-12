#include <iostream>
#include <vector>

// typedef struct node {
//     int val;
// } node_t;

class binarySearchTree{
    private:
        int val;
        binarySearchTree* left;
        binarySearchTree* right;

    public:
        binarySearchTree(int val){
            this->left = nullptr;
            this->right = nullptr;
            this->val = val;
        }
        // insert, delete, and search
        void insert(binarySearchTree* node){
            bool isLeft = this->val < node->val;
            bool isNull = isLeft ? 
                this -> left == nullptr : 
                this -> right == nullptr;
            if(isLeft && isNull){
                this -> left = node;
            }
            else if (isLeft && !isNull){
                left->insert(node);
            }
            else if(!isLeft && isNull){
                this -> right = node;
            }
            else if (!isLeft && !isNull){
                right->insert(node);
            }
        }

        void remove(int val){
            binarySearchTree* node = this->search(val);
            if(node !=nullptr){
                // What the hell is this
            }
        }

        binarySearchTree* search(int key){
            // Check left child exists and matches
            if(this->left != nullptr){
                return  this->left->val == key ? 
                    this->left :
                    this->left->search(key);
            } 
            // Check right child exists and matches
            else if(this->right != nullptr){
                return  this->right->val == key ? 
                    this->right :
                    this->right->search(key);
            }
            // If neither exist, then return failure
            return nullptr;
        }
};