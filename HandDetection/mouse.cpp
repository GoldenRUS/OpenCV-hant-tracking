#include "mouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "myImage.hpp"
#include "windows.h"
#include <cmath>
#include <math.h>

#pragma comment(lib, "user32")

using namespace std;
 Point mouse::mean;
 int  k = 20;
 int resXk;
 int resYk;
 int resolutionX;
 int resolutionY;
 int meanNum;
 vector <Point> tmpMean;
 Point pos;
 bool state=true;
 void mouse::get_angle(Point a, Point b, Point c) 
 {
	 double alpha = acos(((double)mouse::get_dist(c, a) + (double)mouse::get_dist(c, b)- (double)mouse::get_dist(a, b))/(2 * (double)mouse::get_dist(c, a) * (double)mouse::get_dist(c, b)));
	 cout << alpha << endl;
 }

 void mouse::old_get_angle(Point a, Point b, Point c)
 {
	 Point d = Point(a.x, c.y);
	 Point e = Point(b.x, c.y);
	 double alf = (double)mouse::get_dist(a, d) / (double)mouse::get_dist(a, c);
	 double bet = (double)mouse::get_dist(e, d) / (double)mouse::get_dist(b, c);
	 cout << "alpha:" << asin(alf) << " beta:" << asin(bet) << endl;
 }

 int mouse::get_dist(Point a, Point b)
 {
	 int Xa = a.x;
	 int Xb = b.x;
	 int Ya = a.y;
	 int Yb = b.y;
	 return sqrt(pow((Xb-Xa), 2)+pow((Yb-Ya), 2));
 }
 void mouse::get_resolution(MyImage m)
 {
	 resolutionX = GetSystemMetrics(SM_CXSCREEN);
	 resolutionY = GetSystemMetrics(SM_CYSCREEN);
	 resXk = resolutionX / m.src.cols;
	 resYk = resolutionY / m.src.rows;
	 cout << "screen resolution " << resolutionX << "x" << resolutionY << "cam resolution "<< m.src.cols << "x" << m.src.rows << endl;

 }
 void mouse::key(Point pos, MyImage *m)
 {
	 Rect border;
	 int x = 150;
	 int y = 150;
	 int _x = m->src.cols;
	 int _y = m->src.rows;
	 int w = _x-x*2;
	 int h = _y-y*2;
	 border.x = x;
	 border.y = y;
	 border.height = h;
	 border.width = w;
	 rectangle(m->src, border, Scalar(0, 255, 0), 2);
	 if (pos.x < x)
	 {
		 keybd_event('A', 0, 0, 0);
		 keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	 }
	 if (pos.x > x+w)
	 {
		 keybd_event('D', 0, 0, 0);
		 keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	 }
	 if (pos.y < y)
	 {
		 keybd_event('W', 0, 0, 0);
		 keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
	 }
	 if (pos.y > y+h)
	 {
		 keybd_event('S', 0, 0, 0);
		 keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
	 }
 }
Point mouse::get_mean(Point pos, int num)
{
	if (state) {
		tmpMean.clear();
		tmpMean.push_back(pos);
		meanNum = num;
		state = false;
	}
	else if (tmpMean.size() < meanNum) {
		tmpMean.push_back(pos);
	}
	else {
		state = true;
		Point tmp;
		for(int i=0; i < meanNum; i++)
		{
			tmp.x += tmpMean[i].x;
			tmp.y += tmpMean[i].y;
		}
		pos.x = tmp.x / meanNum;
		pos.y = tmp.y / meanNum;
	}
	return pos;
}
void mouse::Cpos()
{
	SetCursorPos(pos.x, pos.y);
}