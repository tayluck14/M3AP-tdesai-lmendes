#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include "Fighter.h"
#include <iomanip>
using namespace std;

void stabilityTest();

int main() {
    // Get your vector of custom data type objects ready
    vector<Fighter> fighters;
    getDataFromFile(fighters);
    // loop through vector sizes from 1000 to 100 in decrements of 100
    for (int size = 1000; size >= 100; size -= 100) {
        vector<Fighter> fightersSubset(fighters.begin(), fighters.begin() + size);

        //sort the vector in four different ways (bubble, ?, heap, ?)
        //record the number of reads and allocations for each sort
        unsigned long bubbleReads = 0, bubbleAllocations = 0;
        bubbleSort(fightersSubset, bubbleReads, bubbleAllocations);
        cout << "Bubble Sort (" << size << " Fighters): Reads = " << bubbleReads << ", Allocations = " << bubbleAllocations << endl;

        unsigned long mergeReads = 0, mergeAllocations = 0;
        mergeSort(fightersSubset, mergeReads, mergeAllocations);
        cout << "Merge Sort (" << size << " Fighters): Reads = " << mergeReads << ", Allocations = " << mergeAllocations << endl;

        unsigned long heapReads = 0, heapAllocations = 0;
        heapSort(fightersSubset, heapReads, heapAllocations);
        cout << "Heap Sort (" << size << " Fighters): Reads = " << heapReads << ", Allocations = " << heapAllocations << endl;

        unsigned long quickReads = 0, quickAllocations = 0;
        quickSortUnstable(fightersSubset, quickReads, quickAllocations);
        cout << "Quick Sort (" << size << " Fighters): Reads = " << quickReads << ", Allocations = " << quickAllocations << endl;

        cout << "_________________________________________________________" << endl;
    }


    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    // add other stable algorithm here
    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    // add other unstable algorithm here

    cout << endl << "Quick Sort" << endl;
    people.sortAndPrint(quickSortUnstable<contact>);
}