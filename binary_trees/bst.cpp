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
        void insert(node_t *newNode);
        node_t* removeNode(int val);

        // Find min/max
        node_t* find(int val);
        node_t *findMin(node_t *root);
        node_t *findMax(node_t *root);

        // Traversal methods
        void inorderTraversal(node_t *root);
        void preorderTraversal(node_t *root);
        void postorderTraversal(node_t *root);
};