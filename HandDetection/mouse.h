#ifndef _mouse_
#define _mouse_ 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "windows.h"
#include "myImage.hpp"

static class mouse
{
public:
	static void Cpos();
	static Point get_mean(Point pos, int num);
	static Point mean;
	static void key(Point pos, MyImage *m);
	static void mouse::get_resolution(MyImage m);
	Rect border;
	static int mouse::get_dist(Point a, Point b);
	static void mouse::old_get_angle(Point a, Point b, Point c);
	static void mouse::get_angle(Point a, Point b, Point c);
	/*static int meanNum;
	static vector <Point> tmpMean;
	static Point pos;
	static bool stat;*/
};
#endif