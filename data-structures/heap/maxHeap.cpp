#include <heap.cpp>

class MaxHeap : public Heap{
    private:
        void heapify(int index){
            /* So the point of heapify is to make sure
              * each child node is smaller/larger than its parents
              * for min and max heapify */
            int left = getLeftChildIndex(index);
            int right = getRightChildIndex(index);
            int largestVal = index;
            // Check if heap condition is met by left and right child
            if (left != NULL && data[left] > data[index]){
                largestVal = left;
            }
            if (right != NULL && data[right] > data[index]){
                largestVal = right;
            }
            // If not swap, larger child with root and check the new subtree
            if (largestVal != index){
                swap(index, largestVal);
                heapify(largestVal);
            }
        }

    public:
        MaxHeap(std::vector<int> data) : Heap(data){};

        int extractRoot(){
            // Retrieve root and make last element root
            int root = this->data[0];
            swap(this->data.size() - 1, 0);
            this->data.pop_back(); // Don't forget to shrink the heap
            // Rebuild the heap
            heapify(0);
            return root;
        }

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