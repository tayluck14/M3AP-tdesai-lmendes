#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex, Comparable& partition, int& i, int& largerElementIndex, Comparable& temp, unsigned long& reads, unsigned long& allocations) {
    allocations+= 2* sizeof(int);
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    partition = vec[startIndex];
    reads++;

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    largerElementIndex = startIndex+1;
    for (i = startIndex+1; i <= endIndex; ++i) {
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i];
            vec[i] = vec[largerElementIndex];
            reads += 2;
            vec[largerElementIndex] = temp;
            // Update largerElementIndex
            ++largerElementIndex;
        }
    }
    // Swap the partition element into place
    if (startIndex != largerElementIndex-1) {
        temp = vec[startIndex];
        vec[startIndex] = vec[largerElementIndex - 1];
        vec[largerElementIndex - 1] = temp;
        reads += 2;
    }

    // Uncomment this line if you want to see each iteration
    //printVec(vec);

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex-2, partition, i, largerElementIndex, temp,reads, allocations);
    quickSortUnstableRec(vec, largerElementIndex, endIndex, partition, i, largerElementIndex, temp,reads, allocations);
}

template<typename Comparable>
vector<Comparable> quickSortUnstable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    Comparable partition, temp;
    allocations += 2 * sizeof(Comparable);
    int i, largerElementIndex;
    allocations += 2 * sizeof(int);
    quickSortUnstableRec(vec, 0, vec.size() - 1, partition, i, largerElementIndex, temp, reads, allocations);
    return vec;
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, unsigned long& reads, unsigned long& allocations) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    reads++;

    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    allocations += sizeof(int);
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            reads++;
        } else if (vec[i] > partition) {
            larger.push_back(vec[i]);
            reads++;
        } else {
            equal.push_back(vec[i]);
            reads++;
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, allocations);
    quickSortStableRec(larger, reads, allocations);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            reads++;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            reads++;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            reads++;
        }
    }

    // Uncomment this line if you want to see each iteration
    //printVec(vec);
}

template<typename Comparable>
vector<Comparable> quickSortStable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    quickSortStableRec(vec, reads, allocations);
    return vec;
}

#endif
