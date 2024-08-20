#include <iostream>
#include <vector>

class Heap {
    private:
        std::vector<int> data;
    public:
        Heap(std::vector<int> data){
            this->data = data;
        }
        
        void minHeapify(){
            // Make a minheap
        }

        void maxHeapify(){
            // make a maxheap
        }

        int extract(){
            // Retrieve the root value of the heap and return it
        }
};