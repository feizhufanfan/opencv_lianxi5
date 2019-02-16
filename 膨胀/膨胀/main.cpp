#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
void Call_back(int ,void*);
int element_size = 3;
Mat src1, dst;
/******************
膨胀的像素操作为中心像素点被像素值大的取代

**********************************/
int main(int argc, char** argv) {
	src1 = imread("Image1.jpg");
	if (!src1.data) {
		cout << "文件不存在！";
		return -1;
	}
	namedWindow("src1",CV_WINDOW_AUTOSIZE);
	imshow("src1",src1);
	createTrackbar("value","src1",&element_size,100,Call_back);
	Call_back(0,0);
	waitKey(0);

	return 0;
}
void Call_back(int ,void*) {
	Mat Element_struct;
	Element_struct=getStructuringElement(MORPH_RECT,Size(element_size * 2 + 1, element_size * 2 + 1),Point(-1,-1));
	dilate(src1,dst,Element_struct,Point(-1,-1));
	
	imshow("dst",dst);
}