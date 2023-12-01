#pragma once
void Split(vector<int>&, int, int ,int&);
void Swap(int&, int&);
void QuickSort(vector<int>&, int, int);

void Split(vector<int>& values, int first, int last, int& splitPoint) {
  int splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;
  
  first++;
  do {
    onCorrectSide = true;
    while (onCorrectSide) {
      if (values[first] > splitVal) {
        onCorrectSide = false;
      }
      else {
        first++;
        onCorrectSide = (first <= last);
      }
    }
    onCorrectSide = (first <= last);
    while (onCorrectSide) {
      if (values[last] <= splitVal) {
        onCorrectSide = false;
      }
      else {
        last--;
        onCorrectSide = (first <= last);
      }
    }
    if (first < last) {
      Swap(values[first], values[last]);
      first++;
      last--;
    }
  } while(first <= last);
  
  
  splitPoint = last;
  Swap(values[saveFirst], values[splitPoint]);
}

void QuickSort(vector<int>& values, int first, int last) {
  if (first < last) {
    int splitPoint;
    Split(values, first, last, splitPoint);
    QuickSort(values, first, splitPoint - 1);
    QuickSort(values, splitPoint + 1, last);
  }
}

void Swap(int& item1, int& item2) {
  int tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}