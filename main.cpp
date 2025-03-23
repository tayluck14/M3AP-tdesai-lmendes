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
#include <fstream>
using namespace std;

void stabilityTest();

int main() {
    // Get your vector of custom data type objects ready
    vector<Fighter> fighters;
    getDataFromFile(fighters);

    //Data directory is included, but the program will automatically generate the data files
    ofstream bubbleOutputFile("../data/BubbleData.txt", ios::out);
    ofstream mergeOutputFile("../data/MergeData.txt", ios::out);
    ofstream heapOutputFile("../data/HeapData.txt", ios::out);
    ofstream quickOutputFile("../data/QuickData.txt", ios::out);
    if (!bubbleOutputFile.is_open() || !mergeOutputFile.is_open() || !heapOutputFile.is_open() || !quickOutputFile.is_open()) {
        cerr << "ERROR: Unable to open one or more files" << endl;
    }

    bubbleOutputFile << "Fighters,Reads,Allocations" << endl;
    mergeOutputFile << "Fighters,Reads,Allocations" << endl;
    heapOutputFile << "Fighters,Reads,Allocations" << endl;
    quickOutputFile << "Fighters,Reads,Allocations" << endl;




    // loop through vector sizes from 1000 to 100 in decrements of 100
    for (int size = 1000; size >= 100; size -= 100) {
        vector<Fighter> fightersSubset(fighters.begin(), fighters.begin() + size);

        //sort the vector in four different ways (bubble, ?, heap, ?)
        //record the number of reads and allocations for each sort
        unsigned long bubbleReads = 0, bubbleAllocations = 0;
        bubbleSort(fightersSubset, bubbleReads, bubbleAllocations);
        bubbleOutputFile << size << "," << bubbleReads << "," << bubbleAllocations << endl;

        unsigned long mergeReads = 0, mergeAllocations = 0;
        mergeSort(fightersSubset, mergeReads, mergeAllocations);
        mergeOutputFile << size << "," << mergeReads << "," << mergeAllocations << endl;

        unsigned long heapReads = 0, heapAllocations = 0;
        heapSort(fightersSubset, heapReads, heapAllocations);
        heapOutputFile << size << "," << heapReads << "," << heapAllocations << endl;

        unsigned long quickReads = 0, quickAllocations = 0;
        quickSortUnstable(fightersSubset, quickReads, quickAllocations);
        quickOutputFile << size << "," << quickReads << "," << quickAllocations << endl;

        cout << "_________________________________________________________" << endl;
    }


    stabilityTest();

    //Close files
    bubbleOutputFile.close();
    heapOutputFile.close();
    mergeOutputFile.close();
    quickOutputFile.close();

    system("py ../generate_graphs.py");

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