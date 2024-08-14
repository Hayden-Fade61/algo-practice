#include <iostream>

class bst{
    typedef struct node {
        int val;
        node* left;
        node* right;
        node(){
            val = 0;
            left = nullptr;
            right = nullptr;
        }
        node(int data){
            val = data;
            left = nullptr;
            right = nullptr;
        }
    } node_t;

    private:
        node_t* root;
    
    public:
        bst(){
            this -> root = nullptr;
        }
        bst (int data){
            this  ->  root = new node(data);
        }
        node_t* getRoot() {return this -> root;}

        // Insert / Delete 
        void insert(node_t* root, int newVal){
            if (root -> val == newVal) return; // No duplicates
            bool goLeft = root -> val < newVal;
            if (goLeft && root -> left == nullptr) root -> left = new node(newVal); 
            else if (goLeft && root -> left != nullptr) insert(root -> left, newVal); 
            else if (!goLeft && root -> right == nullptr) root -> right = new node(newVal); 
            else insert(root -> right, newVal); 
        }

        node_t* remove(node_t *root, int key){
            node_t* toDelete = root;
            node_t* parent = nullptr;
            bool isLeft = false;
            // Find value if it exists in the tree
            while(toDelete -> val != key && toDelete != nullptr){
                if (toDelete -> val < key){
                    parent = toDelete;
                    toDelete = toDelete -> left;
                }
                else{
                    parent = toDelete;
                    toDelete = toDelete -> right;
                }
            }
            if (toDelete == nullptr) return nullptr;
            // 0 child, just delete the node
            if(toDelete->left == nullptr && toDelete->right == nullptr){
                return toDelete;
            }
            // 1 child, replace toDelete with child
            else if(toDelete->left == nullptr || toDelete->right == nullptr){
                node_t *child = toDelete->left == nullptr ? toDelete->left : toDelete->right;
                if(parent -> left == toDelete) parent->left = child;
                else parent->right = child;
                return toDelete;
            }
            // 2 children, replace with inorder successor
            else{
                node_t* successor = findMax(toDelete->left);
                successor->left = toDelete->left; 
                successor->right = toDelete->right;
                if(parent->val < successor->val){
                    parent->right = successor;
                }
                else{
                    parent->left = successor;
                }
            }  
        }

        // Find methods
        node_t* find(node_t* root, int key){
            if(root == nullptr) return nullptr;
            if(root -> val == key) return root;
            else if(key > root -> val) return find(root -> right, key);
            else return find(root -> left, key);
        }

        node_t* findMin(node_t* root){
            if(root -> left == nullptr) return root;
            findMin(root -> left);
        }

        node_t* findMax(node_t* root){
            if(root -> right == nullptr) return root;
            findMax(root -> right);
        }

        // Traversal methods
        void inorderTraversal(node_t* root){
            if (root != nullptr){
                inorderTraversal(root -> left);
                std::cout << root << std::endl;
                inorderTraversal(root -> right);
            }
        }

        void preorderTraversal(node_t* root){
            if (root != nullptr){
                std::cout << root << std::endl;
                inorderTraversal(root -> left);
                inorderTraversal(root -> right);
            }
        }

        void postorderTraversal(node_t* root){
            if (root != nullptr){
                    inorderTraversal(root -> left);
                    inorderTraversal(root -> right);
                    std::cout << root << std::endl;
                }
        }
};