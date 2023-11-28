#pragma once
#include <iostream>
#include <vector>

void Bubble(std::vector<int>);


void Bubble(std::vector<int>values) {
  for (int i = 0; i < values.size(); i++) {
    for (int j = i + 1; j < values.size(); j++) {
      if (values[i] > values[j]) {
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
      }
    }
  }
}