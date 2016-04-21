/* 
 * File:   minHeap.h
 * Author: Matthew Williamson
 * Clid:   mcw4553
 * Assignment: Assignment 3
 * Due Date: 3/27/2013 10:00 p.m.
 * Statement of Authenticity: I certify that this assignment is entirely my own work
 * 
 * Created on March 20, 2013, 1:42 PM
 */

#ifndef MINHEAP_H
#define	MINHEAP_H

#include <vector>
#include <iostream>

using namespace std;

//Description: minHeap will create and use a minHeap as specified by the main driver
//Base Case: heap is empty


template<class Comparable>
class minHeap {
public:
    
    
//Prototype: minHeap(int capacity)
//Description: Creates an empty heap and will initialize the capacity to a user specified value from main driver
//Precondition: none
//Postcondition:   currentSize = 1; heapArray resized to capacity + 5;
//Cost Analysis: Big-O (1)
//Visibility: Public
    minHeap(int capacity);
    
//Prototype: bool isEmpty()
//Description: if heap is empty returns true else false
//Precondition: heap must exist
//Postcondition: if currentSize = 1 return true; else return false
//Cost Analysis: Big-O(1)
//Visibility: Public    
    bool isEmpty( );  

//Prototype: void insert( Comparable item)
//Description: insert element into the heap maintaining heap priority
//Precondition: heap must exist
//Postcondition: item is inserted into the heap maintaining the heap order;  currentSize is incremented by 1
//Cost Analysis: Big-O(log n)
//Visibility: Public    
    void insert( Comparable item );  
    
//Prototype: Comparable deleteMin()
//Description: The root of the heap is returned to the main program
//Precondition: heap must exist
//Postcondition: The root of the heap has been removed and returned to the main program. The currentSize is decremented and heap is adjusted to accommodate for the removal.
//Cost Analysis: Big-O(log n)
//Visibility: Public    
    Comparable deleteMin( );
    
//Prototype: getComparisons()
//Description: returns number of comparisons
//Precondition: heap must exist
//Postcondition: returns comparisons performed
//Cost Analysis: Big-O(N)
//Visibility: Public   
    int getComparisons();
    
//Prototype: getExchanges ()
//Description: returns number of exchanges
//Precondition: heap must exist
//Postcondition: returns exchanges performed
//Cost Analysis: Big-O(N)
//Visibility: Public       
    int getExchanges();
    

private:
//Prototype: int parent (int hole)
//Description: Returns index’s parent
//Precondition: Index must have a parent and be a child
//Postcondition: returns floor(index/2)
//Cost Analysis: Big-O(1)
//Visibility: Private    
    int parent(int hole);

//Prototype: percolateDown (int hole)
//Description: hole moves down the tree while maintaining heap priority
//Precondition: heap must not be empty
//Postcondition: heap order is maintained
//Cost Analysis: Big-O (log N)
//Visibility: Private    
    void percolateDown(int hole);
    

    
//Name: heapArray
//Description: vector pointer that holds the array for the minHeap
//Type: <Comparable>
//Range: Any value that is acceptable for the <Comparable> type 
    vector<Comparable> heapArray;
    
//Name: heapSize
//Description: heapSize is total size of the heap
//Type: integer
//Range: all non-negative integer values    
    int heapSize;
    
//Name: currentSize
//Description: currentSize is the current size of the heap (changes as elements are inserted into heap)
//Type: integer
//Range: all non-negative integer values
    
    int currentSize;
//Name: hole
//Description: holds the index in which an element is to be moved
//Type: integer
//Range: all non-negative integer values    
    int hole;
    
//Name: comparisons
//Description: number of comparisons done on minHeap
//Type: integer
//Range: all non-negative integer values    
    
    int comparisons;
    
//Name: exchanges
//Description: number of exchanges being done on minHeap
//Type: integer
//Range: all non-negative integer values    
    int exchanges;

};



#endif	/* MINHEAP_H */

