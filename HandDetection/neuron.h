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
	int mas;//��� �������
	vector <int> memTips;
	vector <int> memMemb;//������ �������
	void loadMem(string neuname);//��������� ������ �������
	void comp();//����������� ��� �������
	void save();//��������� ����� ����


};
#endif