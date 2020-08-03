// Created by Addison Thomas
// 2 Aug 2020
// LinkedListProblem.cpp


/*
This code is intended to solve the question given by The Paranoids in a technical interview:

Given a linked list and a max size create two methods, get() and input(). Each node in the linked list contains an int array,
which uses the max value as the size of the array. input() takes in an index and a value, and places the value into the linked
list at the index where index 0 is the first element of the int array of the first node. If the node has been filled, create a
new node and split the old node in half. Get() takes the index of the item to be returned and the array that it will iterate
through and returns the element at that index.


example: MAX=3  [1,4] -> [2,3] -> [5,6]
get(2) = 2
input(2,7) = [1,4] -> [7,2,3] -> [5,6]
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//Max size of each nodes int array.
static int MAX_SIZE = 3;

vector<vector<int> > split(vector<int> arr) {
  //For easy access on the return, we will return both the left and the right.
  vector<vector<int> > ret;
  vector<int> left;
  vector<int> right;

  for(int i = 0; i<arr.size(); i++) {
    if(i<arr.size()/2) {
      left.push_back(arr.at(i));
    } else {
      right.push_back(arr.at(i));
    }
  }
  ret.push_back(left);
  ret.push_back(right);

  return ret;
}



int get(vector<vector<int> > v, int index) {
  int position = 0;

  for(int i = 0; i<v.size();i++) {
    if(position+v.at(i).size() > index) {
      int tmp = index-position;
      return v.at(i).at(tmp);
    } else {
      position += v.at(i).size();
    }
  }
  return -1;
}


int input(vector<vector<int> >* v, int index, int value) {
  int position = 0;
  //Using the position means this method can run in O(n) time.
  //Amortized worst case is if the array has to be split, in which case O(n^2) because of recursion.
  for(int i = 0;i<v->size();i++) {
    if(position + v->at(i).size() < index) {
      position += v->at(i).size();
    } else {
      int tmp = index-position;
      if(v->at(i).size() >= MAX_SIZE) {
        vector<vector<int> > splitvector = split(v->at(i));
        v->insert(v->begin()+i, splitvector.at(0));
        v->insert(v->begin()+(i+1), splitvector.at(1));
        return input(v,index,value);
      } else {
        v->at(i).insert(v->at(i).begin() + tmp, value);
        return 1;
      }
    }
  }

  return -1;

}

void printArr(vector<vector<int> > vec) {
  for(int i = 0; i<vec.size(); i++) {
    printf("{ ");
    for(int j = 0; j<vec.at(i).size(); j++) {
      printf("%i ", vec.at(i).at(j));
    }
    printf("}, ");
  }
  printf("\n");
}


int main() {

  vector<vector<int> > vec = {{1,2,3}, {4,5,6}, {7,8}};
  printArr(vec);
  bool quit = false;

  printf("Commands are 'g', 'i', 'p', and 'q' for (g)et, (i)nput, (p)rint and (q)uit:\n");

  while(!quit) {
    char in[] = "";
    cin >> in;
    //Each of the commands that can be run
    char getcom[] = "g";
    char incom[] = "i";
    char quitcom[] = "q";
    char printcom[] = "p";

    //While not an efficent method of fielding inputs,
    // the number of inputs for this practice problem are low, justifying the if/elseif as opposed to a data structure
    //GET COMMAND
    if(strcmp(in, getcom) == 0) {
      printf("Input an index to get: \n");
      int index;
      cin >> index;

      int val = get(vec, index);

      if(val == -1) {
        printf("Index does not exist. Exiting... \n");
        exit(0);
      } else {
        printf("Value: %i\n", val);
      }
      //INPUT COMMAND
    } else if(strcmp(in, incom) == 0){
      printf("Input an index to input at: \n");
      int index;
      cin >> index;

      printf("Input a value to place at index %i\n",index);
      int inputval;
      cin >> inputval;

      input(&vec, index, inputval);
      printArr(vec);

      //QUIT COMMAND
    } else if(strcmp(in, quitcom) == 0) {
      printf("Quit command recieved. Exiting...\n");
      quit = true;
      exit(0);

      //PRINT COMMAND
    } else if(strcmp(in,printcom) == 0) {
      printArr(vec);
    }
    else {
      printf("Command not recognized. Quiting... \n");
      exit(0);
    }
    printf("Command: \n");
  }

  return 0;
}
