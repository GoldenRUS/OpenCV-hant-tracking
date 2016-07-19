#ifndef _NeuroNet_
#define _NeuroNet_ 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "windows.h"
#include "myImage.hpp"
#include "handGesture.hpp"
static class NeuroNet
{
public:
	static void NeuroNet::getHand(MyImage m, HandGesture hg);
	static void NeuroNet::teaching(char* name, Mat img);
	struct NeuronLay1
	{
		Mat input;
		float Wj;
		int output;
		string name;
	};
	static void NeuroNet::analize(Mat mem);
private:
	static int NeuroNet::neuron(NeuroNet::NeuronLay1 in, Mat data);
};
#endif