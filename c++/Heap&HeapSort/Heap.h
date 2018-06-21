#pragma once

class Heap
{
    private:
        int *arr;
        int capacity;
        int size;

        void maxHeapify(int *arr, int index, int size);

    public:
        Heap(int capac);
        void maxHeapify(int index);
        void insert(int value);
        void siftUp(int index);
        int removeMax();
        void heapSort(int *array, int n);
        int getMax() { return this->arr[1]; }
        void printHeap();
        int getSize() {return this->size; }
        bool isEmpty() { return (this->size == 0); }

};