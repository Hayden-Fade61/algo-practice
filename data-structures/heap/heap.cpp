#include <iostream>
#include <vector>

class Heap {
    protected:
        std::vector<int> data;

        // Abstract functions
        // This is a pure virtual function, causes this class to be regarded as abstract
        virtual void heapify(int index) = 0;

        // Non-abstract functions

        int getParentIndex(int index){
            if (index == 0) return NULL;
            else  return (int) index / 2; 
        }

        int getLeftChildIndex(int index){
            if (2*index <= this->data.size()) return 2*index;
            else return NULL;
        }

        int getRightChildIndex(int index){
            if (2*index+ 1 <= this->data.size()) return 2*index + 1;
            else return NULL;
        }

        /* Swap data at index A and index B */
        void swap(int indexA, int indexB){
            /* Contemplated an XOR swap but I've learned
            * It's not that much faster than a temp variable
            * on modern hardware */
            int temp = data[indexA];
            data[indexA] = data[indexB];
            data[indexB] = temp; 
        }

        // Construct the heap
        void buildHeap(){
            /* Run heapify() for the first half of the array 
            * the second half of the array is all leaf nodes */  
            for (int i = 0; i < (int) data.size() / 2; i++){
                heapify(i);
            }
        }
        
    public:
        // Constructors
        Heap(std::vector<int> data){
            this->data = data;
            buildHeap();
        }

        // Abstract functions
        virtual int extractRoot() = 0;

        virtual void insert(int key) = 0;
};