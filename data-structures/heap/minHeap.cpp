#include <heap.cpp>

class MinHeap : public Heap{
    private:
        void heapify(int index){
            /* So the point of heapify is to make sure
              * each child node is smaller/larger than its parents
              * for min and max heapify */
            int left = getLeftChildIndex(index);
            int right = getRightChildIndex(index);
            int smallestVal = index;
            // Check if heap condition is met by left and right child
            if (left != NULL && data[left] < data[index]){
                smallestVal = left;
            }
            if (right != NULL && data[right] < data[index]){
                smallestVal = right;
            }
            // If not swap, larger child with root and check the new subtree
            if (smallestVal != index){
                swap(index, smallestVal);
                heapify(smallestVal);
            }
        }

    public:
        MinHeap(std::vector<int> data) : Heap(data){};

        void insert(int key){
            // Add new element to the end
            this->data.push_back(key);
             int newKeyIndex = this->data.size();
            int parentIndex = getParentIndex(newKeyIndex);  
            // Compare parent to new key and swap to maintain heap
            while(this->data[parentIndex] < key && newKeyIndex > 0){
                swap(parentIndex, newKeyIndex);
                newKeyIndex = parentIndex;
                parentIndex = getParentIndex(newKeyIndex);
            }
        }
};