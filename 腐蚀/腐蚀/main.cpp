#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
Mat src, dst;
int Element_size = 3;
void Call_back(int ,void*);
/**************
图像腐蚀操作：
中心像素点的值被周围的低像素值覆盖

****************************/
int main(int argc, char** argv) {
	src = imread("Image1.jpg");
	if (!src.data) {
		cout << "文件为空！";
		return -1;
	}
	namedWindow("src",CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	createTrackbar("value","src",&Element_size,100,Call_back);
	Call_back(0,0);
	waitKey(0);


	return 0;
}
void Call_back(int, void*) {
	Mat Element = getStructuringElement(MORPH_RECT,Size(Element_size*2+1,Element_size*2+1),Point(-1,-1));
	erode(src,dst,Element,Point(-1,-1),1);
	imshow("dst",dst);
}