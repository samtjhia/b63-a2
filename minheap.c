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
MinHeap *newMinHeap(int size)
{
  MinHeap *min_heap = malloc(sizeof(MinHeap));

  if (min_heap == NULL)
  {
    printf("Memory allocation failed");
    return NULL;
  }

  min_heap->numItems = 0;
  min_heap->maxSize = size;
  min_heap->arr = malloc(size * sizeof(HeapElement));
  min_heap->indices = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++)
  {
    min_heap->indices[i] = -1;
  }

  return min_heap;
}

/**
 * Swaps elements at indices `a` and `b` in the heap, and also updates their
 * indices. Assumes that `a` and `b` are valid.
 *
 * NOTE: This is already implemented for you, no need to change anything.
 */
void swap(MinHeap *heap, int a, int b)
{
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
void heapPush(MinHeap *heap, int val, double priority)
{

  HeapElement new_elem;
  new_elem.val = val;
  new_elem.priority = priority;
  heap->arr[heap->numItems] = new_elem;
  heap->indices[val] = heap->numItems;
  heap->numItems++;

  int i = heap->numItems - 1;
  int p_idx = (i - 1) / 2;
  while (i > 0 && heap->arr[i].priority < heap->arr[p_idx].priority)
  {
    swap(heap, i, p_idx);
    i = p_idx;
    p_idx = (i - 1) / 2;
  }
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
int heapExtractMin(MinHeap *heap, double *priority)
{
  int root_val = heap->arr[0].val;
  double root_prio = heap->arr[0].priority;

  swap(heap, heap->numItems - 1, 0);
  heap->indices[root_val] = -1;
  heap->numItems--;

  int i = 0;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;
  while (left_child < heap->numItems)
  {
    if (right_child >= heap->numItems)
    {
      if (heap->arr[i].priority > heap->arr[left_child].priority)
      {
        swap(heap, i, left_child);
        i = left_child;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
      }
      else
      {
        break;
      }
    }
    else if (heap->arr[i].priority > heap->arr[left_child].priority ||
             heap->arr[i].priority > heap->arr[right_child].priority)
    {
      if (heap->arr[left_child].priority < heap->arr[right_child].priority)
      {
        swap(heap, i, left_child);
        i = left_child;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
      }
      else
      {
        swap(heap, i, right_child);
        i = right_child;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
      }
    }
    else
    {
      break;
    }
  }
  *priority = root_prio; // Set correct priority
  return root_val;       // Return correct value
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
void heapDecreasePriority(MinHeap *heap, int val, double priority)
{
  if (heap->indices[val] == -1){
    return;
  }
  int i = heap->indices[val];
  heap->arr[i].priority = priority;

  int p_idx = (i - 1) / 2;
  while (i > 0 && heap->arr[i].priority < heap->arr[p_idx].priority)
  {
    swap(heap, i, p_idx);
    i = p_idx;
    p_idx = (i - 1) / 2;
  }
}

/**
 * Free the data for the heap. This won't be marked, but it is always good
 * practice to free up after yourself when using a language like C.
 */
void freeHeap(MinHeap *heap)
{
  if (heap == NULL){return;}

  free(heap->arr);
  free(heap->indices);
  free(heap);
}
