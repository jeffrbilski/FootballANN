// Author: Jeffrey Bilski
//
// implementation for classes TrainginSet and TrainingEntry

#include "trainData.h"
#include <iostream>
#include <vector>

//*********************************************TrainingSet***************************************************************
TrainingSet::TrainingSet(){
	gameDescription = "";
	fileName = "";
}

void TrainingSet::openFile (string inputfileName) {
    fileName = inputfileName;//stores the filename as a protected string
    inputFile.open(fileName.c_str());
}

void TrainingSet::closeFile () {
    inputFile.close();
}

void TrainingSet::inputDescription () {
    getline (inputFile, gameDescription);
}

void TrainingSet::inputEntry () {
    int fileDown, fileYTG;
    string fileTarget;
    TrainingEntry dummyEntry;
   
    for (int count = 0; !inputFile.eof(); count++) {
      //loops through each line of the file until the end or maximum number of entries has been reached
      inputFile >> fileDown >> fileYTG >> fileTarget;
      dummyEntry.normalizeDown(fileDown);
      dummyEntry.normalizeYTG(fileYTG);
      dummyEntry.normalizeTarget(fileTarget);
      entries.push_back(dummyEntry);
      
      numberOfEntries = count;//store the number of entries (incase it's less than the max)
    }
}

void TrainingSet::outputEntries () {
  std::cout << gameDescription << std::endl;
  
  for (int count = 0; count<entries.size(); count++) {
    std::cout << entries[count].getDown() << " " << entries[count].getYTG() << " " << entries[count].getTarget() << std::endl; 
  }
}

TrainingEntry TrainingSet::GetEntry(int position) {
  return entries[position];
}

int TrainingSet::GetNumberOfEntries() {
  return entries.size();
}
//***********************************************TrainingEntry***************************************************************
TrainingEntry::TrainingEntry() {
	down = 0;
	ytg = 0;
	target = "";
	normalizedDown = 0;
	normalizedYTG = 0;
	normalizedTarget = 0;
}

void TrainingEntry::normalizeDown (int unnormalizedDown) {
  down = unnormalizedDown;
  normalizedDown = unnormalizedDown /4.0;
 
  if (normalizedDown >= 1)
      normalizedDown = .99;
}

void TrainingEntry::normalizeYTG (int unnormalizedYTG) {
  ytg = unnormalizedYTG;
  normalizedYTG = unnormalizedYTG/100.0;
}

void TrainingEntry::normalizeTarget (string unnormalizedTarget) {
  target = unnormalizedTarget;
  if (unnormalizedTarget == "Run" || unnormalizedTarget == "run") {
	normalizedTarget = 0;
  }
  else if (unnormalizedTarget == "Pass" || unnormalizedTarget == "pass") {
	normalizedTarget = 1;
  }
}

double TrainingEntry::getDown () {
  return normalizedDown;
}

double TrainingEntry::getYTG () {
  return normalizedYTG;
}

double TrainingEntry::getTarget () {
  return normalizedTarget;
}
