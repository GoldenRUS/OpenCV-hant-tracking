#ifndef _bar_
#define _bar_ 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "windows.h"
#include "myImage.hpp"
#include "handGesture.hpp"
static class bar
{
public:
	static void check(vector <Point> fingerTips);
	static void draw(MyImage *m);
	static void init();
private:
	static void Click();
	static void Down();
	static void Up();
    
};
class button
{
public:
	Point crd;
	int height, width;
	Scalar color;
	bool OnClick(Point coor);
};
#endif