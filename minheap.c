/**
 *                        Min-Heaps
 * 
 * Please make sure you read the blurb in `minheap.h` to ensure you understand 
 * how we are implementing min-heaps here and what assumptions / requirements 
 * are being made.
 * 
 * (c) Mustafa Quraish, Summer 2026
 */

#include "minheap.h"

/**
 * Allocate a new min heap of the given size.
 * 
 * TODO: 
 *  Allocate memory for the `MinHeap` object, and the 2 arrays inside it.
 *  `numItems` should initially be set to 0, and all the indices should be
 *   set to -1 to start with (since we don't have anything in the heap).
 */
MinHeap *newMinHeap(int size) {

  return NULL; // Allocate and return heap.
}

/**
 * Swaps elements at indices `a` and `b` in the heap, and also updates their
 * indices. Assumes that `a` and `b` are valid.
 * 
 * NOTE: This is already implemented for you, no need to change anything.
 */
void swap(MinHeap *heap, int a, int b) {
  // Swap the elements
  HeapElement temp = heap->arr[a];
  heap->arr[a] = heap->arr[b];
  heap->arr[b] = temp;

  // Refresh their indices
  heap->indices[heap->arr[a].val] = a;
  heap->indices[heap->arr[b].val] = b;
}

/**
 * Add a value with the given priority into the heap.
 * 
 * TODO: Complete this function, and make sure all the relevant data is updated
 *      correctly, including the `indices` array if you move elements around. 
 *      Make sure the heap property is not violated. 
 * 
 * You may assume the value does not already exist in the heap, and there is
 * enough space in the heap for it.
 */
void heapPush(MinHeap *heap, int val, double priority) {
  return; // Push value to heap before returning
}

/**
 * Extract and return the value from the heap with the minimum priority. Store
 *  the priority for this value in `*priority`. 
 * 
 * For example, if `10` was the value with the lowest priority of `1.0`, then
 *  you would have something that is equivalent to:
 *      
 *        *priority = 1.0;
 *        return 10;
 * 
 * TODO: Complete this function, and make sure all the relevant data is updated
 *      correctly, including the `indices` array if you move elements around. 
 *      Make sure the heap property is not violated. 
 * 
 * You may assume there is at least 1 value in the heap.
 */
int heapExtractMin(MinHeap *heap, double *priority) {
  *priority = 0.0;  // Set correct priority  
  return 0;         // Return correct value
}

/**
 * Decrease the priority of the given value (already in the heap) with the
 * new priority.
 * 
 * NOTE: You will find it helpful here to first get the index of the value
 *       in the heap from the `indices` array.
 * 
 * TODO: Complete this function, and make sure all the relevant data is updated
 *      correctly, including the `indices` array if you move elements around. 
 *      Make sure the heap property is not violated. 
 * 
 * You may assume the value is already in the heap, and the new priority is
 *  smaller than the old one (caller is responsible for ensuring this).
 */
void heapDecreasePriority(MinHeap *heap, int val, double priority) {
  return;   // Decrease priority before return
}

/**
 * Free the data for the heap. This won't be marked, but it is always good
 * practice to free up after yourself when using a language like C.
 */
void freeHeap(MinHeap *heap) {
  return;   // Free heap and it's arrays
}
