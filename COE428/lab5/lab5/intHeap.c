#include <stdio.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
static int size = 0;
static int heap[100000000];

//prints the heap as xml
void printXML(int i) {
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (i < size) {
        printf("<node id=\"%d\">", heap[i]);
        printXML(left);
        printXML(right);
        printf("</node>");
    }
}



void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with root at given index
void heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // If left child is larger than root
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        // Recursively heapify the affected sub-tree
        heapify(largest);
    }
}

//builds max heap
void buildHeap() {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	
    if (size == 0)
        return -1;

    // Store the maximum value
    int root = heap[0];

    heap[0] = heap[size-1];
	heap[size-1] = 0;
    size--;
    heapify(0);

    return root;
}

/**
 * 
 *
 */
void addHeap(int object)//add object to heap
{
    heap[size] = object;
    size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  //A dummy return statement
}
