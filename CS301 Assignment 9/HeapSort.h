#pragma once

void ReheapDown(vector<int>&, int, int);
void HeapSort(vector<int>&, int);
void Swap(int&, int&);

void ReheapDown(vector<int>& values, int root, int bottom) {
  int maxChild;
  int rightChild;
  int leftChild;
  
  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  
  if (leftChild <= bottom) {
    if (leftChild == bottom) {
      maxChild = leftChild;
    }
    else {
      if (values[leftChild] <= values[rightChild]) {
        maxChild = rightChild;
      }
      else {
        maxChild = leftChild;
      }
    }
    if (values[root] < values[maxChild]) {
      Swap(values[root], values[maxChild]);
      ReheapDown(values, maxChild, bottom);
    }
  }
}


void HeapSort(vector<int>& values, int numValues) {
  int index;
  
  // convert array to heap
  for (index = numValues / 2 - 1; index >= 0; index--) {
    ReheapDown(values,index,numValues - 1);
  }
  
  // sort array
  for (index = numValues - 1; index >= 1; index--) {
    Swap(values[0], values[index]);
    ReheapDown(values, 0, index- 1);
  }
}