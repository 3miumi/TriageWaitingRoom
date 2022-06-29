// Ziwen Ming
// PatientPriorityQueue.h
// May 31, 2022
// Implement a PatientPriorityQueue class used to add Patient object to a vector. It
// has functions of priority Queue.

#ifndef P3_PATIENTPRIORITYQUEUE_H
#define P3_PATIENTPRIORITYQUEUE_H
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Patient.h"
#include <cassert>
#include <iostream>
#include <iomanip>
using namespace std;

class PatientPriorityQueue{
public:
    PatientPriorityQueue();
    // Input: the row and col size for creating the RatingsList
    // constructor that takes in the size of the 2d Dynamic array
    // precondition: row > 0, col > 0
    // postcondition:create an array with given column and row, numElement is assigned to 0

    void add (Patient &);
    // Input: the Patient object
    // precondition: none
    // postconditon: the Patient will be added to this PriorityQueue.

    Patient peek () const;
    // Returns a patient that has the highest priority
    // precondition: none
    // postcondition: none


    Patient remove ();
    // Returns and removes a patient that has the highest priority
    // precondition: none
    // postcondition: none

    int size() const;
    // Return the size of the vector
    // precondition: none
    // postcondition: none

    string to_string();
    // returns string representation of the list
    // precondition: none
    // postcondition: returns string

private:
    vector<Patient> patientHeap;//a vector of Patient data type
    int heapSize;

    bool empty() const;
    // returns if the vector is empty or not
    // precondition: none
    // postcondition: returns true/false

    void siftUp(int);
    // Input: index where the patient element in vector need to be sift up
    // precondition: none
    // postcondition: patient will be compared with parent for the priority
    // if patient has high priority, it will be swap with parent.


    void siftDown(int);
    // Input: index where the patient element in vector need to be sift down
    // precondition: none
    // postcondition: patient will be compared with the child leaf that has high priority
    // if patient has high priority, it will be swap with child leaf.


    int getParent(int) const;
    // Input: index where the patient element in vector
    // precondition: none
    // postcondition: return the input's parent index in vector


    int getLeftChild(int) const;
    // Input: index where the patient element in vector
    // precondition: none
    // postcondition: return the input's left child index in vector

    int getRightChild(int) const;
    // Input: index where the patient element in vector
    // precondition: none
    // postcondition: return the input's right child index in vector
};



PatientPriorityQueue :: PatientPriorityQueue(){
    heapSize = 0;
}
void PatientPriorityQueue:: add (Patient &patient){
    patientHeap.push_back(patient);
    heapSize ++;
    siftUp(heapSize - 1);

}
bool PatientPriorityQueue::empty() const{
    return heapSize==0;
}
Patient PatientPriorityQueue::peek() const {
    assert(!empty());
    return patientHeap[0];
}
Patient PatientPriorityQueue:: remove (){
    assert(!empty());
    Patient temp;
    temp = patientHeap[0];
    patientHeap[0] = patientHeap[--heapSize];
    patientHeap.pop_back();
    if (heapSize > 1)
        siftDown(0);
    return temp;

}

int PatientPriorityQueue :: size() const{
    return heapSize;
}



void PatientPriorityQueue::siftUp(int index) {
    int parentIdx;
    Patient temp;
    if (index != 0) {
        parentIdx = getParent(index);
        if (patientHeap[index] < patientHeap[parentIdx]) {
            temp = patientHeap[parentIdx];
            patientHeap[parentIdx] = patientHeap[index];
            patientHeap[index] = temp;
            siftUp(parentIdx);
        }
    }
}

int PatientPriorityQueue::getParent(int index) const {
    return (index - 1) / 2;
}

void PatientPriorityQueue::siftDown(int index) {
    int leftIdx, rightIdx, minInx;
    Patient temp;
    leftIdx = getLeftChild(index);
    rightIdx = getRightChild(index);

    // find minIdx
    if (rightIdx >= heapSize) {
        if (leftIdx >= heapSize)
            return;
        else
            minInx = leftIdx;
    } else {
        if (patientHeap[leftIdx] < patientHeap[rightIdx])
            minInx = leftIdx;
        else
            minInx = rightIdx;
    }

    // swap?
    if (patientHeap[minInx] < patientHeap[index]) {
        temp = patientHeap[minInx];
        patientHeap[minInx] = patientHeap[index];
        patientHeap[index] = temp;
        siftDown(minInx);
    }
}
string PatientPriorityQueue :: to_string(){
    stringstream ss;
    for(int i=0; i < size(); i++){
        ss <<setw(7)<< patientHeap[i].getArrivalOrder() << setw(16) <<patientHeap[i].getPriCode()<<"       "<<patientHeap[i].getName() << endl;
    }
    return ss.str();
}

int PatientPriorityQueue::getLeftChild(int index) const {
    return 2 * index + 1;
}

int PatientPriorityQueue::getRightChild(int index) const {
    return 2 * index + 2;
}
#endif //P3_PATIENTPRIORITYQUEUE_H