// Created by Addison Thomas
// 2 Aug 2020
// LinkedListProblem.cpp


/*
This code is intended to solve the question given by The Paranoids in a technical interview:

Given a list of numbers and a certain number of picks, determine what the maximum sum of the numbers would be if you can only pick from the front or the back.

Example: 1, 2, 10000, 5, 8
Picks: 3
Max: 10000 + 5 + 8
*/

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int MAX_VALUE = 256;

int max_finder(int values[], int picks, int size) {
  int sum = 0;


  int tmppicks = picks;

  //we don't need to iterate over the picks if all the numbers will be used.
  if(picks >= size) {
    for(int i = 0; i<size; i++){
      sum += values[i];
    }
    return sum;
  }

  //initialize the sum with the first round of picks.
  for(int i = 0; i < picks;i++) {
    sum += values[i];
  }

  //use tmpsum as the comparetor for sum.
  int tmpsum = sum;

  //iterate, subtracting the last of the picks from the sum and adding a new pick to the sum.
  for(int i = 0; i<picks; i++) {
    int remainder = picks - tmppicks;
    tmpsum = (tmpsum - values[tmppicks-1]) + values[(size - remainder)-1];

    if(tmpsum > sum) {
      sum = tmpsum;
    }

    tmppicks--;
  }

  return sum;
}



int main() {
  int values[] = {1,2,3,4,5};
  int size = sizeof(values)/sizeof(int);
  int picks = 3;

  printf("ARRAY: ");
  for(int i = 0; i<size; i++) {
    printf("%i ", values[i]);
  }
  printf("\n");
  int max = max_finder(values, picks, size);
  printf("Max value of array is: %i\n",  max);
}
