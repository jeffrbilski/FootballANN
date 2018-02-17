// Author: Jeffrey Bilski
//
//client for ANN

#include <iostream>
#include <vector>
#include <string>
#include "ANN.h"
#include "trainData.h"

using namespace std;

int main () {
  
  TrainingSet mySet; //the training set
  string fileName; //name of the file getting the data from
  string userChoice;
  ANN myANN; //the artificial neural network

  cout << endl << "Enter the name of the file you wish to use: ";
  cin >> fileName;
  
  mySet.openFile(fileName);
  mySet.inputDescription();
  mySet.inputEntry();
  
  cout << endl << "Show the normalized data? (y/n): ";
  cin >> userChoice;
  
  if (userChoice == "y" || userChoice == "Y")
	mySet.outputEntries(); //outputs the normalized data from the file
  
  myANN.FeedForwardANN(mySet);
}