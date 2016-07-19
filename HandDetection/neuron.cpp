#include "neuron.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "windows.h"
#include <cmath>
#include <math.h>

#pragma comment(lib, "user32")

using namespace std;

void neuron::loadMem(string neuname)
{
	ifstream neufile(neuname);
	if (neufile.is_open())
	{
		string tmp;
		getline(neufile, tmp);
	}
	else cout << "error open file " << neuname << endl;
	neufile.close;
}