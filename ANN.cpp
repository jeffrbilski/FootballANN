// Author: Jeffrey Bilski
//
//implementation for ANN

#include "ANN.h"
#include <math.h>
#include <iostream>

//########################## ANN ##################################
//*****************************************************************
void ANN::ProcessOutputNeuron() {
//pre: hidden neurons have processed inputs
//post: result of hidden neurons is processed through output neurons
  vector<double> HiddenNeuronOutputs;

  for (unsigned int count = 0; count < myHiddenNeurons.size(); count++) {
  //pushes back the result of each hidden neuron into a vector
    HiddenNeuronOutputs.push_back(myHiddenNeurons[count].GetSummation());
  }
  myOutputNeuron.SetWeights(HiddenNeuronOutputs.size()); //sets the number of weights to HiddenNeuronOutputs.size()
  myOutputNeuron.CalcSummation(HiddenNeuronOutputs); //finds summation of HiddenNeuronOutputs
  myOutputNeuron.OutputSummation(); //outputs result
}
//*****************************************************************
void ANN::ProcessHiddenNeurons(TrainingEntry& dummyEntry) {
//pre: a single entry of input is grabbed from the set 
//purpose: processes the inputs through the hidden neurons
//post: result of hidden neurons is processed through output neurons
  vector<double> inputs;

  inputs.push_back(dummyEntry.getDown());
  inputs.push_back(dummyEntry.getYTG());

  for (unsigned int count = 0; count < myHiddenNeurons.size(); count++) {
  // sets the weights and finds the summation for each hidden neuron
    myHiddenNeurons[count].SetWeights(inputs.size());
    myHiddenNeurons[count].CalcSummation(inputs);
  }
}
//*****************************************************************
void ANN::FeedForwardANN (TrainingSet& mySet) {
//pre: a set of data entries is passed in. This will be the inputs for the hidden neurons.
//purpose: this function does the primary processing for the network.
//post: the processing of the input is complete and results are output.
  TrainingEntry dummyEntry;
  SetHiddenNeuronsNumber (3);
  
  for (int count = 0; count < mySet.GetNumberOfEntries(); count++) {
  // processes each entry through the neural network
    dummyEntry = mySet.GetEntry(count);	
    ProcessHiddenNeurons (dummyEntry);
  }
  ProcessOutputNeuron();
}
//*****************************************************************
void ANN::SetHiddenNeuronsNumber (int newNumber) {
//purpose: Changes the number of hidden neurons
//post: adjusts the size of the vector of hidden neurons. if the vector is empty, sets the the size.
  
  if (myHiddenNeurons.empty() == false) { //first checks if the hidden neuron vector is empty
    HiddenNeuron someHiddenNeuron;
    
    for (int count = 0; count < newNumber; count++) {
	myHiddenNeurons.push_back(someHiddenNeuron);
    }
  }
  //otherwise resizes
  else {
	myHiddenNeurons.resize (newNumber);
  }
}
//*****************************************************************
//########################## Neuron ##################################
//*****************************************************************
Neuron::Neuron() {
  summation = 0;
  activation = 0;
}
//*****************************************************************
void Neuron::SetWeights(int size) {
//pre: and integer size is passed in
//purpose: sets 'size' number of weights of 0.5
//post: weights.size() == size
  for (int count = 0; count < size; count++) {
    weights.push_back(0.5);
  }
}
//*****************************************************************
double Neuron::GetSummation() {
//post: value of summation is returned
   return summation;
}
//*****************************************************************
double Neuron::GetActivation() {
//post: value of activation is returned
  return activation;
}
//*****************************************************************
void Neuron::CalcSummation(vector<double>& inputs) {
//pre: a vector of double values is passed in
//purpose: finds the summation of the values in the vector inputs
//post: summation is calculated
  for (unsigned int count = 0; count < inputs.size(); count++) {
    summation+= inputs[count]*weights[count];
  }
}
//*****************************************************************
void Neuron::CalcActivation () {
//pre: there is a value for summation
//purpose: finds the activation of the summation
//post: activation is calculated
  activation = 1 / (1 + pow(E_VAL, summation));
}
//*****************************************************************
//########################## Output Neuron ##################################
//*****************************************************************
OutputNeuron::OutputNeuron () {
  summation = 0.0;
  activation = 0.0;
}
void OutputNeuron::OutputSummation() {
//purpose: outputs the value of summation to the screen
  std::cout << std::endl << "The result of the output neuron is " << summation << std::endl;
}
//*****************************************************************
//########################## Hidden Neuron ##################################
//*****************************************************************
HiddenNeuron::HiddenNeuron () {
  summation = 0.0;
  activation = 0.0;
}