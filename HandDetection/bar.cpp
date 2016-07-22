#include "bar.h"


#pragma comment(lib, "user32")
using namespace std;

static int oldCoutFing;
static Point coor;
static vector <Point> lines;
static Scalar color = Scalar(255, 0, 0); // default color red

button red, green, blue;

void bar::init()
{
	//init buttons
	
	red.color = Scalar(255, 0, 0);
	red.crd = Point(300, 0);
	red.height = 50;
	red.width = 50;

	green.color = Scalar(0, 255, 0);
	green.crd = Point(350, 0);
	green.height = 50;
	green.width = 50;

	blue.color = Scalar(0, 0, 255);
	blue.crd = Point(400, 0);
	blue.height = 50;
	blue.width = 50;
	//
}

void bar::check(vector <Point> fingerTips)
{
	coor = fingerTips[1];
	int coutFing = fingerTips.size();
	//cout << "fingerTips: " << coutFing << endl;//for debug only
	if ((coutFing == 3) && (oldCoutFing == 2))
	{
		Click();
	}
	if ((coutFing == 3) && (oldCoutFing == 3))
	{
		Down();
	}
	if ((coutFing == 2) && (oldCoutFing == 3))
	{
		Up();
	}
	oldCoutFing = coutFing;
}

void bar::draw(MyImage *m)
{
	//draw buttons
	rectangle(m->src, Rect(red.crd.x, red.crd.y, red.width, red.height), red.color, CV_FILLED);
	rectangle(m->src, Rect(green.crd.x, green.crd.y, green.width, green.height), green.color, CV_FILLED);
	rectangle(m->src, Rect(blue.crd.x, blue.crd.y, blue.width, blue.height), blue.color, CV_FILLED);

	if(lines.size()>=2)
	for (int i = 1; i < lines.size()-1; i++)
	{
		line(m->src, lines[i], lines[i - 1], color);
	}
	
}

void bar::Click()
{
	cout << "Dubug: Click" << endl;
}

void bar::Down()
{
	cout << "Dubug: Down" << endl;
	if (!red.OnClick(coor) && !green.OnClick(coor) && !blue.OnClick(coor))
	{
		lines.push_back(coor);
	}
}
void bar::Up()
{
	if (red.OnClick(coor))
	{
		color = Scalar(255, 0, 0);
	}
	else if (green.OnClick(coor))
	{
		color = Scalar(0, 255, 0);
	}
	else if (blue.OnClick(coor))
	{
		color = Scalar(0, 0, 255);
	}

	cout << "Dubug: Up" << endl;
}


bool button::OnClick(Point coor)
{
	if ((coor.x >= crd.x) && (coor.x <= crd.x + height) && (coor.y >= crd.y) && (coor.y <= crd.y + width))
	{
		return true;
	}
	else
	{
		return false;
	}
}
