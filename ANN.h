// Author: Jeffrey Bilski
//
//specification for ANN

#ifndef ANN_H
#define ANN_H

#include <vector>
#include "trainData.h"

const double E_VAL = 2.71828;
//*****************************neuron***********************************
class Neuron {
  
protected:
  double summation;
  double activation;
  double gradient;
  double error;
  vector<double> weights;
  
public:
  Neuron();
  //Setters
  void SetWeights(int);
  //Getters
  double GetSummation();
  double GetActivation();
  //Modifiers
  void CalcSummation(vector<double>&);
  void CalcActivation ();
  void CalcGradient();
  void CalcError();
  
};
//******************************output neuron*****************************
class OutputNeuron: public Neuron {

public:
  OutputNeuron();
  void OutputSummation();
};
//******************************hidden neuron*****************************
class HiddenNeuron: public Neuron {
public:
  HiddenNeuron();
};
//*******************the neural network specification*************************
class ANN {

protected:
  vector <HiddenNeuron> myHiddenNeurons;
  OutputNeuron myOutputNeuron;
  //Modifiers
  void ProcessOutputNeuron();
  void ProcessHiddenNeurons(TrainingEntry&);
  
public:
  //Modifiers
  void FeedForwardANN (TrainingSet&);
  //Setters
  void SetHiddenNeuronsNumber (int);
};

#endif