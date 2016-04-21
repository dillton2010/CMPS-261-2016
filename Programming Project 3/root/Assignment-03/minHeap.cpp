/* 
 * File:   minHeap.cpp
 * Author: Matthew Williamson
 * Clid:   mcw4553
 * Assignment: Assignment 3
 * Due Date: 3/27/2013 10:00 p.m.
 * Statement of Authenticity: I certify that this assignment is entirely my own work
 * 
 * Created on March 20, 2013, 1:42 PM
 */

#include "minHeap.h"

template <class Comparable>
minHeap <Comparable> ::minHeap(int capacity)
{
  heapArray.resize(capacity + 5); //initialize the heap to a size a little larger than the initial size
  exchanges = 0;
  comparisons = 0; //since heaps aren't dynamic we must accomadate
  currentSize = 0; //initialize the current size to 1 since we will not be using 0 as our index
} //if currentSize is set to 0 the arithmetic will be incorrect because all operations
//are performed on the index of nodes

template <typename Comparable>
Comparable minHeap<Comparable>::deleteMin() //delete the root of the minheap
{

  Comparable minItem = heapArray[1]; //the first item is the root item
  heapArray[1] = heapArray[currentSize--]; //decrement the heap
  //        exchanges++;
  percolateDown(1); //readjust the heap to accomadate for the item removed

  return minItem; //return the min item
}

template <class Comparable>
void minHeap<Comparable>::percolateDown(int hole) //traverse the heap until we reach the node we are looking for
{ //this  will maintain the
  int child; //heap priority keeping all nodes in the proper position
  Comparable tmp = heapArray[hole];

  for (; hole * 2 <= currentSize; hole = child)
  {
      comparisons++;
      child = hole * 2;
      if (child != currentSize && heapArray[child + 1] < heapArray[child])
      {
          comparisons++;
          child++;
      }
      
      if (heapArray[child] < tmp)
      {
          comparisons++;
          heapArray[hole] = heapArray[child];
          exchanges++;
      }
      else
          break;
  }
  heapArray[ hole ] = tmp;
}


template <class Comparable>
void minHeap <Comparable> ::insert(Comparable item)
{
  hole = ++currentSize;
  for (; hole > 1 && item < heapArray[parent(hole)]; hole = parent(hole))
  {
      //      comparisons++;
      heapArray[hole] = heapArray[parent(hole)];
      //      exchanges++;

  }
  heapArray[hole] = item;


}

template <class Comparable>
int minHeap<Comparable>::parent(int hole) //floor of hole/2
{
  return hole / 2;
}

template <class Comparable>
int minHeap<Comparable>::getComparisons()//returning comparisons to the callee
{
  return comparisons;
}
                                        //since comparisons and exchanges are performed
template <class Comparable>             //inside the class we will use these methods to 
int minHeap<Comparable>::getExchanges() //keep track of them
{                                       //returning exchanges to the callee
                                        //
  return exchanges;
}

template <class Comparable>
bool minHeap<Comparable>::isEmpty() //if nothing was inserted or if the minheap reaches it's initial size
{ //the heap is empty
  if (currentSize == 1) //this is the initial size
      return true;
  else
      return false;
}
template class minHeap<int>;
