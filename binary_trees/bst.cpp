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
            this -> root = new node(data);
        }
        node_t* getRoot() {return this->root;}

        // Insert / Delete / Find
        void insert(int val);
        void insert(node_t* newNode);
        node_t* removeNode(int val);

        // Find methods
        node_t* find(node_t* root, int key){
            if(root == nullptr) return nullptr;
            if(root -> val == key) return root;
            else if(key > root -> val) return find(root->right, key);
            else return find(root->left, key);          
        }

        node_t* findMin(node_t* root){
            if(root->left == nullptr) return root;
            findMin(root->left);
        }

        node_t* findMax(node_t* root){
            if(root->right == nullptr) return root;
            findMax(root->right);
        }

        // Traversal methods
        void inorderTraversal(node_t* root){
            if (root != nullptr){
                inorderTraversal(root->left);
                std::cout << root << std::endl;
                inorderTraversal(root->right);
            }
        }

        void preorderTraversal(node_t* root){
            if (root != nullptr){
                std::cout << root << std::endl;
                inorderTraversal(root->left);
                inorderTraversal(root->right);
            }
        }

        void postorderTraversal(node_t* root){
            if (root != nullptr){
                    inorderTraversal(root->left);
                    inorderTraversal(root->right);
                    std::cout << root << std::endl;
                }
        }
};