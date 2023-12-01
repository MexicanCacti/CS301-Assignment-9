#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdlib> // for srand and rand
#include <ctime> // for clock( ), clock_t, time, and CLOCKS_PER_SEC
using namespace std;

// the .hs hold the implementations of each sorting algorithm.
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
void bubbleSort(vector<int>, ofstream&);

void quickSort(vector<int>, ofstream&);

void mergeSort(vector<int>, ofstream&);

void heapSort(vector<int>, ofstream&);

int main() {
  srand(time(0)); // random number gen
  
  ifstream fin;
  ofstream fout;
  string inFile, outFile, testLabel, command;
  int commands = 0;
  int n = 0;  // STARTING PROBLEM SIZE
  
  // prompt for file names
  cout << "Name of input file: ";
  getline(cin, inFile);
  cout << "\nName of output file: ";
  getline(cin, outFile);
  cout << endl;
  cout << "Enter name of test run; press return." << endl;
  cin >> testLabel;
  cout << "\nProblem size to test with: " << endl;
  cin >> n;

  fin.open(inFile.c_str());
  fout.open(outFile.c_str());
  fout << testLabel << endl;
  
  // create a data structure of size n
  vector<int>testStruct(n);
  for (int i = 0; i < n; i++) {
    testStruct[i] = rand();
  }

  fin >> command;
  while (fin.good() && command != "Quit")
  {
    if (command == "BubbleSort")
    {
      bubbleSort(testStruct, fout);
    }
    else if (command == "QuickSort")
    {
      quickSort(testStruct, fout);
    }
    else if (command == "MergeSort")
    {
      mergeSort(testStruct, fout);
    }
    else if (command == "HeapSort")
    {
      heapSort(testStruct, fout);
    }
    commands++;
    fin >> command;
  };
  
  cout << "Testing completed." << endl;
  fin.close();
  fout.close();
  return 0;
}


void bubbleSort(vector<int>test, ofstream& out) {
  double elapsedSeconds = 0;
  // start the timer and start sorting
  clock_t  startTime = clock();
  Bubble(test); // see BubbleSort.h for implementation of bubble sort
  clock_t endTime = clock();
  // stop timer, computer timing result
  elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  
  // report result
  out << "\nBUBBLE SORT OF SIZE " << test.size() << endl;
  out << "Time elapsed: " << elapsedSeconds << " seconds" << endl;
  cout << "Bubble Sort finished" << endl;
}

void quickSort(vector<int>test, ofstream& out) {
  double elapsedSeconds = 0;
  // start the timer and start sorting
  clock_t  startTime = clock();
  QuickSort(test, 0, test.size() - 1);
  clock_t endTime = clock();
  // stop timer, computer timing result
  elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

  // report result
  out << "\nQUICK SORT OF SIZE " << test.size() << endl;
  out << "Time elapsed: " << elapsedSeconds << " seconds" << endl;
  cout << "Quick Sort finished" << endl;
}

void mergeSort(vector<int>test, ofstream& out) {
  double elapsedSeconds = 0;
  // start the timer and start sorting
  clock_t  startTime = clock();
  MergeSort(test, 0, test.size() - 1);
  clock_t endTime = clock();
  // stop timer, computer timing result
  elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

  // report result
  out << "\nMERGE SORT OF SIZE " << test.size() << endl;
  out << "Time elapsed: " << elapsedSeconds << " seconds" << endl;
  cout << "Merge Sort finished" << endl;
}

void heapSort(vector<int>test, ofstream& out) {
  double elapsedSeconds = 0;

  // start the timer and start sorting
  clock_t  startTime = clock();
  HeapSort(test, test.size());
  clock_t endTime = clock();
  // stop timer, computer timing result
  elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

  // report result
  out << "\nHEAP SORT OF SIZE " << test.size() << endl;
  out << "Time elapsed: " << elapsedSeconds << " seconds" << endl;
  cout << "Heap Sort finished" << endl;
}
