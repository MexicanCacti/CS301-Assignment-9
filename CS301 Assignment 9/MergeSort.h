#pragma once
#include <iostream>
#include <vector>

void Merge(std::vector<int>, int, int, int, int);
void MergeSort(std::vector<int>, int, int);

// two arrays, merge them together sorted
void Merge(std::vector<int> values, int leftFirst, int leftLast, int rightFirst, int rightLast) {
  std::vector<int>temp(values.size()); // temp array to store items in order
  int index = leftFirst;
  int saveFirst = leftFirst;
  
  // compare two arrays, inserting elements in order. Do this until one array runs out of elements to sort
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
    if (values[leftFirst] < values[rightFirst]) {
      temp[index] = values[leftFirst];
      leftFirst++;
    }
    else {
      temp[index] = values[rightFirst];
      rightFirst++;
    }
    index++;
  }
  
  // do this if ran out of elements from right list
  while (leftFirst <= leftLast) {
    temp[index] = values[leftFirst];
    leftFirst++;
    index++;
  }
  
  //do this if ran out of elements from left list
  while (rightFirst <= rightLast) {
    temp[index] = values[rightFirst];
    rightFirst++;
    index++;
  }
  
  // values now holds a sorted list
  values = temp;
  
}

// split array in half
void MergeSort(std::vector<int>values, int first, int last) {

  if (first < last) {
    int middle = (first + last) / 2;  // where to split list
    MergeSort(values,first , middle); // first half of list
    MergeSort(values,middle + 1, last); // second half of list
    Merge(values, first, middle, middle+1, last); // merge first & second halves
  }

}