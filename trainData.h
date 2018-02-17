// Author: Jeffrey Bilski
//
// specification for the classes TrainingSet and TrainingEntry

#ifndef TRAINDATA_H
#define TRAINDATA_H

#include <string>
#include <fstream>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class TrainingEntry {
        public:
                TrainingEntry();
                void normalizeDown(int);
                void normalizeYTG(int);
                void normalizeTarget(string);
                double getDown();
                double getYTG();
                double getTarget();
        protected:
                int down;
                int ytg;
                string target;
                double normalizedDown;
                double normalizedYTG;
                double normalizedTarget;
};

//***************************************************************************
class TrainingSet {
	protected:
		string gameDescription;
		string fileName;
		ifstream inputFile;
		int numberOfEntries;
		vector<TrainingEntry> entries;
	public:
		TrainingSet();
		void openFile(string fileName);
		void closeFile();
		void inputDescription();
		void inputEntry();
		void outputEntries();
		TrainingEntry GetEntry(int position);
		int GetNumberOfEntries();
};

#endif
