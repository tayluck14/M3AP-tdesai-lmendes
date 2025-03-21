#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int numPasses = 0, i; //size of numpasses*2
    allocations += 2*sizeof(int);
    Comparable temp; //allocate size of comparable
    allocations += sizeof(Comparable);
    bool haveSwapped = true;
    allocations += sizeof(bool);
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
                reads += 4; // count reads from if statement and variable allocations
                // Update haveSwapped
                haveSwapped = true;
            }
            reads += 2; //count reads from false if statement
        }
        // Update numPasses
        ++numPasses;

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return vec;
}

#endif
