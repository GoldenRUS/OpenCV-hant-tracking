#ifndef _neuron_
#define _neuron_ 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "windows.h"
#include <vector>
using namespace std;
static class neuron
{
public:
	int tips, memb;
	string name;
	int mas;//вес нейрона
	vector <int> memTips;
	vector <int> memMemb;//память нейрона
	void loadMem(string neuname);//загружает память нейрона
	void comp();//расчитывает вес нейрона
	void save();//сохраняет новый опыт


};
#endif