#include <iostream>
#include <vector>
using namespace std;

template <typename T> void merge (vector<T> &data, int firstToSort, int j, int lastToSort) {
   int mergedSize, mergePos, leftPos , rightPos;

   mergePos= 0;
   mergedSize = lastToSort -firstToSort + 1;
   leftPos = firstToSort;                               
   rightPos = j + 1;
   vector<T> mergedNumbers(mergedSize);                           

   while (leftPos <= j && rightPos <= lastToSort) {
      if (data.at(leftPos) < data.at(rightPos)) {
         mergedNumbers.at(mergePos) = data.at(leftPos);
         ++leftPos;
      }
      else {
         mergedNumbers.at(mergePos) = data.at(rightPos);
         ++rightPos;   
      }
      ++mergePos;
   }
   
   while (leftPos <= j) {
      mergedNumbers.at(mergePos) = data.at(leftPos);
      ++leftPos;
      ++mergePos;
   }

   while (rightPos <= lastToSort) {
      mergedNumbers.at(mergePos) = data.at(rightPos);
      ++rightPos;
      ++mergePos;  
   }

   for (mergePos = 0; mergePos < mergedSize ; ++mergePos) {
      data.at( firstToSort+ mergePos )= mergedNumbers.at(mergePos);
   }
   mergedNumbers.clear();

}

template <typename T> void mergeSort(std::vector<T>& data,  unsigned int firstToSort , unsigned int lastToSort) {
   int j;
   
   if (firstToSort < lastToSort) {
      j = (firstToSort + lastToSort) / 2;  
      mergeSort(data, firstToSort, j);
      mergeSort(data, j + 1, lastToSort);
      merge(data, firstToSort, j, lastToSort);
   }
}


