#include "NeuroNet.h"


#pragma comment(lib, "user32")
using namespace std;


void NeuroNet::getHand(MyImage m, HandGesture hg)
{
	IplImage *img = cvCreateImage(cvSize(m.bw.cols, m.bw.rows), 8, 3);;
	IplImage copy = m.bw;
	img = &copy;
	cvSetImageROI(img, hg.bRect);
	IplImage *sub_img = cvCreateImage(cvSize(100, 100),
		img->depth,
		img->nChannels);
	cvResize(img, sub_img, NULL);
	cvResetImageROI(img);
	MyImage out;
	out.src = Mat(sub_img);


	//if (cv::waitKey(60) == char('t')) NeuroNet::teaching("w.bmp", out.src);
	if (cv::waitKey(60) == char('a')) NeuroNet::analize(out.src);
	imshow("black", out.src);
}

void NeuroNet::teaching(char* name, Mat img)
{
	cout << "teach----" << endl;
	IplImage* _mem = cvLoadImage(name);
	Mat mem = Mat(_mem);
	//Mat mem = imread(name + ".bmp");
	
	//imwrite(name + ".bmp", mem);
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{ 
			if ((mem.at<uchar>(x, y) < 255) && (img.at<uchar>(x, y) == 255)) 
			{
				mem.at<uchar>(x, y)++;
			}
		}
	}
	
	IplImage tmp = mem;
	_mem = &tmp;
	cvShowImage("mem", _mem);
	cvSaveImage(name, _mem);
}

void NeuroNet::analize(Mat mem)
{
	IplImage* _mem;

	_mem = cvLoadImage("five.bmp");
	NeuroNet::NeuronLay1 five;
	five.input = Mat(_mem);
	five.name = "name";
	five.Wj = 1;
	five.output = neuron(five, mem);

	_mem = cvLoadImage("ok.bmp");
	NeuroNet::NeuronLay1 ok;
	ok.input = Mat(_mem);
	ok.name = "ok";
	ok.Wj = 1;
	ok.output = neuron(ok, mem);

	_mem = cvLoadImage("v.bmp");
	NeuroNet::NeuronLay1 v;
	v.input = Mat(_mem);
	v.name = "v";
	v.Wj = 1;
	v.output = neuron(v, mem);

	_mem = cvLoadImage("w.bmp");
	NeuroNet::NeuronLay1 w;
	w.input = Mat(_mem);
	w.name = "w";
	w.Wj = 1;
	w.output = neuron(w, mem);

	_mem = cvLoadImage("o.bmp");
	NeuroNet::NeuronLay1 o;
	o.input = Mat(_mem);
	o.name = "o";
	o.Wj = 1;
	o.output = neuron(o, mem);
	
	cout << "mass of 'five'=" << five.output << ", mass of 'ok'=" << ok.output << ", mass of 'v'=" << v.output << ", mass of 'w'=" << w.output << ", mass of 'o'=" << o.output << endl;
	if ((five.output > ok.output) && (five.output > v.output) && (five.output > w.output) && (five.output > o.output)) cout << "I think, you show me 'five'" << endl;
	if ((ok.output > five.output) && (ok.output > v.output) && (ok.output > w.output) && (ok.output > o.output)) cout << "I think, you show me 'ok'" << endl;
	if ((v.output > ok.output) && (v.output > five.output) && (v.output > w.output) && (v.output > o.output)) cout << "I think, you show me 'v'" << endl;
	if ((w.output > ok.output) && (w.output > v.output) && (w.output > five.output) && (w.output > o.output)) cout << "I think, you show me 'w'" << endl;
	if ((o.output > ok.output) && (o.output > v.output) && (o.output > five.output) && (o.output > w.output)) cout << "I think, you show me 'o'" << endl;

}
int NeuroNet::neuron(NeuroNet::NeuronLay1 in, Mat data)
{
	for (int x = 0; x < data.cols; x++)
	{
		for (int y = 0; y < data.rows; y++)
		{
			if ((in.input.at<uchar>(x, y) > 0) && (data.at<uchar>(x, y) > 0)) in.output+= data.at<uchar>(x, y);
			//if ((in.input.at<uchar>(x, y) > 0) && (data.at<uchar>(x, y) = 0)) in.output-=9;
			//if ((in.input.at<uchar>(x, y) = 0) && (data.at<uchar>(x, y) = 0)) in.output++;//Под вопросом. Если черный.
		}
	}
	return in.output*in.Wj;
}